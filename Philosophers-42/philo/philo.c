/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:54:33 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/01 15:13:15 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_param			param;
	t_philo			*philo;
	pthread_mutex_t	*forks;

	if (check_param(ac, av) == -1)
		return (1);
	init_param(&param, ac, av);
	forks = malloc(sizeof(pthread_mutex_t) * param.n_philo);
	philo = malloc(sizeof(t_philo) * param.n_philo);
	init_mutex(&param, forks);
	init_thread(&param, philo, forks);
	return (0);
}
