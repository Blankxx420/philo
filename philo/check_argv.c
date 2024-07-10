/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:50:53 by brguicho          #+#    #+#             */
/*   Updated: 2024/07/10 11:00:35 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	argv_are_digits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if  (argv[i][0] == '-' && argv[i][0] == '+')
				j++;
			else if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_info(t_info *infos, int argc)
{
	if (infos->nbr_philo < 1 || infos->time_to_die < 1
		|| infos->time_to_eat < 1 || infos->time_to_sleep < 1)
		return (0);
	if ((argc == 6 && infos->nbr_time_to_eat < 0)
		|| (argc == 6 && infos->nbr_time_to_eat > INT_MAX))
		return (0);
	if (infos->nbr_philo > INT_MAX
		|| infos->time_to_die > INT_MAX
		|| infos->time_to_eat > INT_MAX
		|| infos->time_to_sleep > INT_MAX)
		return (0);
	return (1);
}