#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpressen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/29 20:56:44 by mpressen          #+#    #+#              #
#    Updated: 2015/12/29 21:51:12 by mpressen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_display_file

SRC_PATH = ./

SRC_NAME = $(SRC1)

SRC1 = main.c		\

OBJ_PATH = ./

#AUTOMATIC
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC)
	gcc -o $(NAME) $(OBJ)


clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

.PHONY: fclean clean all