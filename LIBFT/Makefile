# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 15:07:35 by jzaiedma          #+#    #+#              #
#    Updated: 2019/10/29 16:27:58 by jzaiedma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)
		gcc $(FLAGS) -c ft_atoi.c -I libft.h
		gcc $(FLAGS) -c ft_bzero.c -I libft.h
		gcc $(FLAGS) -c ft_isalnum.c -I libft.h
		gcc $(FLAGS) -c ft_isalpha.c -I libft.h
		gcc $(FLAGS) -c ft_isascii.c -I libft.h
		gcc $(FLAGS) -c ft_isdigit.c -I libft.h
		gcc $(FLAGS) -c ft_islower.c -I libft.h
		gcc $(FLAGS) -c ft_isprint.c -I libft.h
		gcc $(FLAGS) -c ft_isspace.c -I libft.h
		gcc $(FLAGS) -c ft_isupper.c -I libft.h
		gcc $(FLAGS) -c ft_itoa.c -I libft.h
		gcc $(FLAGS) -c ft_memalloc.c -I libft.h
		gcc $(FLAGS) -c ft_memccpy.c -I libft.h
		gcc $(FLAGS) -c ft_memchr.c -I libft.h
		gcc $(FLAGS) -c ft_memcmp.c -I libft.h
		gcc $(FLAGS) -c ft_memcpy.c -I libft.h
		gcc $(FLAGS) -c ft_memmove.c -I libft.h
		gcc $(FLAGS) -c ft_memset.c -I libft.h
		gcc $(FLAGS) -c ft_putchar_fd.c -I libft.h
		gcc $(FLAGS) -c ft_putchar.c -I libft.h
		gcc $(FLAGS) -c ft_putendl_fd.c -I libft.h
		gcc $(FLAGS) -c ft_putendl.c -I libft.h
		gcc $(FLAGS) -c ft_putnbr_fd.c -I libft.h
		gcc $(FLAGS) -c ft_putnbr.c -I libft.h
		gcc $(FLAGS) -c ft_putstr_fd.c -I libft.h
		gcc $(FLAGS) -c ft_putstr.c -I libft.h
		gcc $(FLAGS) -c ft_strcat.c -I libft.h
		gcc $(FLAGS) -c ft_strchr.c -I libft.h
		gcc $(FLAGS) -c ft_strrchr.c -I libft.h
		gcc $(FLAGS) -c ft_strmap.c -I libft.h
		gcc $(FLAGS) -c ft_strmapi.c -I libft.h
		gcc $(FLAGS) -c ft_strncat.c -I libft.h
		gcc $(FLAGS) -c ft_strclr.c -I libft.h
		gcc $(FLAGS) -c ft_strcmp.c -I libft.h
		gcc $(FLAGS) -c ft_strncmp.c -I libft.h
		gcc $(FLAGS) -c ft_strcpy.c -I libft.h
		gcc $(FLAGS) -c ft_strncpy.c -I libft.h
		gcc $(FLAGS) -c ft_strdup.c -I libft.h
		gcc $(FLAGS) -c ft_strequ.c -I libft.h
		gcc $(FLAGS) -c ft_striter.c -I libft.h
		gcc $(FLAGS) -c ft_striteri.c -I libft.h
		gcc $(FLAGS) -c ft_strjoin.c -I libft.h
		gcc $(FLAGS) -c ft_strlcat.c -I libft.h
		gcc $(FLAGS) -c ft_strlen.c -I libft.h
		gcc $(FLAGS) -c ft_strnequ.c -I libft.h
		gcc $(FLAGS) -c ft_strnew.c -I libft.h
		gcc $(FLAGS) -c ft_strnstr.c -I libft.h
		gcc $(FLAGS) -c ft_strstr.c -I libft.h
		gcc $(FLAGS) -c ft_strsub.c -I libft.h
		gcc $(FLAGS) -c ft_strtrim.c -I libft.h
		gcc $(FLAGS) -c ft_tolower.c -I libft.h
		gcc $(FLAGS) -c ft_toupper.c -I libft.h
		gcc $(FLAGS) -c ft_strdel.c -I libft.h
		gcc $(FLAGS) -c ft_memdel.c -I libft.h
		gcc $(FLAGS) -c ft_strsplit.c -I libft.h
		ar rc $(NAME) *.o

$(NAME):	
		gcc $(FLAGS) -c ft_atoi.c -I libft.h

clean:
		rm -f *.o

fclean: clean
		rm -f libft.a

re: fclean all

.PHONY: clean fclean all re
