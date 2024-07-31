/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 06:23:00 by bamsyah           #+#    #+#             */
/*   Updated: 2023/09/19 14:35:35 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putbase(unsigned long i, char *s, int *len)
{
	if (i >= 16)
	{
		ft_putbase(i / 16, s, len);
		ft_putbase(i % 16, s, len);
	}
	else
	{
		*len += ft_putchar_len(s[i]);
	}
}

void	ft_putunbr_len(unsigned int nbr, int *len)
{
	if (nbr <= 0 || nbr >= 9)
	{
		ft_putnbr_len(nbr / 10, len);
		ft_putnbr_len(nbr % 10, len);
	}
	else
		*len += ft_putchar_len(nbr + 48);
}

int	ft_putstr_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	ft_putnbr_len(int nbr, int *len)
{
	if (nbr == INT_MIN)
	{
		write(1, "-2147483648", 11);
		*len += 11;
	}
	else if (nbr >= 0 && nbr <= 9)
		*len += ft_putchar_len(nbr + '0');
	else if (nbr < 0)
	{
		*len += ft_putchar_len('-');
		ft_putnbr_len(nbr * (-1), len);
	}
	else
	{
		ft_putnbr_len(nbr / 10, len);
		ft_putnbr_len(nbr % 10, len);
	}
}

int	ft_putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}
