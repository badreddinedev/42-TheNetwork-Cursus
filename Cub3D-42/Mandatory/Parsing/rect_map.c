/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:47:06 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/16 19:57:25 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

size_t	tall_line(char **map)
{
	size_t	i;
	size_t	j;
	size_t	max;

	i = -1;
	max = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (max < ft_strlen(map[i]))
				max = ft_strlen(map[i]);
	}
	return (max);
}

char	*get_line(char *line, size_t max)
{
	char	*new_line;
	size_t	i;

	new_line = ft_calloc_char(1, (max + 1), '$');
	i = 0;
	while (i < max)
	{
		if (ft_strlen(line) > i
			&& (line[i] == '1' || line[i] == '0' || line[i] == 'E'
				|| line[i] == 'W' || line[i] == 'N' || line[i] == 'S' ))
			new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

void	rect_map(t_cub_pars *cub)
{
	int		i;
	char	*tmp;
	char	*row;
	size_t	max;

	i = -1;
	max = tall_line(cub->map2d);
	while (cub->map2d[++i])
	{
		tmp = ft_strdup(cub->map2d[i]);
		row = get_line(tmp, max);
		free(cub->map2d[i]);
		cub->map2d[i] = row;
		free(tmp);
	}
}
