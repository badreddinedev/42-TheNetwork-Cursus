/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:49:38 by bamsyah           #+#    #+#             */
/*   Updated: 2023/11/17 18:21:00 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int key, t_mlx *mlx)
{
	if (key == KEY_EXIT)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_window);
		free(mlx->map.map);
		free(mlx->map.map_c);
		free(mlx->map.map_e);
		exit(0);
	}
	if (key == KEY_W || key == KEY_UP)
		move_up(mlx);
	else if (key == KEY_S || key == KEY_DOWN)
		move_down(mlx);
	else if (key == KEY_A || key == KEY_LEFT)
		move_left(mlx);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_right(mlx);
	ft_printf("Move count: %d\n", mlx->map.move_count);
	return (0);
}
