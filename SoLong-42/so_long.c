/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 04:44:53 by bamsyah           #+#    #+#             */
/*   Updated: 2023/11/21 04:36:55 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_all(void *param)
{
	t_mlx	*game;

	game = (t_mlx *)param;
	free(game->map.map);
	free(game->map.map_c);
	free(game->map.map_e);
	exit(0);
	return (1);
}

char	*map(int fd, t_map *map)
{
	char	*read_line;
	char	*split;

	split = NULL;
	while (1)
	{
		read_line = get_next_line(fd);
		if (!read_line)
			break ;
		split = ft_strjoin2(split, read_line);
		free(read_line);
	}
	check_newline(split);
	one_player(split);
	one_exit(split);
	collectible(split, map);
	return (split);
}

void	ft_map(t_map *map, char *line)
{
	map->map = ft_split(line, '\n');
	map->map_c = ft_split(line, '\n');
	map->map_e = ft_split(line, '\n');
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_mlx	window;

	window.map.move_count = 0;
	if (ac != 2)
		invalid_map();
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		invalid_map();
	check_name(av[1]);
	line = map(fd, &window.map);
	if (!line)
		invalid_map();
	ft_map(&window.map, line);
	check_all(&window.map);
	map_dimension(&window.map);
	path_config(&window.map);
	ft_window(&window, &window.map);
	mlx_hook(window.mlx_window, 2, 0, key_press, &window);
	mlx_hook(window.mlx_window, 17, 0, free_all, &window);
	mlx_loop(window.mlx);
}
/*
linux --> mlx_hook(window.mlx_window, 2, 1L << 0, key_press, &window); 
		  mlx_hook(window.mlx_window, 17, 1L << 7, free_all, &window);
*/

/* 
macos --> mlx_hook(window.mlx_window, 2, 0, key_press, &window);
		  mlx_hook(window.mlx_window, 17, 0, free_all, &window); 
*/
