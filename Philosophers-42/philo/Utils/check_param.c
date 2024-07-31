/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 04:23:27 by bamsyah           #+#    #+#             */
/*   Updated: 2024/01/23 20:19:21 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_param(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (ft_error("Incorrect Number of Argument."));
	while (i < ac)
	{
		if (ft_atoi(av[i]) == -1)
			return (-1);
		else if (ft_atoi(av[i]) == 0)
			return (ft_error("The argument should not be [0]"));
		i++;
	}
	return (0);
}
