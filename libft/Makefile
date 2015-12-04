#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpressen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 21:17:18 by mpressen          #+#    #+#              #
#    Updated: 2015/12/04 22:16:57 by mpressen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# PROJECT VARIABLES
NAME = libft.a

SRC_PATH = ./

SRC_NAME = $(SRC_PART_I) $(SRC_PART_II)

SRC_PART_I = ft_strrchr.c		\
				ft_strdup.c		\
				ft_memccpy.c	\
				ft_memchr.c		\
				ft_strstr.c		\
				ft_atoi.c		\
				ft_memcmp.c		\
				ft_strlcat.c	\
				ft_bzero.c		\
				ft_memcpy.c		\
				ft_strlen.c		\
				ft_isalnum.c	\
				ft_strcat.c		\
				ft_strncat.c	\
				ft_tolower.c	\
				ft_isalpha.c	\
				ft_memmove.c	\
				ft_strchr.c		\
				ft_strncmp.c	\
				ft_toupper.c	\
				ft_isascii.c	\
				ft_memset.c		\
				ft_strnstr.c	\
				ft_strncpy.c	\
				ft_isdigit.c	\
				ft_strcmp.c		\
				ft_isprint.c	\
				ft_strcpy.c

SRC_PART_II = ft_putstr.c		\
				ft_putnbr.c		\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\
				ft_putstr_fd.c	\
				ft_putchar.c	\
				ft_putchar_fd.c	\
				ft_strtrim.c	\
				ft_strsplit.c	\
				ft_strjoin.c	\
				ft_strsub.c		\
				ft_strequ.c		\
				ft_strnequ.c	\
				ft_itoa.c		\
				ft_putendl.c	\
				ft_strclr.c		\
				ft_strnew.c		\
				ft_memalloc.c	\
				ft_memdel.c		\
				ft_strdel.c		\
				ft_striter.c	\
				ft_striteri.c	\
				ft_strmap.c		\
				ft_strmapi.c

INC_PATH = -I./

INC_NAME = libft.h

OBJ_PATH = ./

#STANDART VARIABLES
CC = gcc

CFLAGS = -Wall -Wextra -Werror	#-g -pedantic -ansi

#AUTOMATIC
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC = $(addprefix $(INC_PATH), $(INC_NAME)))

#STANDART RULES
all: $(NAME)

$(OBJ):	#compilation
	gcc -c $(SRC)

$(NAME): $(OBJ)
	ar rc $(NAME) $(INC) $(OBJ)	#linkage
	ranlib $(NAME) #indexage

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

#PERSONAL RULES
norme:
	norminette $(SRC)
	norminette $(INC)

.PHONY: re fclean clean all