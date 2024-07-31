/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <bamsyah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 08:37:43 by bamsyah           #+#    #+#             */
/*   Updated: 2023/08/24 01:36:15 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "./ft_printf/ft_printf.h"

void	thesignal(int signal)
{
	static int	count;
	static unsigned char	c;

	c = ((signal == SIGUSR1) << count) | c;
	count++;
	if (count == 8)
	{
		write(1, &c, 1);
		count = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("The PID is %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, thesignal);
		signal(SIGUSR2, thesignal);
		pause();
	}
}
