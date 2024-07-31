/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:11:25 by bamsyah           #+#    #+#             */
/*   Updated: 2023/09/19 14:35:45 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strchr(char *rest)
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

char	*ft_strjoin(char *buffer, char *rest)
{
	char	*all;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!buffer)
		return (NULL);
	all = malloc(sizeof(char) * (ft_strlen(buffer) + ft_strlen(rest)) + 1);
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

char	*ft_strdup(char *str)
{
	char	*sstr;
	int		i;

	i = 0;
	sstr = malloc(sizeof(char) * ft_strlen(str) + 1);
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
