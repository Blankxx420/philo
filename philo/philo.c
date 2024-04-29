/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:34:37 by brguicho          #+#    #+#             */
/*   Updated: 2024/04/29 11:02:00 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_philo_var(t_thread thread)
{
	pthread_mutex_init(&thread.left_fork, NULL);
	pthread_mutex_init(&thread.right_fork, NULL);
	thread.thread = pthread_create(thread.thread)
}

static void	init_philo(t_data *data)
{
	int i;

	data->philo = ft_calloc(sizeof(t_thread *), data->info.nbr_philo);
	if (data->philo)
		return ;
	while (data->philo[i])
	{
		set_philo_var(data->philo[i]);
		i++;
	}
	
}
static void	set_info(t_info *info, int argc, char **argv)
{
	info->nbr_philo = ft_atouli(argv[1]);
	info->time_to_die = ft_atouli(argv[2]);
	info->time_to_eat = ft_atouli(argv[3]);
	info->time_to_sleep = ft_atouli(argv[4]);
	if (argc == 6)
		info->nbr_time_to_eat = ft_atouli(argv[5]);
}

static void	init(t_info *info)
{
	info->nbr_philo = 0;
	info->time_to_die = 0;
	info->time_to_eat = 0;
	info->time_to_sleep = 0;
	info->nbr_time_to_eat = 0;
}

int	ft_philo(int argc, char **argv)
{
	t_data data;

	init(&data.info);
	if (!argv_are_digits(argv))
		return (1);
	set_info(&data.info, argc, argv);
}
