#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpressen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 21:17:18 by mpressen          #+#    #+#              #
#    Updated: 2015/12/04 02:58:00 by mpressen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCS = ft_memalloc.c		\
			ft_putendl_fd.c	\
			ft_strdup.c		\
			ft_strrchr.c	\
			ft_memccpy.c	\
			ft_putnbr.c		\
			ft_strequ.c		\
			ft_strsplit.c	\
			ft_memchr.c		\
			ft_putnbr_fd.c	\
			ft_strjoin.c	\
			ft_strstr.c		\
			ft_atoi.c		\
			ft_memcmp.c		\
			ft_putstr.c		\
			ft_strlcat.c	\
			ft_strsub.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_putstr_fd.c	\
			ft_strlen.c		\
			ft_strtrim.c	\
			ft_isalnum.c	\
			ft_memdel.c		\
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
			ft_strclr.c		\
			ft_strncpy.c	\
			ft_isdigit.c	\
			ft_putchar.c	\
			ft_strcmp.c		\
			ft_strnequ.c	\
			ft_isprint.c	\
			ft_putchar_fd.c	\
			ft_strcpy.c		\
			ft_strnew.c		\
			ft_itoa.c		\
			ft_putendl.c	\
			ft_strdel.c		\
			ft_strnstr.c	\
			ft_striter.c	\
			ft_striteri.c	\
			ft_strmap.c		\
			ft_strmapi.c	\

OBJ = 

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(NAME) $(SRCS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

 re: fclean all

.PHONY: re fclean clean all