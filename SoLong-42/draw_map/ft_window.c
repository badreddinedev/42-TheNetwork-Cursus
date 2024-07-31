/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 03:13:32 by bamsyah           #+#    #+#             */
/*   Updated: 2023/11/21 23:02:09 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_window(t_mlx *window, t_map *check)
{
	window->mlx = mlx_init();
	window->mlx_window = mlx_new_window(window->mlx, check->width * 80,
			check->height * 80, "so_long");
	window->img = mlx_new_image(window->mlx, check->width * 80,
			check->height * 80);
	draw_map(window, check);
}
