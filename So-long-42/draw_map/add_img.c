/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:50:06 by bamsyah           #+#    #+#             */
/*   Updated: 2023/11/16 04:18:49 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	add_image(t_mlx *add)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	add->back = mlx_xpm_file_to_image(add->mlx, "xpm/back.xpm", &x, &y);
	add->play = mlx_xpm_file_to_image(add->mlx, "xpm/play.xpm", &x, &y);
	add->wall = mlx_xpm_file_to_image(add->mlx, "xpm/wall.xpm", &x, &y);
	add->exit = mlx_xpm_file_to_image(add->mlx, "xpm/exit.xpm", &x, &y);
	add->coin = mlx_xpm_file_to_image(add->mlx, "xpm/coin.xpm", &x, &y);
}

void	put_image(t_map *map, t_mlx *window)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			line_25(map, window, i, j);
			j++;
		}
		i++;
	}
}

void	draw_map(t_mlx *add, t_map *map)
{
	add_image(add);
	put_image(map, add);
}

void	line_25(t_map *map, t_mlx *window, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(window->mlx, window->mlx_window,
			window->wall, j * 80, i * 80);
	else
	{
		mlx_put_image_to_window(window->mlx, window->mlx_window,
			window->back, j * 80, i * 80);
		if (map->map[i][j] == 'P')
			mlx_put_image_to_window(window->mlx, window->mlx_window,
				window->play, j * 80, i * 80);
		if (map->map[i][j] == 'E')
			mlx_put_image_to_window(window->mlx, window->mlx_window,
				window->exit, j * 80, i * 80);
		if (map->map[i][j] == 'C')
			mlx_put_image_to_window(window->mlx, window->mlx_window,
				window->coin, j * 80, i * 80);
	}
}
