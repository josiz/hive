# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 11:46:09 by vkurkela          #+#    #+#              #
#    Updated: 2020/01/20 10:53:16 by jzaiedma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./sources/helpers.c ./sources/main.c ./sources/print_block.c ./sources/print_c_s.c \
./sources/print_f.c ./sources/print_i_d.c ./sources/print_o.c ./sources/print_u.c \
./sources/print_x_x.c ./sources/print_f_two.c ./sources/print_i_d_two.c ./sources/print_x_x_two.c \
./sources/helpers_two.c ./sources/helpers_three.c ./sources/main_two.c ./sources/helpers_four.c

OBJ = ./*.o

HEADERS = ./sources/printf.h

LIBFT = libft/*.o

CC = gcc

FLAGS = -Wall -Wextra -Werror -I $(HEADERS)

all: $(NAME)

$(NAME): 
	@${MAKE} -C libft
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ) $(LIBFT)

clean:
	/bin/rm -f $(OBJ)
	rm -f ./obj/*.o
	@${MAKE} -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@${MAKE} -C libft fclean

re: fclean all

print:
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

.PHONY: all print clean fclean re
