# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 17:16:45 by jzaiedma          #+#    #+#              #
#    Updated: 2019/10/25 18:26:11 by jzaiedma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

ODIR = ./srcs/

HDIR = ./includes/

all:
		gcc -c $(ODIR)ft_putchar.c -I $(HDIR)
		gcc -c $(ODIR)ft_putstr.c -I $(HDIR)
		gcc -c $(ODIR)ft_strcmp.c -I $(HDIR)
		gcc -c $(ODIR)ft_strlen.c -I $(HDIR)
		gcc -c $(ODIR)ft_swap.c -I $(HDIR)
		ar rc $(NAME) ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

clean:
		rm -f ft_putchar.o
		rm -f ft_putstr.o
		rm -f ft_strcmp.o
		rm -f ft_strlen.o
		rm -f ft_swap.o

fclean: clean
		rm -f $(NAME)

re: fclean all
