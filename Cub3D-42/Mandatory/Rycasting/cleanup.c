/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:02:50 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/03/15 16:04:13 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clean_textures(t_cub_pars *cub3d)
{
	if (cub3d->directions.north != NULL)
		free(cub3d->directions.north);
	if (cub3d->directions.south != NULL)
		free(cub3d->directions.south);
	if (cub3d->directions.east != NULL)
		free(cub3d->directions.east);
	if (cub3d->directions.west != NULL)
		free(cub3d->directions.west);
}

void	clean_map(char **matrice)
{
	int	i;

	i = 0;
	if (!matrice)
		return ;
	while (matrice[i])
	{
		free(matrice[i]);
		i++;
	}
	free(matrice);
}

void	clean_rgb(char *rgb, char *tmp)
{
	if (rgb)
		free(rgb);
	if (tmp)
		free(tmp);
}

void	free_t_image(t_image *img)
{
	if (img)
		free(img);
}

void	cleanup(t_mlx *mlx)
{
	clean_textures(&mlx->cub3d);
	clean_map(mlx->cub3d.map2d);
	free(mlx->cub3d.map);
	if (mlx->ea_texture)
		free_t_image(mlx->ea_texture);
	if (mlx->no_texture)
		free_t_image(mlx->no_texture);
	if (mlx->so_texture)
		free_t_image(mlx->so_texture);
	if (mlx->we_texture)
		free_t_image(mlx->we_texture);
}
