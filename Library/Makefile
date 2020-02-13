# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 15:07:35 by jzaiedma          #+#    #+#              #
#    Updated: 2020/01/22 12:37:27 by jzaiedma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = 	./basic/ft_atoi.c \
		./basic/ft_bzero.c \
		./basic/ft_isalnum.c \
		./basic/ft_isalpha.c \
		./basic/ft_isascii.c \
		./basic/ft_isdigit.c \
		./basic/ft_islower.c \
		./basic/ft_isprint.c \
		./basic/ft_isspace.c \
		./basic/ft_isupper.c \
		./basic/ft_itoa.c \
		./basic/ft_long_itoa.c \
		./basic/ft_memalloc.c \
		./basic/ft_memccpy.c \
		./basic/ft_memchr.c \
		./basic/ft_memcmp.c \
		./basic/ft_memcpy.c \
		./basic/ft_memmove.c \
		./basic/ft_memset.c \
		./basic/ft_putchar_fd.c \
		./basic/ft_putchar.c \
		./basic/ft_putendl_fd.c \
		./basic/ft_putendl.c \
		./basic/ft_putnbr_fd.c \
		./basic/ft_putnbr.c \
		./basic/ft_putllnbr.c \
		./basic/ft_putstr_fd.c \
		./basic/ft_putstr.c \
		./basic/ft_putnstr.c \
		./basic/ft_strcat.c \
		./basic/ft_strchr.c \
		./basic/ft_strrchr.c \
		./basic/ft_strmap.c \
		./basic/ft_strmapi.c \
		./basic/ft_strncat.c \
		./basic/ft_strclr.c \
		./basic/ft_strcmp.c \
		./basic/ft_strncmp.c \
		./basic/ft_strcpy.c \
		./basic/ft_strncpy.c \
		./basic/ft_strdup.c \
		./basic/ft_strequ.c \
		./basic/ft_striter.c \
		./basic/ft_striteri.c \
		./basic/ft_strjoin.c \
		./basic/ft_strlcat.c \
		./basic/ft_strlen.c \
		./basic/ft_strnequ.c \
		./basic/ft_strnew.c \
		./basic/ft_strnstr.c \
		./basic/ft_strstr.c \
		./basic/ft_strsub.c \
		./basic/ft_strtrim.c \
		./basic/ft_tolower.c \
		./basic/ft_toupper.c \
		./basic/ft_strdel.c \
		./basic/ft_memdel.c \
		./basic/ft_strsplit.c \
		./GNL/get_next_line.c \
		./printf/helpers.c ./printf/main.c ./printf/print_block.c \
		./printf/print_c_s.c ./printf/print_f.c ./printf/print_i_d.c \
		./printf/print_o.c ./printf/print_x_x.c ./printf/print_f_two.c \
		./printf/print_i_d_two.c ./printf/print_x_x_two.c ./printf/helpers_two.c \
		./printf/helpers_three.c ./printf/helpers_four.c ./printf/main_two.c \

HEADERS = ./headers/

OBJ = ./*.o

all: $(NAME)

$(NAME):
		gcc -c -Wall -Wextra -Werror -I$(HEADERS) -c $(SRC)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
