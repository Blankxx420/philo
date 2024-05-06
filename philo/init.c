/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:41:51 by brguicho          #+#    #+#             */
/*   Updated: 2024/05/06 10:10:39 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data)
{
	int i;

	data->philo = ft_calloc(data->info.nbr_philo, sizeof(t_thread *));
	if (!data->philo)
		return ;
	i = 0;
	while (i < data->info.nbr_philo)
	{
		data->philo[i] = ft_calloc(1, sizeof(t_thread));
		
		pthread_create(&data->philo[i]->thread, NULL, ft_routine, (void *)data);
		pthread_mutex_init(&data->philo[i]->left_fork, NULL);
		pthread_mutex_init(&data->philo[i]->right_fork, NULL);
		pthread_mutex_init(&data->philo[i]->state, NULL);
		pthread_mutex_init(&data->philo[i]->nbr_meals_eaten, NULL);
		i++;
	}
}

void	set_info(t_info *info, int argc, char **argv)
{
	info->nbr_philo = ft_atouli(argv[1]);
	info->time_to_die = ft_atouli(argv[2]);
	info->time_to_eat = ft_atouli(argv[3]);
	info->time_to_sleep = ft_atouli(argv[4]);
	if (argc == 6)
		info->nbr_time_to_eat = ft_atouli(argv[5]);
}

void	init(t_info *info)
{
	info->nbr_philo = 0;
	info->time_to_die = 0;
	info->time_to_eat = 0;
	info->time_to_sleep = 0;
	info->nbr_time_to_eat = 0;
}