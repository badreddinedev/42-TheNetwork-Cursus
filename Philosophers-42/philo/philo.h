/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:53:45 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/01 15:13:17 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
//----------------Include----------------
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <limits.h>
# include <stdio.h>
# include <sys/time.h>
//----------------Include----------------

//----------------Struct----------------
typedef struct s_param
{
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	n_philo;
	int	n_eat;
}	t_param;

typedef struct s_philo
{
	t_param			*param;
	pthread_t		thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print_dead;
	pthread_mutex_t	*eat_mutex;
	int				id;
	int				l_fork;
	int				r_fork;
	int				eat_count;
	int				start_eat;
	int				last_eat;
}	t_philo;
//----------------Struct----------------

//----------------Utils-----------------
int			check_param(int ac, char **av);
int			ft_error(char *str);
int			ft_atoi(char *str);
void		init_param(t_param *param, int ac, char **av);
void		init_mutex(t_param *param, pthread_mutex_t *forks);
int			init_thread(t_param *param, t_philo *philo, pthread_mutex_t *forks);
void		*routine(void *philo);
void		end_routine(t_philo *philo);
suseconds_t	now(void);
void		ft_time1(int wait_time);
//----------------Utils-----------------
#endif