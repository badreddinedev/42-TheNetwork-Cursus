/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <bamsyah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:12:05 by bamsyah           #+#    #+#             */
/*   Updated: 2023/07/19 20:51:32 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_getrest(char *rest, char *line);
int		ft_strlen(char *str);
char	*ft_strdup(char *rest);
char	*ft_strjoin(char *buffer, char *rest);
int		ft_strchr(char *buffer);
char	*read_file(int fd, char *rest);
char	*get_next_line(int fd);
char	*ft_getline(char *rest);

#endif
