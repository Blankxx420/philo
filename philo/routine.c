/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:06:19 by brguicho          #+#    #+#             */
/*   Updated: 2024/06/21 10:31:02 by brguicho         ###   ########.fr       */
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
	ft_print_is_eating(thread);
	thread->state = EATING;
	ft_usleep(thread->data->info->time_to_eat);
	if (is_philo_dead(thread))
		pthread_mutex_unlock(&thread->data->fork);
		return (1);
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
	ft_usleep(thread->data->info->time_to_sleep);
	if (is_philo_dead(thread))
		pthread_mutex_unlock(&thread->data->states);
		return (1);
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
	if (thread->id % 2 == 0)
	{
		pthread_mutex_lock(&thread->data->states);
		thread->state = WAITING;
		pthread_mutex_unlock(&thread->data->states);
		usleep(100);
	}
	while (!check_dead(thread))
	{
		if (can_philo_take_fork(thread))
		{
			if(start_eating(thread));
				break;
			if (start_sleeping(thread))
				break;
		}
		usleep(100);
	}
	return ((void *)thread);
}
