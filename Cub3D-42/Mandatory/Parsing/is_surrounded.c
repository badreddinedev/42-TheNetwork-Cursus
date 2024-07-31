/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:51:18 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/16 19:57:08 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	is_valid_row(char *row)
{
	int		i;
	char	*tmp;

	tmp = ft_strtrim(row, "\t\v\f\r\n ");
	i = -1;
	while (tmp[++i])
	{
		if (tmp[i] != '1' && tmp[i] != ' ')
			ft_putendl_free("Invalid Map Row", 2, tmp);
	}
	free(tmp);
}

void	is_valid_column(char **column)
{
	int		i;
	char	*tmp;

	i = -1;
	while (column[++i])
	{
		tmp = ft_strtrim(column[i], "\t\v\f\r\n ");
		if (tmp[0] != '1' || tmp[ft_strlen(tmp) - 1] != '1')
			ft_putendl_free("Invalid Map Row", 2, tmp);
		free(tmp);
	}
}

void	is_surrounded(t_cub_pars *cub)
{
	is_valid_row(cub->map2d[0]);
	is_valid_row(cub->map2d[cub->map_init.y - 1]);
	is_valid_column(cub->map2d);
}
