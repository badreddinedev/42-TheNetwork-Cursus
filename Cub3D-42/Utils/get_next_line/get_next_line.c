/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:14:14 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/15 02:34:10 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*read_file(int fd, char *rest)
{
	char		*buffer;
	ssize_t		rread;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!rest)
		rest = ft_strdup_g("");
	rread = 1;
	while (!ft_strchr_g(rest) && rread != 0)
	{
		rread = read(fd, buffer, BUFFER_SIZE);
		if (rread == -1)
			return (free(buffer), free(rest), NULL);
		buffer[rread] = '\0';
		rest = ft_strjoin_g(buffer, rest);
	}
	return (free(buffer), rest);
}

char	*ft_getline(char *rest)
{
	char	*str;
	int		i;

	i = 0;
	while (rest[i] != '\n' && rest[i])
		i++;
	if (rest[i] == '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		str[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_getrest(char *rest, char *line)
{
	char	*rrest;
	int		i;
	int		j;

	i = ft_strlen_g(line);
	j = 0;
	while (rest[i++])
		j++;
	rrest = malloc(sizeof(char) * (j + 1));
	if (!rrest)
		return (NULL);
	i = ft_strlen_g(line);
	j = 0;
	while (rest[i])
		rrest[j++] = rest[i++];
	rrest[j] = '\0';
	free(rest);
	return (rrest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = read_file(fd, rest);
	if (!rest)
		return (NULL);
	line = ft_getline(rest);
	if (line[0] == '\0')
	{
		free(rest);
		rest = NULL;
		return (free(line), NULL);
	}
	rest = ft_getrest(rest, line);
	if (!rest)
		return (free(line), NULL);
	return (line);
}
