/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:39:43 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/03/16 04:41:29 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	rgb_to_int(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_color(t_image *texture, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = texture->addr + (y * texture->size_line + x * (texture->bits_per_pixel
				/ 8));
	color = *(unsigned int *)dst;
	return (color);
}

double	get_x(t_mlx *mlx)
{
	int	x;

	x = 0;
	if (mlx->is_vertical == 1)
	{
		x = fmod(mlx->ray_y, 64);
		if (x >= 62 || x <= 1)
			x = fmod(mlx->ray_x, 64);
	}
	else
	{
		x = fmod(mlx->ray_x, 64);
		if (x >= 62 || x <= 1)
			x = fmod(mlx->ray_y, 64);
	}
	return (x);
}

void	getdirection(t_mlx *mlx)
{
	if (check_wall_2(mlx, mlx->ray_x - 2, mlx->ray_y) == 0)
		mlx->x_offset = 0;
	if (check_wall_2(mlx, mlx->ray_x, mlx->ray_y - 2) == 1)
		mlx->x_offset = 1;
	if (check_wall_2(mlx, mlx->ray_x, mlx->ray_y + 2) == 0)
		mlx->x_offset = 2;
	if (check_wall_2(mlx, mlx->ray_x - 2, mlx->ray_y) == 1)
		mlx->x_offset = 3;
	if (check_wall_2(mlx, mlx->ray_x - 1, mlx->ray_y - 2) == 1)
		mlx->x_offset = 0;
}
