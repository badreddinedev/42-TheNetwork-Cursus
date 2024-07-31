/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:26:07 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/03/16 17:57:07 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cast(double ray_angle, t_mlx *mlx)
{
	double	player_x;
	double	player_y;
	double	distance;
	double	angle_diff;

	player_x = mlx->cub3d.player.x;
	player_y = mlx->cub3d.player.y;
	mlx->ray_x = player_x;
	mlx->ray_y = player_y;
	distance = 0.0;
	angle_diff = mlx->cub3d.player.rotation_angle - ray_angle;
	while (1)
	{
		mlx->ray_x += cos(ray_angle);
		mlx->ray_y += sin(ray_angle);
		if (check_wall(mlx, mlx->ray_x, mlx->ray_y))
		{
			distance = sqrt((mlx->ray_x - player_x) * (mlx->ray_x - player_x)
					+ (mlx->ray_y - player_y) * (mlx->ray_y - player_y));
			distance = distance * cos(angle_diff);
			mlx->distance = distance;
			break ;
		}
	}
}

void	cast_rays(t_mlx *mlx)
{
	double	ray_angle;
	double	ray_increment;
	int		i;

	ray_angle = mlx->cub3d.player.rotation_angle - ((FOV * (M_PI / 180)) / 2);
	mlx->rayangle = ray_angle;
	ray_increment = (FOV * (M_PI / 180)) / MAP_W;
	i = 0;
	while (i < MAP_W)
	{
		cast(ray_angle, mlx);
		if (roundf(fmod(mlx->ray_x, 64)) == 0)
		{
			mlx->is_horizontal = 1;
			mlx->is_vertical = 0;
		}
		else if (roundf(fmod(mlx->ray_y, 64)) == 0)
		{
			mlx->is_vertical = 1;
			mlx->is_horizontal = 0;
		}
		render3dwalls(mlx, i);
		ray_angle += ray_increment;
		i++;
	}
}
