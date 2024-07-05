/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:59:06 by brguicho          #+#    #+#             */
/*   Updated: 2024/07/05 23:59:35 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_is_eating(t_thread *thread)
{
	size_t	time;

	pthread_mutex_lock(&thread->data->print);
	time = ft_get_current_time() - thread->data->start_time;
	printf("%ld %d is eating\n", time, thread->id);
	pthread_mutex_unlock(&thread->data->print);
}

void	ft_print_is_thinking(t_thread *thread)
{
	size_t	time;

	pthread_mutex_lock(&thread->data->print);
	time = ft_get_current_time() - thread->data->start_time;
	printf("%ld %d is thinking\n", time, thread->id);
	pthread_mutex_unlock(&thread->data->print);
}

void	ft_print_is_sleeping(t_thread *thread)
{
	size_t	time;

	pthread_mutex_lock(&thread->data->print);
	time = ft_get_current_time() - thread->data->start_time;
	printf("%ld %d is sleeping\n", time, thread->id);
	pthread_mutex_unlock(&thread->data->print);
}

void	ft_print_has_taken_fork_r(t_thread *thread)
{
	size_t	time;

	pthread_mutex_lock(&thread->data->print);
	time = ft_get_current_time() - thread->data->start_time;
	printf("%ld %d has taken right fork\n", time, thread->id);
	pthread_mutex_unlock(&thread->data->print);
}

void	ft_print_has_taken_fork_l(t_thread *thread)
{
	size_t	time;

	pthread_mutex_lock(&thread->data->print);
	time = ft_get_current_time() - thread->data->start_time;
	printf("%ld %d has taken left fork\n", time, thread->id);
	pthread_mutex_unlock(&thread->data->print);
}
