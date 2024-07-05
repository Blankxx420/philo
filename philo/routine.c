/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:06:19 by brguicho          #+#    #+#             */
/*   Updated: 2024/07/05 15:38:01 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int start_eating(t_thread *thread)
{
	pthread_mutex_lock(thread->own_fork);
	ft_print_has_taken_fork_r(thread);
	pthread_mutex_lock(thread->left_fork);
	ft_print_has_taken_fork_l(thread);
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
	return (0);
}

int start_sleeping(t_thread *thread)
{
	ft_print_is_sleeping(thread);
	usleep(thread->data->info->time_to_sleep * 1000);
	return (0);
}

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

void	*ft_routine(void *threads)
{
	t_thread	*thread;

	thread = (t_thread *)threads;
	wait_all_philo(thread->data);
	pthread_mutex_lock(&thread->data->print);
	thread->data->start_time = ft_get_current_time();
	pthread_mutex_unlock(&thread->data->print);
	if (thread->id % 2 == 0)
	{
		usleep(100);
	}
	while (!check_dead(thread))
	{
		if(check_dead)
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
