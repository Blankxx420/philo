/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 06:56:53 by brguicho          #+#    #+#             */
/*   Updated: 2024/07/10 22:58:38 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	ft_get_current_time(void)
{
	struct timeval	time;
	size_t			timer;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	timer = time.tv_sec * 1000 + time.tv_usec / 1000;
	return ((long long int)timer);
}
