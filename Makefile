# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 04:47:42 by aennaki           #+#    #+#              #
#    Updated: 2023/03/25 13:37:37 by aennaki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME_SRV = server
NAME_CLT = client
NAME_SRV_B = server_bonus
NAME_CLT_B = client_bonus
CFLAGS = -Wall -Werror -Wextra
SRC_SRV = libft.c server.c
SRC_CLT = libft.c client.c
SRC_BNS_SRC = libft.c server_bonus.c
SRC_BNS_CLT = libft.c client_bonus.c
OBJ_SRV = $(SRC_SRV:.c=.o)
OBJ_CLT = $(SRC_CLT:.c=.o)
OBJ_BNS_SRV = $(SRC_BNS_SRC:.c=.o)
OBJ_BNS_CLT = $(SRC_BNS_CLT:.c=.o)

RM = rm -rf

all : $(NAME_SRV)

%.o : %.c libft.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME_SRV) : $(OBJ_SRV) $(OBJ_CLT)
	$(CC) $(CFLAGS) $(OBJ_SRV) -o $(NAME_SRV)
	$(CC) $(CFLAGS) $(OBJ_CLT) -o $(NAME_CLT)

bonus : $(NAME_SRV_B) 

$(NAME_SRV_B) : $(OBJ_BNS_SRV) $(OBJ_BNS_CLT)
	$(CC) $(CFLAGS) $(OBJ_BNS_SRV) -o $(NAME_SRV_B)
	$(CC) $(CFLAGS) $(OBJ_BNS_CLT) -o $(NAME_CLT_B)

clean :
	$(RM) $(OBJ_SRV) $(OBJ_CLT) $(OBJ_BNS_SRV) $(OBJ_BNS_CLT)

fclean : clean
	$(RM) $(NAME_SRV) $(NAME_CLT) $(NAME_SRV_B) $(NAME_CLT_B)

re : fclean all

.PHONY: all bonus clean fclean re
