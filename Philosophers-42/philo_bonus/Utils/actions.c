/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:21:52 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/03/08 23:14:18 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	take_first_fork(t_philo *philo)
{
	sem_wait(philo->forks);
	check_time_to_die(philo);
	sem_wait(philo->print_msg);
	printf("%lldms philo %d has taken a fork 🍴\n",
		(now() - philo->time), philo->id);
	sem_post(philo->print_msg);
}

void	take_second_fork(t_philo *philo)
{
	sem_wait(philo->forks);
	check_time_to_die(philo);
	sem_wait(philo->print_msg);
	printf("%lldms philo %d has taken a fork 🍴\n",
		(now() - philo->time), philo->id);
}

int	is_eating(t_philo *philo)
{
	printf("%lldms philo %d is eating 🍽️ 🍔\n",
		(now() - philo->time), philo->id);
	sem_post(philo->print_msg);
	philo->time_of_last_meal = now();
	custom_usleep(philo->args_info.time_to_eat, now(), NULL);
	sem_post(philo->forks);
	sem_post(philo->forks);
	if (philo->args_info.num_of_times_each_philo_must_eat != 0)
	{
		philo->args_info.num_of_times_each_philo_must_eat--;
		if (philo->args_info.num_of_times_each_philo_must_eat == 0)
			return (0);
	}
	return (1);
}

void	is_sleeping(t_philo *philo)
{
	sem_wait(philo->print_msg);
	printf("%lldms philo %d is sleeping 😴\n",
		(now() - philo->time), philo->id);
	sem_post(philo->print_msg);
	custom_usleep(philo->args_info.time_to_sleep, now(), philo);
	check_time_to_die(philo);
}

void	is_thinking(t_philo *philo)
{
	sem_wait(philo->print_msg);
	printf("%lldms philo %d is thinking 🤔 🤔\n",
		(now() - philo->time), philo->id);
	sem_post(philo->print_msg);
}
