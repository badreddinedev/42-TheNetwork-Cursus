/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:12:19 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/03/08 23:15:56 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	wait_for_philo(t_philo *philo)
{
	int	i;

	while (1)
	{
		if (waitpid(-1, NULL, WNOHANG))
		{
			i = 0;
			while (i < philo->args_info.num_of_philos)
			{
				kill(philo[i].fork_id, SIGKILL);
				usleep(300000);
				i++;
			}
			break ;
		}
		usleep(50);
	}
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_PRINT_MSG);
	sem_close(philo->forks);
	sem_close(philo->print_msg);
	free(philo);
	exit(EXIT_SUCCESS);
}

void	*start_philo(t_philo_args args_info, t_philo *philos)
{
	int	i;

	i = 0;
	if_there_is_only_one_philo(philos, args_info);
	while (i < args_info.num_of_philos)
	{
		philos[i].fork_id = fork();
		if (philos[i].fork_id == 0)
		{
			philos[i].id = i + 1;
			philos[i].args_info = args_info;
			philos[i].time = now();
			philos[i].time_of_last_meal = now();
			philos[i].forks = philos->forks;
			philos[i].print_msg = philos->print_msg;
			philo_routine(&philos[i]);
		}
		if (philos[i].fork_id == -1)
		{
			printf("Error: Unable to create process!\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (NULL);
}

void	if_there_is_only_one_philo(t_philo *philo, t_philo_args args)
{
	philo->args_info = args;
	if (philo->args_info.num_of_philos == 1)
	{
		philo->fork_id = fork();
		if (philo->fork_id == 0)
		{
			philo->time = now();
			sem_wait(philo->forks);
			printf("%lldms philo %d has taken a fork 🍴\n", \
				now() - philo->time, 1);
			custom_usleep(philo->args_info.time_to_die, now(), NULL);
			printf("%lldms philo %d died 💀🎃\n", \
				now() - philo->time, 1);
			sem_close(philo->forks);
			sem_close(philo->print_msg);
			free(philo);
			exit(EXIT_SUCCESS);
		}
		wait_for_philo(philo);
	}
}

void	initialize_semaphores(t_philo *philos, int num_of_philos)
{
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_PRINT_MSG);
	philos->forks = sem_open(SEM_FORK, O_CREAT | O_EXCL, 0777, num_of_philos);
	philos->print_msg = sem_open(SEM_PRINT_MSG, O_CREAT | O_EXCL, 0777, 1);
	if (philos->forks == SEM_FAILED || philos->print_msg == SEM_FAILED)
	{
		printf("error : semaphore was not created!!\n");
		free(philos);
		exit(EXIT_FAILURE);
	}
}
