#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpressen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/29 20:56:44 by mpressen          #+#    #+#              #
#    Updated: 2016/04/20 17:46:30 by mpressen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC_PATH = ./

SRC_NAME = main.c ft_parsing.c draw_pic.c hook.c

OBJ_PATH = ./

LIB_PATH = ./libft/

LIB_NAME = libft.a

INC_PATH = ./libft/includes ./includes/

#AUTOMATIC
CFLAGS = -Wall -Wextra -Werror

INC_FLAG = -I

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))
INC_COMPIL = $(addprefix $(INC_FLAG), $(INC_PATH))

all: $(NAME)

$(NAME):
	make -C $(LIB_PATH)
	gcc -c $(CFLAGS) $(SRC) $(INC_COMPIL)
	gcc -o $@ $(OBJ) $(LIB) -lm -lmlx -framework OpenGL -framework AppKit

clean:
	make -C $(LIB_PATH) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -rf $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)

.PHONY: norme re fclean clean all
