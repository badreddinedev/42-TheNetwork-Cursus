/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <bamsyah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 08:37:31 by bamsyah           #+#    #+#             */
/*   Updated: 2023/08/24 01:37:47 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "./ft_printf/ft_printf.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	x;
	int	signe;

	i = 0;
	x = 0;
	signe = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = x * 10 + (str[i] - '0');
		i++;
	}
	return (x * signe);
}

void	send_signal(char *ppid, char *msg)
{
	int	pid;
	int	i;
	int	j;
	int	bitwise;

	i = 0;
	pid = ft_atoi(ppid);
	while (msg[i])
	{
		j = 0;
		while (j < 8)
		{
			bitwise = (msg[i] >> j) & 1;
			if (bitwise == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		send_signal(av[1], av[2]);
	else
		ft_printf("Use this syntax : ./client <pid> <string to send>\n");
	return (0);
}
