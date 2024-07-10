/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:41:51 by brguicho          #+#    #+#             */
/*   Updated: 2024/07/10 14:39:08 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->info->nbr_philo)
	{
		data->philo[i].own_fork = ft_calloc(1, sizeof(pthread_mutex_t));
		if (!data->philo[i].own_fork)
			return (1);
		if (pthread_mutex_init(data->philo[i].own_fork, NULL))
			return (1);
		if (i + 1 < data->info->nbr_philo)
			data->philo[i + 1].left_fork = data->philo[i].own_fork;
		data->philo[i].nbr_meals_eaten = 0;
		data->philo[i].id = i + 1;
		data->philo[i].data = data;
		data->philo[i].last_timestamp = 0;
		i++;
	}
	if (data->info->nbr_philo != 1)
		data->philo[0].left_fork = data->philo[i - 1].own_fork;
	return (0);
}

int	start_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->info->nbr_philo)
	{
		if (pthread_create(&data->philo[i].thread,
			NULL, &ft_routine, &data->philo[i]))
			return (1);
		i++;
	}
	pthread_mutex_lock(&data->ready);
	data->flag_rdy = 1;
	pthread_mutex_unlock(&data->ready);
	monitoring(data);
	i = 0;
	while (i < data->info->nbr_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}

int	set_info(t_info *info, int argc, char **argv)
{
	info->nbr_philo = (int)ft_atoll(argv[1]);
	info->time_to_die = ft_atoll(argv[2]);
	info->time_to_eat = ft_atoll(argv[3]);
	info->time_to_sleep = ft_atoll(argv[4]);
	info->nbr_time_to_eat = -1;
	if (argc == 6)
		info->nbr_time_to_eat = (int)ft_atoll(argv[5]);
	if (!check_info(info, argc))
		return(1);
	return (0);
}

void	init(t_info *info)
{
	info->nbr_philo = 0;
	info->time_to_die = 0;
	info->time_to_eat = 0;
	info->time_to_sleep = 0;
	info->nbr_time_to_eat = 0;
}

int	init_data(t_data *data)
{
	if (pthread_mutex_init(&data->meal, NULL)
		|| pthread_mutex_init(&data->dead, NULL)
		|| pthread_mutex_init(&data->ready, NULL)
		|| pthread_mutex_init(&data->print, NULL))
		return (1);
	data->flag_rdy = 0;
	data->flag_dead = 0;
	data->philo = ft_calloc(data->info->nbr_philo + 1, sizeof(t_thread));
	if (!data->philo)
		return (1);
	return (0);
}
