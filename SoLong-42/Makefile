# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 17:38:36 by bamsyah           #+#    #+#              #
#    Updated: 2023/11/17 16:18:03 by bamsyah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

SRC =  ft_printf/function.c ft_printf/ft_printf.c  \
	utils/ft_calloc.c utils/ft_split.c utils/ft_strdup2.c utils/invalid_map.c utils/ft_bzero.c \
	utils/ft_strjoin2.c utils/ft_strlcat.c utils/ft_strlcpy.c utils/ft_strlen2.c \
	get_next_line/get_next_line_utils.c get_next_line/get_next_line.c so_long.c \
	check_map/checking_map.c check_map/check_wall.c check_map/checking_components.c \
	draw_map/add_img.c draw_map/ft_window.c check_map/check_all.c check_map/map_dimension.c \
	utils/player_pos.c check_map/flood.c move/key_press.c move/mouvements.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
# macos -->	
	$(CC) $(CFLAGS) $(OBJ) -lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# linux -->
#	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
