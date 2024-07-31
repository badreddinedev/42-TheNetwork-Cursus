/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 02:38:54 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/16 19:57:15 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	is_invalid_element(char *line)
{
	if (line[0] == '\n' && line[0] == '\0'
		&& line[0] == '\t')
		ft_putendl_fd("Error Invalid Map", 2);
}

int	parse_elements(t_cub_pars *cub, char *line)
{
	char	*trim_line;
	char	**split_line;
	char	*tmp;

	trim_line = ft_strtrim(line, " \t\n");
	split_line = ft_split(trim_line, ' ');
	if (!is_cardinal_direction(line))
		return (save_cardinal_direction(cub, line),
			free(trim_line), clean_map(split_line), 0);
	else if ((split_line[0][0] == 'F' || split_line[0][0] == 'C'))
		return (save_rgb(cub, line),
			free(trim_line), clean_map(split_line), 0);
	else if (!is_map(trim_line) && !is_graphics(*cub))
	{
		tmp = ft_strdup(line);
		cub->map = ft_strjoin(cub->map, tmp);
		return (free(trim_line), clean_map(split_line), 0);
	}
	return (free(trim_line), clean_map(split_line), 1);
}

void	parse(t_cub_pars *cub)
{
	char	*line;

	cub->map = ft_strdup("");
	while (1)
	{
		line = get_next_line(cub->fd);
		if (!line)
			break ;
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		if (parse_elements(cub, line))
			ft_putendl_fd("Invalide Map", 2);
		free(line);
	}
	check_map(cub);
}
