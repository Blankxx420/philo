/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:06:48 by brguicho          #+#    #+#             */
/*   Updated: 2024/05/06 10:51:04 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_print_is_eating(t_thread *thread)
{
	size_t time;
	pthread_mutex_lock(&thread->states);
	thread->state = EATING;
	thread->nbr_meals_eaten++;
	pthread_mutex_unlock(&thread->states);
	time = ft_get_current_time();
	printf("%ld %d is eating\n", time, thread->thread);
	return ((void *)time);
}

// void	ft_print_is_thinking(t_thread *thread)
// {
// 	size_t time;
	
// 	time = ft_get_current_time();
// 	printf("%d %d is thinking\n", time, thread->thread);
// }

// void	ft_print_is_sleeping(t_thread *thread)
// {
// 	size_t time;
	
// 	time = ft_get_current_time();
// 	printf("%d %d is sleeping\n", time, thread->thread);
// }

// void	ft_print_has_taken_fork_r(t_thread *thread)
// {
// 	size_t time;
	
// 	time = ft_get_current_time();
// 	printf("%d %d has taken right fork\n", time, thread->thread);
// }

// void	ft_print_has_taken_fork_l(t_thread *thread)
// {
// 	size_t time;
	
// 	time = ft_get_current_time();
// 	printf("%d %d has taken left fork\n", time, thread->thread);
// }