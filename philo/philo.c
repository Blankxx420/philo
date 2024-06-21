/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:34:37 by brguicho          #+#    #+#             */
/*   Updated: 2024/06/18 09:26:41 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_dead_main(t_data *data)
{
	int i;

	i = 0;
	while (data->philo[i])
	{
		pthread_mutex_lock(&data->states);
		if (data->philo[i]->state == DEAD)
		{
			pthread_mutex_unlock(&data->states);
			return (1);
		}
		pthread_mutex_unlock(&data->states);
		i++;
		usleep(100);
	}
	return (0);
}

int	ft_philo(int argc, char **argv)
{
	t_data *data;

	data = ft_calloc(1 , sizeof(t_data));
	if (!data)
		return (1);
	data->info = ft_calloc(1, sizeof(t_info));
	if (!data->info)
		return (1);
	init(data->info);
	if (!argv_are_digits(argv))
		return (1);
	set_info(data->info, argc, argv);
	init_philo(data);
	start_thread(data);
	while(!check_dead_main(data))
		;
	return (0);
}
