/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:06:19 by brguicho          #+#    #+#             */
/*   Updated: 2024/07/01 10:32:21 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int start_eating(t_thread *thread)
{
	pthread_mutex_lock(&thread->data->fork[thread->id - 1]);
	pthread_mutex_lock(&thread->data->fork[thread->id]);
	ft_print_is_eating(thread);
	pthread_mutex_lock(&thread->data->meal);
	thread->nbr_meals_eaten++;
	pthread_mutex_unlock(&thread->data->meal);
	usleep(thread->data->info->time_to_eat * 1000);
	pthread_mutex_unlock(&thread->data->fork[thread->id - 1]);
	pthread_mutex_unlock(&thread->data->fork[thread->id]);
	return (0);
}

int start_sleeping(t_thread *thread)
{
	ft_print_is_sleeping(thread);
	pthread_mutex_lock(&thread->data->states);
	usleep(thread->data->info->time_to_sleep * 1000);
	pthread_mutex_unlock(&thread->data->states);
	return (0);
}

void can_philo_take_fork(t_thread *thread)
{
	pthread_mutex_lock(&thread->data->fork[thread->id - 1]);
	ft_print_has_taken_fork_r(thread);
	pthread_mutex_lock(&thread->data->fork[thread->id]);
	ft_print_has_taken_fork_l(thread);
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
	thread->data->start_time = ft_get_current_time();
	if (thread->id % 2 == 0)
	{
		usleep(100);
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
