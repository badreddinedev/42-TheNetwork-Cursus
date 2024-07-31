# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 18:20:16 by bamsyah           #+#    #+#              #
#    Updated: 2023/12/05 14:00:55 by bamsyah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

SRC = Utils/ft_atoi.c Utils/ft_itoa.c  Utils/ft_putstr_fd.c  Utils/ft_split.c \
	Utils/ft_strjoin.c Utils/ft_strlen.c  Utils/ft_strncmp.c  Utils/ft_strtrim.c \
	Utils/ft_strchr.c Utils/ft_strdup.c Utils/ft_substr.c push_swap.c \
	Utils/ft_putchar_fd.c Utils/ft_bzero.c Utils/ft_calloc.c Utils/ft_strlcat.c \
	Utils/ft_strlcpy.c ft_printf/ft_printf.c ft_printf/ft_putbase.c \
	ft_printf/ft_putchar_len.c ft_printf/ft_putnbr_len.c ft_printf/ft_putunbr_len.c \
	ft_printf/ft_putstr_len.c Rules/operations.c Rules/pb.c Rules/pa.c Rules/sa.c \
	Rules/sb.c Rules/ss.c Rules/push.c Rules/rra.c Rules/rrb.c Rules/rrr.c \
	Rules/rr.c Rules/ra.c Rules/rb.c Utils/ft_sorted.c Utils/ft_sizeliste.c \
	Algorithm/algorithm.c Utils/ft_lastnode.c Algorithm/sort_3.c Algorithm/sort_5.c \
	Utils/ft_min.c Algorithm/sort_up_5.c Algorithm/sorted_push_b.c Utils/ft_find_max.c \
	Algorithm/place_max_in_top.c Utils/ft_push_tab.c Utils/ft_strlen_d.c Utils/ft_error.c \

SRC_B = Bonus/Utils/ft_atoi.c Bonus/Utils/ft_itoa.c  Bonus/Utils/ft_putstr_fd.c  Bonus/Utils/ft_split.c \
	Bonus/Utils/ft_strjoin.c Bonus/Utils/ft_strlen.c  Bonus/Utils/ft_strncmp.c  Bonus/Utils/ft_strtrim.c \
	Bonus/Utils/ft_strchr.c Bonus/Utils/ft_strdup.c Bonus/Utils/ft_substr.c \
	Bonus/Utils/ft_putchar_fd.c Bonus/Utils/ft_bzero.c Bonus/Utils/ft_calloc.c Bonus/Utils/ft_strlcat.c \
	Bonus/Utils/ft_strlcpy.c Bonus/ft_printf/ft_printf.c Bonus/ft_printf/ft_putbase.c \
	Bonus/ft_printf/ft_putchar_len.c Bonus/ft_printf/ft_putnbr_len.c Bonus/ft_printf/ft_putunbr_len.c \
	Bonus/ft_printf/ft_putstr_len.c Bonus/Rules/operations.c Bonus/Rules/pb.c Bonus/Rules/pa.c Bonus/Rules/sa.c \
	Bonus/Rules/sb.c Bonus/Rules/ss.c Bonus/Rules/push.c Bonus/Rules/rra.c Bonus/Rules/rrb.c Bonus/Rules/rrr.c \
	Bonus/Rules/rr.c Bonus/Rules/ra.c Bonus/Rules/rb.c Bonus/Utils/ft_sorted.c Bonus/Utils/ft_sizeliste.c \
	Bonus/Algorithm/algorithm.c Bonus/Utils/ft_lastnode.c Bonus/Algorithm/sort_3.c Bonus/Algorithm/sort_5.c \
	Bonus/Utils/ft_min.c Bonus/Algorithm/sort_up_5.c Bonus/Algorithm/sorted_push_b.c Bonus/Utils/ft_find_max.c \
	Bonus/Algorithm/place_max_in_top.c Bonus/Utils/ft_push_tab.c Bonus/Utils/ft_strcmp.c Bonus/Utils/ft_strlen_d.c \
	Bonus/checker.c Bonus/Get_next_line/get_next_line.c Bonus/Get_next_line/get_next_line_utils.c Bonus/Utils/ft_error.c

OBJ = $(SRC:.c=.o)

OBJS_B = $(SRC_B:.c=.o)

all: Header $(NAME)

bonus: Header $(NAME_B)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME_B): $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_B)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJS_B)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_B)

re: fclean all

Header:
	@echo "██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗"
	@echo "██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗"
	@echo "██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝"
	@echo "██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝"
	@echo "██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║"
	@echo "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝"