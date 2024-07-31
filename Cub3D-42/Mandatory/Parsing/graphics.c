/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:18:42 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/16 19:57:02 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_texture_dir(t_cub_pars cub)
{
	if (!cub.directions.north)
		return (1);
	if (!cub.directions.south)
		return (1);
	if (!cub.directions.east)
		return (1);
	if (!cub.directions.west)
		return (1);
	return (0);
}

int	check_rgb(t_cub_pars cub)
{
	if (cub.celling.r > 255 || cub.celling.r < 0)
		return (1);
	if (cub.celling.g > 255 || cub.celling.g < 0)
		return (1);
	if (cub.celling.b > 255 || cub.celling.b < 0)
		return (1);
	if (cub.floor.r > 255 || cub.floor.r < 0)
		return (1);
	if (cub.floor.g > 255 || cub.floor.g < 0)
		return (1);
	if (cub.floor.b > 255 || cub.floor.b < 0)
		return (1);
	return (0);
}

int	is_graphics(t_cub_pars cub)
{
	if (check_texture_dir(cub) || check_rgb(cub))
		return (1);
	return (0);
}
