#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpressen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/29 20:56:44 by mpressen          #+#    #+#              #
#    Updated: 2016/02/10 21:32:56 by mpressen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC_PATH = ./

SRC_NAME = main.c

OBJ_PATH = ./

LIB_PATH = ./libft/

LIB_NAME = libft.a

INC = ./libft/includes/ ./fdf.h

#AUTOMATIC
CFLAGS = -Wall -Wextra -Werror

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

all: $(NAME)

$(NAME):
	make -C $(LIB_PATH)
	gcc -c $(CFLAGS) $(SRC) -I $(INC)
	gcc -o $@ $(OBJ) $(LIB)

clean:
	make -C $(LIB_PATH) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -rf $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC)

.PHONY: norme re fclean clean all
