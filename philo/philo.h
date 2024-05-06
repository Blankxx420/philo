/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:28:12 by brguicho          #+#    #+#             */
/*   Updated: 2024/05/06 10:50:45 by brguicho         ###   ########.fr       */
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

# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define WAITING 4
# define END 5
# define DEAD 6

typedef struct s_info
{
	int		nbr_philo;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int		nbr_time_to_eat;
}				t_info;

typedef struct s_thread
{
	pthread_mutex_t	fork;
	int				left_fork;
	int				nbr_meals_eaten;
	int				right_fork;
	pthread_t		thread;
	pthread_mutex_t	states;
	int				state;
}				t_thread;

typedef struct s_data
{
	t_info			info;
	t_thread		**philo;
}				t_data;

void	set_philo_var(t_thread *thread);
void	init_philo(t_data *data);
void	set_info(t_info *info, int argc, char **argv);
void	init(t_info *info);

int		ft_philo(int argc, char **argv);
void	*ft_routine(void *data);
int		argv_are_digits(char **argv);
size_t	ft_atouli(char *str);
size_t	ft_get_current_time(void);
int		ft_usleep(size_t milliseconds);
void	ft_bzero(void *dest, unsigned int size);
void	*ft_calloc(size_t elementcount, size_t elementcize);


void	*ft_print_is_eating(void *);
#endif