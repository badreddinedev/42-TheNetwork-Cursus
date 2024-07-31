/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 04:52:19 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/01 15:13:24 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(char *str)
{
	size_t			i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (ft_error("The Number is Not Valid"));
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (ft_error("The Number is Not Valid"));
		result = result * 10 + str[i++] - '0';
	}
	if (result > INT_MAX)
		return (ft_error("The Number is Not Valid"));
	return (result);
}
