/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_components.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:03:47 by bamsyah           #+#    #+#             */
/*   Updated: 2023/11/26 20:59:05 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	one_player(char *player)
{
	int	i;
	int	y;

	i = 0;
	while (player[i])
	{
		if (player[i] == 'P')
		{
			y = i + 1;
			while (player[y])
			{
				if (player[y] == 'P')
					invalid_map();
				y++;
			}
		}
		i++;
	}
}

void	one_exit(char *player)
{
	int	i;
	int	y;

	i = 0;
	while (player[i])
	{
		if (player[i] == 'E')
		{
			y = i + 1;
			while (player[y])
			{
				if (player[y] == 'E')
					invalid_map();
				y++;
			}
		}
		i++;
	}
}

void	collectible(char *player, t_map *map)
{
	int	i;

	i = 0;
	map->collectible = 0;
	while (player[i])
	{
		if (player[i] == 'C')
		{
			map->collectible++;
		}
		i++;
	}
	if (map->collectible == 0)
		invalid_map();
}
