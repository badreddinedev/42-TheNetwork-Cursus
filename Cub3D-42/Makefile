# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 13:09:52 by bamsyah           #+#    #+#              #
#    Updated: 2024/03/16 19:53:57 by bamsyah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
FRAMEWORK =  -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

SRC = cub3d.c Utils/libft/ft_calloc.c  Utils/libft/ft_isdigit.c Utils/libft/ft_strchr.c  Utils/libft/ft_strlcpy.c \
	Utils/libft/ft_strrchr.c Utils/libft/ft_strdup.c  Utils/libft/ft_strlen.c  Utils/libft/ft_strtrim.c \
	Utils/libft/ft_atoi.c Utils/libft/ft_strjoin.c Utils/libft/ft_strncmp.c Utils/libft/ft_substr.c \
	Utils/libft/ft_bzero.c Utils/libft/ft_strlcat.c Utils/libft/ft_strnstr.c Utils/libft/ft_split.c \
	Utils/libft/ft_putchar_fd.c Utils/libft/ft_putstr_fd.c  Utils/libft/ft_putendl_fd.c \
	Utils/get_next_line/get_next_line.c Utils/get_next_line/get_next_line_utils.c \
	$(wildcard ./Mandatory/Rycasting/*.c) $(wildcard ./Mandatory/Parsing/*.c) 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FRAMEWORK) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all