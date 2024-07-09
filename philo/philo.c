/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:34:37 by brguicho          #+#    #+#             */
/*   Updated: 2024/07/09 18:17:02 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	data->info = ft_calloc(1, sizeof(t_info));
	if (!data->info)
		return (1);
	init(data->info);
	if (!argv_are_digits(argv))
		return (1);
	if(set_info(data->info, argc, argv))
		return (1);
	init_data(data);
	init_philo(data);
	start_thread(data);
	return (0);
}
