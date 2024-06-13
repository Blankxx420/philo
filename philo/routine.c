/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:06:19 by brguicho          #+#    #+#             */
/*   Updated: 2024/06/13 14:27:26 by brguicho         ###   ########.fr       */
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

int	check_dead(t_data *data)
{
	int i;

	i = 0;
	while (data->philo[i])
	{
		if (data->philo[i]->state == DEAD)
			return (1);
		i++;
	}
	return (0);
}

void	*ft_routine(void *threads)
{
	t_thread	*thread;

	thread = (t_thread *)threads;
	while (!check_dead(thread->data))
	{
		if (thread->id % 2 == 0)
		{
			pthread_mutex_unlock(&thread->states);
			thread->state = WAITING;
			ft_usleep(10);
		}
		can_philo_take_fork(thread);
	}
	return ((void *)thread);
}
