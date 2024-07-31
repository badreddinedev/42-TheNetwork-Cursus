# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamsyah <bamsyah@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 06:11:13 by bamsyah           #+#    #+#              #
#    Updated: 2023/08/24 07:54:12 by bamsyah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

CC = clang
CFLAGS = -Wall -Wextra -Werror

CLIENT-FILE = client.c
SERVER-FILE = server.c

CLIENT-OBJ = $(CLIENT-FILE:.c=.o)
SERVER-OBJ = $(SERVER-FILE:.c=.o)

RM = rm -rf

all: $(CLIENT) $(SERVER)

$(CLIENT):$(CLIENT-OBJ)
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT-OBJ) -Lft_printf -lftprintf
$(SERVER):$(SERVER-OBJ)
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER-OBJ) -Lft_printf -lftprintf

clean:
	$(RM) $(CLIENT-OBJ) $(SERVER-OBJ)

fclean:clean
	$(RM) $(CLIENT) $(SERVER)

re:fclean all
