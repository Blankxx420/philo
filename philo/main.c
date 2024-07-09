/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:25:59 by brguicho          #+#    #+#             */
/*   Updated: 2024/07/09 23:46:18 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (ft_philo(argc, argv) == 1)
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
