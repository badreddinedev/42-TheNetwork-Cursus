/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <bamsyah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:38:29 by bamsyah           #+#    #+#             */
/*   Updated: 2023/07/19 23:33:44 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *rest)
{
	char		*buffer;
	ssize_t		rread;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!rest)
		rest = ft_strdup("");
	rread = 1;
	while (!ft_strchr(rest) && rread != 0)
	{
		rread = read(fd, buffer, BUFFER_SIZE);
		if (rread == -1)
			return (free(buffer), free(rest), NULL);
		buffer[rread] = '\0';
		rest = ft_strjoin(buffer, rest);
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

	i = ft_strlen(line);
	j = 0;
	while (rest[i++])
		j++;
	rrest = malloc(sizeof(char) * (j + 1));
	if (!rrest)
		return (NULL);
	i = ft_strlen(line);
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
	static char	*rest[10240];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest[fd] = read_file(fd, rest[fd]);
	if (!rest[fd])
		return (NULL);
	line = ft_getline(rest[fd]);
	if (line[0] == '\0')
	{
		free(rest[fd]);
		rest[fd] = NULL;
		return (free(line), NULL);
	}
	rest[fd] = ft_getrest(rest[fd], line);
	if (!rest[fd])
		return (free(line), NULL);
	return (line);
}
