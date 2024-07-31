/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:16:09 by bamsyah           #+#    #+#             */
/*   Updated: 2024/01/25 16:40:26 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_philo(t_param *param, t_philo *philo, pthread_mutex_t *forks)
{
	pthread_mutex_t	*print_dead;
	int				i;

	i = 0;
	print_dead = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(print_dead, NULL))
		return (1);
	while (i < param->n_philo)
	{
		philo[i].param = param;
		philo[i].id = (i + 1);
		philo[i].l_fork = philo[i].id - 1;
		philo[i].r_fork = philo[i].id % param->n_philo;
		philo[i].eat_count = 0;
		philo[i].start_eat = now();
		philo[i].last_eat = now();
		philo[i].forks = forks;
		philo[i].print_dead = print_dead;
		philo[i].eat_mutex = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo[i].eat_mutex, NULL);
		i++;
	}
	return (0);
}

int	init_thread(t_param *param, t_philo *philo, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (init_philo(param, philo, forks))
		ft_error("Creation of philo failed.");
	while (i < param->n_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]))
			return (ft_error("Creation of threads failed"));
		usleep(100);
		i++;
	}
	end_routine(philo);
	return (0);
}
