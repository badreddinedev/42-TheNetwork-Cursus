/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:41:16 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/16 19:57:22 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	alpha(char c)
{
	if (c == 'N')
		return (NO);
	else if (c == 'S')
		return (SO);
	else if (c == 'E')
		return (EA);
	else
		return (WE);
}

void	get_p_position(t_cub_pars *cub)
{
	int	px;
	int	py;

	px = (int)cub->player.x;
	py = (int)cub->player.y;
	cub->player.y = 0;
	while (cub->map2d[py])
	{
		px = 0;
		while (cub->map2d[py][px])
		{
			if (cub->map2d[py][px] == 'S' || cub->map2d[py][px] == 'N'
				|| cub->map2d[py][px] == 'E' || cub->map2d[py][px] == 'W')
			{
				cub->player.rotation_angle = alpha(cub->map2d[py][px]);
				cub->player.x = (float)(px * TILE_SIZE + 16);
				cub->player.y = (float)(py * TILE_SIZE + 16);
				return ;
			}
			px++;
		}
		py++;
	}
}

void	player_surrounded(t_cub_pars *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub->map2d[++i])
	{
		j = -1;
		while (cub->map2d[i][++j])
		{
			if (ft_strchr("NSEW", cub->map2d[i][j]))
			{
				if (cub->map2d[i - 1][j] == ' '
					|| cub->map2d[i][j - 1] == ' '
					|| cub->map2d[i][j + 1] == ' '
					|| cub->map2d[i + 1][j] == ' ')
					ft_putendl_fd("Invalid Player Not Surrounded", 2);
			}
		}
	}
}

void	one_player(t_cub_pars *cub)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (cub->map2d[++i])
	{
		j = -1;
		while (cub->map2d[i][++j])
		{
			if (ft_strchr("NSEW", cub->map2d[i][j]))
				count++;
		}
	}
	if (count != 1)
		ft_putendl_fd("Invalid More Player in The Map", 2);
}
