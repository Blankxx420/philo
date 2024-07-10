/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:28:12 by brguicho          #+#    #+#             */
/*   Updated: 2024/07/10 14:27:33 by brguicho         ###   ########.fr       */
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

# define INT_MAX 2147483647

typedef struct s_info
{
	int		nbr_philo;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	int		nbr_time_to_eat;
}				t_info;

struct	s_data;

typedef struct s_thread
{
	int				id;
	long long int	last_timestamp;
	int				nbr_meals_eaten;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*own_fork;
	int				state;
	struct s_data	*data;
}				t_thread;

typedef struct s_data
{
	t_info			*info;
	t_thread		*philo;
	pthread_mutex_t	meal;
	pthread_mutex_t	dead;
	pthread_mutex_t	ready;
	pthread_mutex_t	print;
	int				flag_rdy;
	int				flag_dead;
	long long int			start_time;
}				t_data;

void	set_philo_var(t_thread *thread);
int		init_philo(t_data *data);
int		set_info(t_info *info, int argc, char **argv);
void	init(t_info *info);
int		init_data(t_data *data);

int		start_thread(t_data *data);
void	wait_all_philo(t_data *data);

int		ft_philo(int argc, char **argv);
void	*ft_routine(void *data);
int		argv_are_digits(char **argv);
long long int	ft_atoll(char *str);
long long int	ft_get_current_time(void);
int		ft_usleep(size_t milliseconds);
void	ft_bzero(void *dest, unsigned int size);
void	*ft_calloc(size_t elementcount, size_t elementcize);
void	free_philos(t_data *data);
void	free_all(t_data *data);
int		check_dead(t_thread *thread);
int		check_all_meal_eaten(t_data *data);
int		check_if_someone_died(t_data *data);
void	monitoring(t_data *data);
int		check_info(t_info *infos, int argc);
void	start_eating(t_thread *thread);
void	ft_print_is_eating(t_thread *thread);
void	ft_print_has_taken_fork(t_thread *thread);
void	ft_print_is_sleeping(t_thread *thread);
void	ft_print_is_thinking(t_thread *thread);
#endif