/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:11:34 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/08 23:16:48 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <errno.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <limits.h>

# define SEM_FORK "/forks"
# define SEM_PRINT_MSG "/print_msg"

typedef struct philo_args
{
	int	num_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times_each_philo_must_eat;
}	t_philo_args;

typedef struct philo
{
	int				id;
	sem_t			*forks;
	sem_t			*print_msg;
	long long		time_of_last_meal;
	long long		time;
	t_philo_args	args_info;
	int				fork_id;
}	t_philo;

int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			parse_args(char **argv);
void			check_empty_args(char **argv);
void			get_args_to_int(char **argv, t_philo_args *philo_info);
void			custom_usleep(int time_to_sleep, long long exec_time,
					t_philo *philo);
void			check_time_to_die(t_philo *philo);
unsigned long	now(void);
void			philo_routine(t_philo *philo);
void			*start_philo(t_philo_args args_info, t_philo *philos);
void			if_there_is_only_one_philo(t_philo *philo, t_philo_args args);
void			initialize_semaphores(t_philo *philos, int num_of_philos);
void			wait_for_philo(t_philo *philo);
void			take_first_fork(t_philo *philo);
void			take_second_fork(t_philo *philo);
int				is_eating(t_philo *philo);
void			is_sleeping(t_philo *philo);
void			is_thinking(t_philo *philo);

#endif