/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:06:48 by brguicho          #+#    #+#             */
/*   Updated: 2024/07/05 14:05:54 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_all_philo(t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->ready);
		if (data->flag_rdy == 1)
		{
			pthread_mutex_unlock(&data->ready);
			break;
		}
		pthread_mutex_unlock(&data->ready);
		usleep(100);
	}
}
int check_all_meal_eaten(t_data *data)
{
	int i;

	i = 0;
	if (data->info->nbr_time_to_eat == -1)
		return (1);
	while (i < data->info->nbr_philo)
	{
		pthread_mutex_lock(&data->meal);
		if (data->philo[i].nbr_meals_eaten < data->info->nbr_time_to_eat)
		{
			pthread_mutex_unlock(&data->meal);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&data->meal);
	pthread_mutex_lock(&data->dead);
	data->flag_dead = 1;
	pthread_mutex_unlock(&data->dead);
	return (0);
}