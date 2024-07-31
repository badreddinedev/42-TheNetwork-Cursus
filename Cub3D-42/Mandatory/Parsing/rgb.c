/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 04:47:22 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/16 19:57:29 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_convert(char *color)
{
	char	*path;
	int		val;

	if (!color)
		ft_putendl_fd("Error Invalid File", 2);
	path = ft_strtrim(color, " ");
	if (path[0] == '\0')
		ft_putendl_free("Error Invalid File", 2, path);
	val = ft_atoi(path);
	free(path);
	return (val);
}

void	rgb_valid(char **rgb)
{
	char	*path;
	int		color;
	int		i;
	int		j;

	i = -1;
	if (ft_file_len(rgb) != 3)
		ft_putendl_fd("Invalid rgb", 2);
	while (rgb[++i])
	{
		j = -1;
		path = ft_strtrim(rgb[i], " ");
		while (path[++j])
			if (!ft_isdigit(path[j]) && path[j] != '\n')
				ft_putendl_free("Invalid rgb color", 2, path);
		color = ft_atoi(path);
		if (color < 0 || color > 255)
			ft_putendl_free("Invalid rgb color", 2, path);
		free(path);
	}
}

void	fill_rgbs(t_cub_pars *cub, char **rgb, char id)
{
	rgb_valid(rgb);
	if (id == 'F')
	{
		if (cub->floor.b != -1 || cub->floor.g != -1
			|| cub->floor.r != -1)
			ft_putendl_fd("Error Invalid File", 2);
		cub->floor.r = ft_convert(rgb[0]);
		cub->floor.g = ft_convert(rgb[1]);
		cub->floor.b = ft_convert(rgb[2]);
	}
	if (id == 'C')
	{
		if (cub->celling.b != -1 || cub->celling.g != -1
			|| cub->celling.r != -1)
			ft_putendl_fd("Error Invalid File", 2);
		cub->celling.r = ft_convert(rgb[0]);
		cub->celling.g = ft_convert(rgb[1]);
		cub->celling.b = ft_convert(rgb[2]);
	}
	clean_map(rgb);
}

int	comma(char *line)
{
	char	**split;
	char	*rgbs;
	int		c_count;
	int		i;

	split = ft_split(line, ' ');
	rgbs = ft_strtrim(split[1], " ");
	c_count = 0;
	i = 0;
	while (rgbs[i])
	{
		if (rgbs[i] == ',')
			c_count++;
		if ((rgbs[i] == ',' && rgbs[i + 1] == ',') || c_count > 2)
			return (clean_map(split), free(rgbs), 1);
		i++;
	}
	return (clean_map(split), free(rgbs), 0);
}

void	save_rgb(t_cub_pars *cub, char *line)
{
	char	*hex;
	char	**rgbs;
	char	**tmp;

	hex = ft_strtrim(line, " ");
	if (comma(hex))
		ft_putendl_free("Invalid Color", 2, hex);
	rgbs = ft_split(hex, ',');
	if (rgbs[0][0] == 'F')
	{
		tmp = ft_split(rgbs[0], ' ');
		free(rgbs[0]);
		rgbs[0] = ft_strtrim(tmp[1], " ");
		clean_map(tmp);
		fill_rgbs(cub, rgbs, 'F');
	}
	if (rgbs[0][0] == 'C')
	{
		tmp = ft_split(rgbs[0], ' ');
		free(rgbs[0]);
		rgbs[0] = ft_strtrim(tmp[1], " ");
		clean_map(tmp);
		fill_rgbs(cub, rgbs, 'C');
	}
	free(hex);
}
