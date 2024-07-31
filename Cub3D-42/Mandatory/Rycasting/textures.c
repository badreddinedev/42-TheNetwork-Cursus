/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:37:14 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/03/16 04:41:14 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_texture_2(void *ptr)
{
	if ((char *)ptr == NULL)
	{
		ft_putendl_fd("\033[0;31m 📛 Error Invalid Textures \033[0m", 2);
		exit (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

t_image	*new_texture(t_mlx *mlx, char *path)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
	{
		printf("Error\nmalloc failed\n");
		exit(1);
	}
	img->img = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &img->width,
			&img->height);
	if (check_texture_2(img->img) == EXIT_FAILURE)
		return (NULL);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	if (check_texture_2(img->addr) == EXIT_FAILURE)
		return (NULL);
	return (img);
}

void	textures_init(t_mlx *mlx)
{
	mlx->no_texture = new_texture(mlx, mlx->cub3d.directions.north);
	mlx->so_texture = new_texture(mlx, mlx->cub3d.directions.south);
	mlx->we_texture = new_texture(mlx, mlx->cub3d.directions.west);
	mlx->ea_texture = new_texture(mlx, mlx->cub3d.directions.east);
	if (mlx->no_texture == NULL || mlx->so_texture == NULL
		|| mlx->we_texture == NULL || mlx->ea_texture == NULL)
	{
		cleanup(mlx);
		exit(EXIT_FAILURE);
	}
}
