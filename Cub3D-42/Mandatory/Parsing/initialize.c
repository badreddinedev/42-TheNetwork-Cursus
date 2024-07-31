/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:17:35 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/16 19:57:05 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_textures(t_cub_pars *cub_pars)
{
	cub_pars->directions.east = NULL;
	cub_pars->directions.north = NULL;
	cub_pars->directions.south = NULL;
	cub_pars->directions.west = NULL;
}

void	init_rgb(t_cub_pars *cub_pars)
{
	cub_pars->celling.b = -1;
	cub_pars->celling.g = -1;
	cub_pars->celling.r = -1;
	cub_pars->floor.b = -1;
	cub_pars->floor.g = -1;
	cub_pars->floor.r = -1;
}

void	init_player(t_cub_pars *cub_pars)
{
	cub_pars->player.x = 0;
	cub_pars->player.y = 0;
}

void	init_map(t_cub_pars *cub_pars)
{
	cub_pars->map_init.x = 0;
	cub_pars->map_init.y = 0;
}

void	ft_initialize(t_cub_pars *cub_pars)
{
	init_textures(cub_pars);
	init_rgb(cub_pars);
	init_player(cub_pars);
	init_map(cub_pars);
}
