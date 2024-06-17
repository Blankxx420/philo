/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:28:12 by brguicho          #+#    #+#             */
/*   Updated: 2024/06/17 10:59:57 by brguicho         ###   ########.fr       */
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

# define DEAD 0
# define START 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define WAITING 5
# define END 6

typedef struct s_info
{
	int		nbr_philo;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int		nbr_time_to_eat;
}				t_info;

struct s_data;

typedef struct s_thread
{
	int				id;
	int				*left_fork;
	int				nbr_meals_eaten;
	int				right_fork;
	pthread_t		thread;
	int				state;
	struct s_data	*data;
}				t_thread;

typedef struct s_data
{
	t_info			*info;
	t_thread		**philo;
	pthread_mutex_t	fork;
	pthread_mutex_t	states;
}				t_data;

void	set_philo_var(t_thread *thread);
void	init_philo(t_data *data);
void	set_info(t_info *info, int argc, char **argv);
void	init(t_info *info);
void	start_thread(t_data *data);
int 	check_dead_main(t_data *data);

int		ft_philo(int argc, char **argv);
void	*ft_routine(void *data);
int		argv_are_digits(char **argv);
size_t	ft_atouli(char *str);
size_t	ft_get_current_time(void);
int		ft_usleep(size_t milliseconds);
void	ft_bzero(void *dest, unsigned int size);
void	*ft_calloc(size_t elementcount, size_t elementcize);
void	free_philos(t_thread **philo);

void	*ft_print_is_eating(void *data);
void	ft_print_has_taken_fork_r(t_thread *thread);
void	ft_print_has_taken_fork_l(t_thread *thread);
#endif