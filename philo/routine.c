/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:06:19 by brguicho          #+#    #+#             */
/*   Updated: 2024/07/10 21:39:19 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_thread *thread)
{
	pthread_mutex_lock(&thread->data->dead);
	if (thread->data->flag_dead == 1)
	{
		pthread_mutex_unlock(&thread->data->dead);
		return (1);
	}
	pthread_mutex_unlock(&thread->data->dead);
	return (0);
}

void	start_eating(t_thread *thread)
{
	if (thread->data->info->nbr_philo == 1)
	{
		usleep(thread->data->info->time_to_die + 2);
		check_dead(thread);
		return ;
	}
	pthread_mutex_lock(thread->own_fork);
	ft_print_has_taken_fork(thread);
	pthread_mutex_lock(thread->left_fork);
	ft_print_has_taken_fork(thread);
	ft_print_is_eating(thread);
	pthread_mutex_lock(&thread->data->meal);
	thread->nbr_meals_eaten++;
	pthread_mutex_unlock(&thread->data->meal);
	usleep(thread->data->info->time_to_eat * 1000);
	pthread_mutex_lock(&thread->data->meal);
	thread->last_timestamp = ft_get_current_time(); 
	pthread_mutex_unlock(&thread->data->meal);
	pthread_mutex_unlock(thread->own_fork);
	pthread_mutex_unlock(thread->left_fork);
}

void	start_sleeping(t_thread *thread)
{
	if (thread->data->info->nbr_philo == 1)
		return ;
	if (thread->data->info->time_to_die <= thread->data->info->time_to_sleep)
		return ;
	ft_print_is_sleeping(thread);
	usleep(thread->data->info->time_to_sleep * 1000);
}

void	*ft_routine(void *threads)
{
	t_thread	*thread;

	thread = (t_thread *)threads;
	if (thread->id % 2 == 0)
	{
		usleep(100);
	}
	while (!check_dead(thread))
	{
		if (check_dead(thread))
			return (NULL);
		if (!check_dead(thread))
			start_eating(thread);
		start_sleeping(thread);
		if (!check_dead(thread))
			ft_print_is_thinking(thread);
		usleep(100);
	}
	return ((void *)thread);
}
