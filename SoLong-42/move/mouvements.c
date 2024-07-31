/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:47:32 by bamsyah           #+#    #+#             */
/*   Updated: 2023/11/17 18:30:55 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	win(t_mlx *mlx)
{
	ft_printf("\033[0;32m\
██╗░░░██╗░█████╗░██╗░░░██╗░██╗░░░░░░░██╗██╗███╗░░██╗\n\
╚██╗░██╔╝██╔══██╗██║░░░██║░██║░░██╗░░██║██║████╗░██║\n\
░╚████╔╝░██║░░██║██║░░░██║░╚██╗████╗██╔╝██║██╔██╗██║\n\
░░╚██╔╝░░██║░░██║██║░░░██║░░████╔═████║░██║██║╚████║\n\
░░░██║░░░╚█████╔╝╚██████╔╝░░╚██╔╝░╚██╔╝░██║██║░╚███║\n\
░░░╚═╝░░░░╚════╝░░╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝\n");
	mlx_destroy_window(mlx->mlx, mlx->mlx_window);
	exit(0);
}

void	move_up(t_mlx *mlx)
{
	if ((mlx->map.map[mlx->map.player_x - 1][mlx->map.player_y] != '1'
		&& mlx->map.map[mlx->map.player_x - 1][mlx->map.player_y] != 'E'))
	{
		mlx->map.move_count++;
		if (mlx->map.map[mlx->map.player_x - 1][mlx->map.player_y] == 'C')
		{
			(--mlx->map.collectible);
			mlx->map.map[mlx->map.player_x - 1][mlx->map.player_y] = '0';
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->back,
				mlx->map.player_y * 80, mlx->map.player_x * 80 - 80);
		}
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->back,
			mlx->map.player_y * 80, mlx->map.player_x * 80);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->play,
			mlx->map.player_y * 80, mlx->map.player_x * 80 - 80);
		mlx->map.player_x -= 1;
	}
	else if (mlx->map.map[mlx->map.player_x - 1][mlx->map.player_y] == 'E'
		&& mlx->map.collectible == 0)
		win(mlx);
}

void	move_down(t_mlx *mlx)
{
	if ((mlx->map.map[mlx->map.player_x + 1][mlx->map.player_y] != '1'
		&& mlx->map.map[mlx->map.player_x + 1][mlx->map.player_y] != 'E'))
	{
		if (mlx->map.map[mlx->map.player_x + 1][mlx->map.player_y] != '1')
			mlx->map.move_count++;
		if (mlx->map.map[mlx->map.player_x + 1][mlx->map.player_y] == 'C')
		{
			(--mlx->map.collectible);
			mlx->map.map[mlx->map.player_x + 1][mlx->map.player_y] = '0';
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->back,
				mlx->map.player_y * 80, mlx->map.player_x * 80 + 80);
		}
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->back,
			mlx->map.player_y * 80, mlx->map.player_x * 80);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->play,
			mlx->map.player_y * 80, mlx->map.player_x * 80 + 80);
		mlx->map.player_x += 1;
	}
	else if (mlx->map.map[mlx->map.player_x + 1][mlx->map.player_y] == 'E'
		&& mlx->map.collectible == 0)
		win(mlx);
}

void	move_left(t_mlx *mlx)
{
	if ((mlx->map.map[mlx->map.player_x][mlx->map.player_y - 1] != '1'
		&& mlx->map.map[mlx->map.player_x][mlx->map.player_y - 1] != 'E'))
	{
		if (mlx->map.map[mlx->map.player_x][mlx->map.player_y - 1] != '1')
			mlx->map.move_count++;
		if (mlx->map.map[mlx->map.player_x][mlx->map.player_y - 1] == 'C')
		{
			(--mlx->map.collectible);
			mlx->map.map[mlx->map.player_x][mlx->map.player_y - 1] = '0';
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->back,
				mlx->map.player_y * 80 - 80, mlx->map.player_x * 80);
		}
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->back,
			mlx->map.player_y * 80, mlx->map.player_x * 80);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->play,
			mlx->map.player_y * 80 - 80, mlx->map.player_x * 80);
		mlx->map.player_y -= 1;
	}
	else if (mlx->map.map[mlx->map.player_x][mlx->map.player_y - 1] == 'E'
		&& mlx->map.collectible == 0)
		win(mlx);
}

void	move_right(t_mlx *mlx)
{
	if ((mlx->map.map[mlx->map.player_x][mlx->map.player_y + 1] != '1'
		&& mlx->map.map[mlx->map.player_x][mlx->map.player_y + 1] != 'E'))
	{
		if (mlx->map.map[mlx->map.player_x][mlx->map.player_y + 1] != '1')
			mlx->map.move_count++;
		if (mlx->map.map[mlx->map.player_x][mlx->map.player_y + 1] == 'C')
		{
			(--mlx->map.collectible);
			mlx->map.map[mlx->map.player_x][mlx->map.player_y + 1] = '0';
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->back,
				mlx->map.player_y * 80 + 80, mlx->map.player_x * 80);
		}
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->back,
			mlx->map.player_y * 80, mlx->map.player_x * 80);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->play,
			mlx->map.player_y * 80 + 80, mlx->map.player_x * 80);
		mlx->map.player_y += 1;
	}
	else if (mlx->map.map[mlx->map.player_x][mlx->map.player_y + 1] == 'E'
		&& mlx->map.collectible == 0)
		win(mlx);
}
