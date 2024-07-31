/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:35:40 by bamsyah           #+#    #+#             */
/*   Updated: 2024/01/23 22:53:37 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_mutex(t_param *param, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < param->n_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			ft_error("Creation of forks mutexes failed.");
		i++;
	}
}
