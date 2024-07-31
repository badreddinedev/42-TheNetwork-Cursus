/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:50:18 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/08 23:16:09 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo_bonus.h"

int	main(int ac, char **av)
{
	t_philo_args	args;
	t_philo			*philos;

	if (ac == 5 || ac == 6)
	{
		parse_args(av);
		get_args_to_int(av, &args);
		philos = (t_philo *)malloc(sizeof(t_philo) * args.num_of_philos);
		if (philos == NULL)
			return (write(1, "memory was not allocated!!\n", 27));
		initialize_semaphores(philos, args.num_of_philos);
		start_philo(args, philos);
		wait_for_philo(philos);
	}
	else
		printf("Need proper arguments!\n");
	return (0);
}
