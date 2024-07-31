/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:10:12 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/16 19:56:53 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_xpm(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (!ft_strncmp(path + (len - 4), ".xpm", 4))
		return (1);
	return (0);
}

int	fill_textures(char **split_line, t_cub_pars *cub, char *path)
{
	int	status;

	status = 0;
	if (split_line[1][0] == '.' && split_line[1][1] == '/')
	{
		if (split_line[0][0] == 'N' && split_line[0][1] == 'O'
		&& cub->directions.north == NULL)
			cub->directions.north = ft_strtrim(path, "\n");
		else if (split_line[0][0] == 'S' && split_line[0][1] == 'O'
		&& cub->directions.south == NULL)
			cub->directions.south = ft_strtrim(path, "\n");
		else if (split_line[0][0] == 'W' && split_line[0][1] == 'E'
		&& cub->directions.west == NULL)
			cub->directions.west = ft_strtrim(path, "\n");
		else if (split_line[0][0] == 'E' && split_line[0][1] == 'A'
		&& cub->directions.east == NULL)
			cub->directions.east = ft_strtrim(path, "\n");
		else
			status = 1;
	}
	else
		status = 1;
	return (status);
}

void	save_textures(char **split_line, t_cub_pars *cub)
{
	char	*path;

	path = split_line[1];
	if (fill_textures(split_line, cub, path) == 1)
		ft_putendl_free("Invalid Elements", 2, path);
	if (check_xpm(path) == 1)
		ft_putendl_free("Invalid Elements", 2, path);
}

void	save_cardinal_direction(t_cub_pars *cub, char *line)
{
	char	*trim_line;
	char	**split_line;

	trim_line = ft_strtrim(line, " ");
	split_line = ft_split(trim_line, ' ');
	save_textures(split_line, cub);
	clean_map(split_line);
	free(trim_line);
}

int	is_cardinal_direction(char *line)
{
	char	*trim_line;
	char	**split_line;
	int		len;

	trim_line = ft_strtrim(line, " ");
	split_line = ft_split(trim_line, ' ');
	len = ft_file_len(split_line);
	if (len == 2
		&& ft_strlen(split_line[0]) == 2
		&& ((split_line[0][0] == 'N' && split_line[0][1] == 'O') ||
			(split_line[0][0] == 'S' && split_line[0][1] == 'O') ||
			(split_line[0][0] == 'W' && split_line[0][1] == 'E') ||
			(split_line[0][0] == 'E' && split_line[0][1] == 'A')))
	{
		clean_map(split_line);
		free(trim_line);
		return (0);
	}
	clean_map(split_line);
	free(trim_line);
	return (1);
}
