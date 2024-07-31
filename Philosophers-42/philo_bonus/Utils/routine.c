/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:54:37 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/03/08 23:14:53 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	check_time_to_die(t_philo *philo)
{
	if ((int)(now() - philo->time_of_last_meal) >= philo->args_info.time_to_die)
	{
		sem_wait(philo->print_msg);
		printf("%lldms philo %d died 💀🎃\n",
			(now() - philo->time), philo->id);
		exit(EXIT_SUCCESS);
	}
}

void	custom_usleep(int time_to_sleep, long long exec_time, t_philo *philo)
{
	while (1)
	{
		if ((int)((now() - exec_time)) >= time_to_sleep)
			break ;
		if (philo)
			check_time_to_die(philo);
		usleep(50);
	}
}

void	philo_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		custom_usleep(30, now(), NULL);
	while (1)
	{
		take_first_fork(philo);
		take_second_fork(philo);
		if (!is_eating(philo))
			break ;
		is_sleeping(philo);
		is_thinking(philo);
	}
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_PRINT_MSG);
	sem_close(philo->forks);
	sem_close(philo->print_msg);
	exit(EXIT_SUCCESS);
}
