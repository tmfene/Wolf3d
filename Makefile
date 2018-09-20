# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmfene <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 10:55:03 by tmfene            #+#    #+#              #
#    Updated: 2018/09/04 09:44:33 by tmfene           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = wolf3d.c \
	  reader.c \
	  ft_drawer.c \
	  ft_checker.c \
	  ft_keyboard.c \
	  ray_casting.c

OBJ = $(SRC:.c=.o)

$(NAME) :
	make -C libft/ fclean && make -C libft/
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit -o wolf3d

all : $(NAME)

clean :
	$(RM) $(OBJ)
	make -C libft/ clean

fclean : clean
	$(RM) $(NAME)
	make -C libft/ fclean

re : fclean all
