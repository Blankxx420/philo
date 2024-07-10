/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:10:28 by brguicho          #+#    #+#             */
/*   Updated: 2024/07/10 23:01:54 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	ft_atoll(char *str)
{
	long long int	i;
	long long int	sum;
	long long int	sign;

	sum = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] - '0' >= 0 && str[i] - '0' <= 9))
	{
		sum = sum * 10 + str[i] - '0';
		i++;
	}
	return (sum * sign);
}

void	ft_bzero(void *dest, unsigned int size)
{
	unsigned int	index;

	index = 0;
	while (index < size)
	{
		*((unsigned char *) dest + index) = '\0';
		index++;
	}
}

void	*ft_calloc(size_t elementcount, size_t elementcize)
{
	void	*tab;

	if (elementcize == 0 || elementcount == 0)
	{
		tab = malloc(1);
		if (tab == NULL)
			return (NULL);
		ft_bzero(tab, 1);
		return (tab);
	}
	if (elementcount * elementcize / elementcize != elementcount)
		return (NULL);
	tab = malloc(elementcize * elementcount);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, elementcount * elementcize);
	return (tab);
}

void	free_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->info->nbr_philo)
	{
		if (data->philo[i].own_fork)
		{
			pthread_mutex_destroy(data->philo[i].own_fork);
			free(data->philo[i].own_fork);
		}
		i++;
	}
	pthread_mutex_destroy(&data->dead);
	pthread_mutex_destroy(&data->meal);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->ready);
	free(data->philo);
}

void	free_all(t_data *data)
{
	if (data->philo)
		free_philos(data);
	if (data->info)
		free(data->info);
	if (data)
		free(data);
}
