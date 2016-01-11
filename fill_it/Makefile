#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpressen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/29 20:56:44 by mpressen          #+#    #+#              #
#    Updated: 2016/01/11 23:36:14 by mpressen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC_PATH = ./

SRC_NAME = $(SRC1)

SRC1 = main.c		\
		check.c

INC_PATH = ./

INC_NAME = fillit.h	\
			libft.h

LIB_PATH = ~/Desktop/

LIB_NAME = libft.a

OBJ_PATH = ./

#AUTOMATIC
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
INC = $(addprefix $(INC_PATH), $(INC_NAME))
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIB)


clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all
