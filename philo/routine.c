/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:06:19 by brguicho          #+#    #+#             */
/*   Updated: 2024/06/17 10:57:09 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int can_philo_take_fork(t_thread *thread)
{
	pthread_mutex_lock(&thread->fork);
	if (thread->right_fork == 1 && *thread->left_fork == 1)
	{
		thread->right_fork = 0;
		ft_print_has_taken_fork_r(thread);
		*thread->left_fork = 0;
		ft_print_has_taken_fork_l(thread);
		pthread_mutex_unlock(&thread->fork);
		return (1);
	}
	pthread_mutex_unlock(&thread->fork);
	return (0);
}

int	check_dead(t_thread *thread)
{
	pthread_mutex_lock(&thread->states);
	if (thread->state == DEAD)
	{
		pthread_mutex_unlock(&thread->states);
		return (1);
	}
	pthread_mutex_unlock(&thread->states);
	return (0);
}

void	*ft_routine(void *threads)
{
	t_thread	*thread;

	thread = (t_thread *)threads;
	if (thread->id % 2 == 0)
	{
		pthread_mutex_lock(&thread->states);
		thread->state = WAITING;
		pthread_mutex_unlock(&thread->states);
		usleep(100);
	}
	while (!check_dead(thread))
	{
		can_philo_take_fork(thread);
		usleep(100);
	}
	return ((void *)thread);
}
