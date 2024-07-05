/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:10:28 by brguicho          #+#    #+#             */
/*   Updated: 2024/07/05 23:12:36 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_atouli(char *str)
{
	size_t	i;
	size_t	sum;

	i = 0;
	sum = 0;
	while (str[i])
	{
		sum = sum * 10 + str[i] - '0';
		i++;
	}
	return (sum);
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
