/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:41:51 by brguicho          #+#    #+#             */
/*   Updated: 2024/07/05 13:55:45 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->info->nbr_philo)
	{
		data->philo[i].own_fork = ft_calloc(1, sizeof(pthread_mutex_t));
		if (!data->philo[i].own_fork)
		{
			free_all(data);
		}
		if (pthread_mutex_init(data->philo[i].own_fork, NULL))
		{
			free_all(data);
		}
		data->philo[i].state = START;
		data->philo[i].nbr_meals_eaten = 0;
		data->philo[i].id = i + 1;
		data->philo[i].data = data;
		data->philo[i].thread = 0;
		i++;
	}
}

void	start_thread(t_data *data)
{
	int i;

	data->philo[0].left_fork = data->philo[data->info->nbr_philo - 1].own_fork;
	i = 1;
	while (i < data->info->nbr_philo)
	{
		data->philo[i].left_fork = data->philo[i - 1].own_fork;
		pthread_create(&data->philo[i].thread, NULL, &ft_routine, &data->philo[i]);
		i++;
	}
	pthread_mutex_lock(&data->ready);
	data->flag_rdy = 1;
	pthread_mutex_unlock(&data->ready);
	
}

void	set_info(t_info *info, int argc, char **argv)
{
	info->nbr_philo = ft_atouli(argv[1]);
	info->time_to_die = ft_atouli(argv[2]);
	info->time_to_eat = ft_atouli(argv[3]);
	info->time_to_sleep = ft_atouli(argv[4]);
	info->nbr_time_to_eat = -1;
	if (argc == 6)
	{
		info->nbr_time_to_eat = ft_atouli(argv[5]);
		if (info->nbr_time_to_eat <= 0)
			return ;
	}
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
	if (pthread_mutex_init(&data->meal, NULL) || pthread_mutex_init(&data->states, NULL)
		|| pthread_mutex_init(&data->ready, NULL) || pthread_mutex_init(&data->main_state, NULL)
		|| pthread_mutex_init(&data->print, NULL))
	{
		free(data->info);
		free(data);
		return (1);
	}
	data->flag_rdy = 0;
	data->flag_dead = 0;
	data->philo = ft_calloc(data->info->nbr_philo + 1, sizeof(t_thread));
	if (!data->philo)
	{
		free(data->info);
		free(data);
		return (1);
	}
	return (0);
}
