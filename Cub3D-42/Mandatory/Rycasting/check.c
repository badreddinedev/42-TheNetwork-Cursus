/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:28:44 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/03/16 04:41:01 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

int	check_wall(t_mlx *mlx, float x, float y)
{
	if ((int)x < 0 || (int)y < 0 || (int)x >= MAP_W || (int)y >= MAP_H)
		return (1);
	if (mlx->cub3d.map2d[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1'
		|| mlx->cub3d.map2d[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '$')
		return (1);
	if (mlx->cub3d.map2d[(int)((y - 2) / TILE_SIZE)][(int)(x
			/ TILE_SIZE)] == '1' || mlx->cub3d.map2d[(int)((y
			- 2) / TILE_SIZE)][(int)(x / TILE_SIZE)] == '$')
		return (1);
	if (mlx->cub3d.map2d[(int)((y + 2) / TILE_SIZE)][(int)(x
			/ TILE_SIZE)] == '1' || mlx->cub3d.map2d[(int)((y
			+ 2) / TILE_SIZE)][(int)(x / TILE_SIZE)] == '$')
		return (1);
	if (mlx->cub3d.map2d[(int)(y / TILE_SIZE)][(int)((x - 2)
			/ TILE_SIZE)] == '1' || mlx->cub3d.map2d[(int)(y
			/ TILE_SIZE)][(int)((x - 2) / TILE_SIZE)] == '$')
		return (1);
	if (mlx->cub3d.map2d[(int)(y / TILE_SIZE)][(int)((x + 2)
			/ TILE_SIZE)] == '1' || mlx->cub3d.map2d[(int)(y
			/ TILE_SIZE)][(int)((x + 2) / TILE_SIZE)] == '$')
		return (1);
	return (0);
}

int	check_wall_2(t_mlx *mlx, float x, float y)
{
	if (mlx->cub3d.map2d[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1')
		return (0);
	if (mlx->cub3d.map2d[(int)((y - 2) / TILE_SIZE)][(int)(x
			/ TILE_SIZE)] == '1')
		return (1);
	if (mlx->cub3d.map2d[(int)((y + 2) / TILE_SIZE)][(int)(x
			/ TILE_SIZE)] == '1')
		return (0);
	if (mlx->cub3d.map2d[(int)(y / TILE_SIZE)][(int)((x - 2)
			/ TILE_SIZE)] == '1')
		return (1);
	if (mlx->cub3d.map2d[(int)(y / TILE_SIZE)][(int)((x + 2)
			/ TILE_SIZE)] == '1')
		return (1);
	return (0);
}
