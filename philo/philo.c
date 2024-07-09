/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:34:37 by brguicho          #+#    #+#             */
/*   Updated: 2024/07/10 00:13:20 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	progam_init(t_data *data, int argc, char **argv)
{
	init(data->info);
	if (!argv_are_digits(argv))
		return (1);
	if(set_info(data->info, argc, argv))
		return (1);
	if (init_data(data))
		return (1);
	if (init_philo(data))
		return (1);
	return (0);
}

int	ft_philo(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	data->info = ft_calloc(1, sizeof(t_info));
	if (!data->info)
	{
		free_all(data);	
		return (1);
	}
	if (progam_init(data, argc, argv))
	{
		free_all(data);
		return (1);
	}
	if (start_thread(data))
	{
		free_all(data);
		return (1);	
	}
	free_all(data);
	return (0);
}
