/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 03:43:30 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/03/08 23:14:42 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	parse_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] > 32)
			{
				printf("error : arg invalide!!\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_empty_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			printf("error : empty argument!!\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	get_args_to_int(char **argv, t_philo_args *philo_info)
{
	check_empty_args(argv);
	philo_info->num_of_philos = ft_atoi(argv[1]);
	if (philo_info->num_of_philos == 0)
		exit(EXIT_FAILURE);
	philo_info->time_to_die = ft_atoi(argv[2]);
	philo_info->time_to_eat = ft_atoi(argv[3]);
	philo_info->time_to_sleep = ft_atoi(argv[4]);
	philo_info->num_of_times_each_philo_must_eat = 0;
	if (argv[5] && argv[5][0] != '\0')
	{
		philo_info->num_of_times_each_philo_must_eat = ft_atoi(argv[5]);
		if (philo_info->num_of_times_each_philo_must_eat == 0)
			exit(EXIT_FAILURE);
	}
	if (philo_info->num_of_philos < 0 || philo_info->time_to_die < 0
		|| philo_info->time_to_eat < 0 || philo_info->time_to_sleep < 0
		|| philo_info->num_of_times_each_philo_must_eat < 0)
	{
		printf("error : arg invalide!! --> nombre long\n");
		exit(EXIT_FAILURE);
	}
}
