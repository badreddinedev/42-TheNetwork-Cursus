/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:11:25 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/15 02:33:43 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_strchr_g(char *rest)
{
	int	i;

	i = 0;
	while (rest && rest[i])
	{
		if (rest[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_g(char *buffer, char *rest)
{
	char	*all;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!buffer)
		return (NULL);
	all = malloc(sizeof(char) * (ft_strlen_g(buffer) + ft_strlen_g(rest)) + 1);
	if (!all)
		return (NULL);
	while (rest && rest[i])
	{
		all[i] = rest[i];
		i++;
	}
	while (buffer[y])
	{
		all[i++] = buffer[y++];
	}
	all[i] = '\0';
	free(rest);
	return (all);
}

char	*ft_strdup_g(char *str)
{
	char	*sstr;
	int		i;

	i = 0;
	sstr = malloc(sizeof(char) * ft_strlen_g(str) + 1);
	if (!sstr)
		return (NULL);
	while (str[i])
	{
		sstr[i] = str[i];
		i++;
	}
	sstr[i] = '\0';
	return (sstr);
}

int	ft_strlen_g(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
