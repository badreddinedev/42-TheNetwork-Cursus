/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:28:15 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/03/16 17:44:51 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render(t_mlx *mlx)
{
	if (mlx->data.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->data.img);
	mlx->data.img = mlx_new_image(mlx->mlx_ptr, MAP_W, MAP_H);
	mlx->data.addr = mlx_get_data_addr(mlx->data.img, &mlx->data.bits_per_pixel,
			&mlx->data.line_length, &mlx->data.endian);
	cast_rays(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->data.img, 0, 0);
	return ;
}

int	move_player(t_mlx *mlx)
{
	if (mlx->cub3d.player.walk_direction)
		move_down_up(mlx);
	if (mlx->cub3d.player.turn_direction)
		move_left_right(mlx);
	if (mlx->cub3d.player.look)
		look_left_right(mlx);
	return (0);
}
