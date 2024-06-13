/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:41:51 by brguicho          #+#    #+#             */
/*   Updated: 2024/06/13 14:05:32 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data)
{
	int	i;
	int	id;

	data->philo = ft_calloc(data->info.nbr_philo, sizeof(t_thread *));
	if (!data->philo)
		return ;
	i = 0;
	id = 1;
	while (i < data->info.nbr_philo)
	{
		data->philo[i] = ft_calloc(1, sizeof(t_thread));
		if (!data->philo[i])
		{
			free_philos(data->philo);
			return ;
		}
		pthread_mutex_init(&data->philo[i]->fork, NULL);
		pthread_mutex_init(&data->philo[i]->states, NULL);
		data->philo[i]->state = START;
		data->philo[i]->nbr_meals_eaten = 0;
		data->philo[i]->right_fork = 1;
		data->philo[i]->left_fork = &data->philo[data->info.nbr_philo - i]->right_fork;
		data->philo[i]->id = id;
		data->philo[i]->data = data;
		pthread_create(&data->philo[i]->thread, NULL,
			&ft_routine, (void *)data->philo[i]);
		i++;
		id++;
	}
}

void	set_info(t_info *info, int argc, char **argv)
{
	info->nbr_philo = ft_atouli(argv[1]);
	info->time_to_die = ft_atouli(argv[2]);
	info->time_to_eat = ft_atouli(argv[3]);
	info->time_to_sleep = ft_atouli(argv[4]);
	if (argc == 6)
	{
		info->nbr_time_to_eat = ft_atouli(argv[5]);
		if (info->nbr_time_to_eat <= 0)
			return ;
	}
	if (info->nbr_philo <= 0 || info->time_to_die < 200
		|| info->time_to_eat < 200 || info->time_to_eat < 200)
		return ;
}

void	init(t_info *info)
{
	info->nbr_philo = 0;
	info->time_to_die = 0;
	info->time_to_eat = 0;
	info->time_to_sleep = 0;
	info->nbr_time_to_eat = 0;
}
