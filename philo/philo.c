/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:34:37 by brguicho          #+#    #+#             */
/*   Updated: 2024/05/02 09:47:12 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo(int argc, char **argv)
{
	t_data data;

	init(&data.info);
	if (!argv_are_digits(argv))
		return (1);
	set_info(&data.info, argc, argv);
	init_philo(&data);
	return (0);
}
