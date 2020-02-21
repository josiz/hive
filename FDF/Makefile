# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 11:46:09 by jzaiedma          #+#    #+#              #
#    Updated: 2020/02/20 12:09:20 by jzaiedma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = 	./sources/fdf_main.c ./sources/draw_line.c ./sources/make_iso.c \
		./sources/assign_linepoints.c ./sources/commands.c \
		./sources/adjust_array.c ./sources/mouse.c \
		./sources/window.c ./sources/commands_two.c \
		./sources/rotate.c ./sources/color.c ./sources/make_empty.c \
		./sources/draw_projection.c

OBJ = ./*.o

INCL = -I ./header/fdf.h

LIB = -L libft -lft -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft
	$(CC) $(FLAGS) $(INCL) $(SRC) $(LIB) -o $(NAME)

libftmake:
	@make -C libft

clean:
	@rm -f $(OBJS)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re without



