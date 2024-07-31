/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 04:44:42 by bamsyah           #+#    #+#             */
/*   Updated: 2023/11/16 05:24:15 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_position(t_map *map)
{
	int	position;
	int	i;

	i = -1;
	while (map->map[++i])
	{
		position = -1;
		while (map->map[i][++position])
		{
			if (map->map[i][position] == 'P')
			{
				map->player_y = i;
				map->player_x = position;
			}
		}
	}
	if ((map->map[map->player_y][map->player_x - 1] == '1')
		&& (map->map[map->player_y][map->player_x + 1] == '1')
		&& (map->map[map->player_y - 1][map->player_x] == '1')
		&& (map->map[map->player_y + 1][map->player_x] == '1'))
		invalid_map();
}

void	check_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
		j++;
	while (map[0][i] && map[j - 1][i])
	{
		if ((map[0][i] != '1') || (map[j - 1][i] != '1'))
			invalid_map();
		i++;
	}
}

void	left_right(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][j])
		j++;
	while (map[i])
	{
		if ((map[i][0] != '1') || (map[i][j - 1] != '1'))
			invalid_map();
		i++;
	}
}
