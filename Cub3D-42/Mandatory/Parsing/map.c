/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:15:13 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/16 19:57:12 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	has_map_conflicts(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
			{
				if ((map[i - 1][j] && map[i - 1][j] == '$')
					|| (map[i][j - 1] && map[i][j - 1] == '$')
					|| (map[i][j + 1] && map[i][j + 1] == '$')
					|| (map[i + 1][j] && map[i + 1][j] == '$'))
					ft_putendl_fd("Error Invalid Map---", 2);
			}
		}
	}
}

void	check_newline(char *map)
{
	int	i;

	i = -1;
	while (map[++i])
		if (map[i] == '\n' && map[i + 1] == '\n' )
			ft_putendl_fd("Error Invalid Map", 2);
}

int	is_map(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (!(line[i] == '1' || line[i] == '0'
				|| line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'W' || line[i] == 'E'
				|| line[i] == ' '))
			return (1);
	return (0);
}

void	check_map(t_cub_pars *cub)
{
	cub->map2d = ft_split(cub->map, '\n');
	cub->map_init.x = ft_strlen(cub->map2d[0]);
	cub->map_init.y = ft_file_len(cub->map2d);
	is_surrounded(cub);
	one_player(cub);
	player_surrounded(cub);
	rect_map(cub);
	has_map_conflicts(cub->map2d);
	get_p_position(cub);
}
