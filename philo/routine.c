/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:06:19 by brguicho          #+#    #+#             */
/*   Updated: 2024/06/25 15:00:54 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_philo_dead(t_thread *thread)
{
	int ret;

	ret = 0;
	if (thread->nbr_meals_eaten == thread->data->info->nbr_time_to_eat)
		return (ret);
	if (thread->last_timestamp > thread->data->info->time_to_die)
	{
		ret = 1;
		thread->state = DEAD;
	}
	return (ret);
}

int start_eating(t_thread *thread)
{
	pthread_mutex_lock(&thread->data->fork);
	thread->state = EATING;
	ft_print_is_eating(thread);
	usleep(thread->data->info->time_to_eat * 1000);
	if (is_philo_dead(thread))
	{
		pthread_mutex_unlock(&thread->data->fork);
		return (1);
	}
	thread->nbr_meals_eaten++;
	thread->right_fork = 1;
	*thread->left_fork = 1;
	pthread_mutex_unlock(&thread->data->fork);
	return (0);
}

int start_sleeping(t_thread *thread)
{
	pthread_mutex_lock(&thread->data->states);
	thread->state = SLEEPING;
	ft_print_is_sleeping(thread);
	usleep(thread->data->info->time_to_sleep * 1000);
	if (is_philo_dead(thread))
	{
		pthread_mutex_unlock(&thread->data->states);
		return (1);
	}
	pthread_mutex_unlock(&thread->data->states);
	return (0);
}

int can_philo_take_fork(t_thread *thread)
{
	pthread_mutex_lock(&thread->data->fork);
	if (thread->right_fork == 1 && *thread->left_fork == 1 && thread->state != WAITING)
	{
		thread->right_fork = 0;
		ft_print_has_taken_fork_r(thread);
		*thread->left_fork = 0;
		ft_print_has_taken_fork_l(thread);
		pthread_mutex_unlock(&thread->data->fork);
		return (1);
	}
	pthread_mutex_unlock(&thread->data->fork);
	return (0);
}

int	check_dead(t_thread *thread)
{
	pthread_mutex_lock(&thread->data->states);
	if (thread->state == DEAD)
	{
		pthread_mutex_unlock(&thread->data->states);
		return (1);
	}
	pthread_mutex_unlock(&thread->data->states);
	return (0);
}

void	*ft_routine(void *threads)
{
	t_thread	*thread;

	thread = (t_thread *)threads;

	wait_all_philo(thread->data);
	pthread_mutex_lock(&thread->data->fork);
	thread->data->start_time = ft_get_current_time();
	pthread_mutex_unlock(&thread->data->fork);
	if (thread->id % 2 == 0)
	{
		pthread_mutex_lock(&thread->data->states);
		thread->state = WAITING;
		pthread_mutex_unlock(&thread->data->states);
		usleep(100);
		pthread_mutex_lock(&thread->data->states);
		thread->state = START;
		pthread_mutex_unlock(&thread->data->states);
	}
	while (!check_dead(thread))
	{
		if (can_philo_take_fork(thread))
		{
			if(start_eating(thread))
				break;
			if (start_sleeping(thread))
				break;
		}
		usleep(100);
	}
	return ((void *)thread);
}
