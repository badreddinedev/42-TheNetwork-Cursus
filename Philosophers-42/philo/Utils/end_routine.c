/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:45:15 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/02 03:23:12 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	death(t_philo *philo)
{
	if (now() - philo->last_eat > philo->param->t_die)
	{
		pthread_mutex_lock(philo->print_dead);
		printf("%d %d is died 💀🎃\n", now() - philo->start_eat, philo->id);
		return (-1);
	}
	return (0);
}

void	fill_cache(int *cache, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		cache[i] = 0;
}

int	all_philos_eat(int *cache, int len)
{
	int	i;

	i = 0;
	while (cache[i] == 1)
		i++;
	if (i == len)
		return (1);
	return (0);
}

void	end_routine(t_philo *philo)
{
	int	i;
	int	cache[255];

	i = 0;
	fill_cache(cache, philo->param->n_philo);
	while (i < philo->param->n_philo)
	{
		pthread_mutex_lock(philo[i].eat_mutex);
		if (philo->param->n_eat > 0
			&& (philo[i].eat_count == philo->param->n_eat))
		{
			cache[i] = 1;
			if (all_philos_eat(cache, philo->param->n_philo))
				return ;
		}
		if (death(&philo[i]) == -1)
			return ;
		pthread_mutex_unlock(philo[i].eat_mutex);
		i++;
		if (i == philo->param->n_philo)
			i = 0;
	}
}
