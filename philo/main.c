/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:25:59 by brguicho          #+#    #+#             */
/*   Updated: 2024/04/25 00:05:02 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc > 4 && argc < 7)
	{
		if (ft_philo(argc, argv))
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
