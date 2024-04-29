/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:28:12 by brguicho          #+#    #+#             */
/*   Updated: 2024/04/29 10:56:21 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

# define PENDING 10
# define RUNNING 64
# define STOP 16

typedef struct s_info
{
	int		nbr_philo;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int		nbr_time_to_eat;
}				t_info;

typedef struct s_data
{
	t_info			info;
	t_thread		**philo;
}				t_data;

typedef struct s_thread
{
	pthread_mutex_t	left_fork;
	int				nbr_meals_eaten;
	pthread_mutex_t	right_fork;
	pthread_t		thread;
	int				state;
}				t_thread;

int		ft_philo(int argc, char **argv);
int		argv_are_digits(char **argv);
size_t	ft_atouli(char *str);
size_t	ft_get_current_time(void);
int		ft_usleep(size_t milliseconds);

#endif