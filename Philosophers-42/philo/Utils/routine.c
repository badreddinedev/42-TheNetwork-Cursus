/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:48:40 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/02 03:21:50 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_state(t_philo *philo, char action)
{
	size_t	timestamp;

	timestamp = now() - philo->start_eat;
	pthread_mutex_lock(philo->print_dead);
	if (action == 'F')
		printf("%lu %d has taken a fork 🍴\n", timestamp, philo->id);
	else if (action == 'E')
		printf("%lu %d is eating 🍽️ 🍔\n", timestamp, philo->id);
	else if (action == 'S')
		printf("%lu %d is sleeping 😴\n", timestamp, philo->id);
	else if (action == 'T')
		printf("%lu %d is thinking 🤔 🤔\n", timestamp, philo->id);
	pthread_mutex_unlock(philo->print_dead);
}

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (1)
	{
		pthread_mutex_lock(&philo->forks[ft_min(philo->l_fork, philo->r_fork)]);
		ft_state(philo, 'F');
		pthread_mutex_lock(&philo->forks[ft_max(philo->l_fork, philo->r_fork)]);
		ft_state(philo, 'F');
		ft_state(philo, 'E');
		ft_time1(philo->param->t_eat);
		pthread_mutex_unlock(&philo->forks[philo->l_fork]);
		pthread_mutex_unlock(&philo->forks[philo->r_fork]);
		pthread_mutex_lock(philo->eat_mutex);
		if (philo->param->n_eat > 0)
			philo->eat_count++;
		philo->last_eat = now();
		pthread_mutex_unlock(philo->eat_mutex);
		ft_state(philo, 'S');
		ft_time1(philo->param->t_sleep);
		ft_state(philo, 'T');
	}
	return (NULL);
}
