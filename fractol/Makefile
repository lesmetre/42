#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpressen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/29 20:56:44 by mpressen          #+#    #+#              #
#    Updated: 2016/06/03 12:54:21 by mpressen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

SRC_PATH = ./

SRC_NAME = main.c draw_pic.c hook.c julia.c julia2.c mandelbrot.c burning_ship.c mandelbar.c multibar.c multibrot.c logbrot.c mpressen.c mpressen2.c sierpinski_carpet.c sierpinski_triangle.c draw_legend.c bonus.c bonus2.c

OBJ_PATH = ./

LIB_PATH = ./libft/

LIB_PATH2 = ./mlx/

LIB_NAME = libft.a

LIB_NAME2 = libmlx.a

INC_PATH = ./libft/includes ./includes/

#AUTOMATIC
CFLAGS = -Wall -Wextra -Werror

INC_FLAG = -I

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))
LIB2 = $(addprefix $(LIB_PATH2), $(LIB_NAME2))
INC_COMPIL = $(addprefix $(INC_FLAG), $(INC_PATH))

all: $(NAME)

$(NAME):
	make -C $(LIB_PATH)
	make -C $(LIB_PATH2)
	gcc -c $(CFLAGS) $(SRC) $(INC_COMPIL)
	gcc -o $@ $(OBJ) $(LIB) $(LIB2) -framework OpenGL -framework AppKit

clean:
	make -C $(LIB_PATH) clean
	make -C $(LIB_PATH2) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -rf $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)

.PHONY: norme re fclean clean all
