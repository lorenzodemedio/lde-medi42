# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 17:31:41 by lde-medi          #+#    #+#              #
#    Updated: 2024/11/26 17:31:46 by lde-medi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: libft.a

libft.a: ft_putstr.o ft_swap.o ft_putchar.o ft_strlen.o ft_strcmp.o
	ar rcs libft.a ft_putstr.o ft_swap.o ft_putchar.o ft_strlen.o ft_strcmp.o

ft_putstr.o: ft_putstr.c
	gcc -Wall -Werror -Wextra -c ft_putstr.c -o ft_putstr.o

ft_swap.o: ft_swap.c
	gcc -Wall -Werror -Wextra -c ft_swap.c -o ft_swap.o

ft_putchar.o: ft_putchar.c
	gcc -Wall -Werror -Wextra -c ft_putchar.c -o ft_putchar.o

ft_strlen.o: ft_strlen.c
	gcc -Wall -Werror -Wextra -c ft_strlen.c -o ft_strlen.o

ft_strcmp.o: ft_strcmp.c
	gcc -Wall -Werror -Wextra -c ft_strcmp.c -o ft_strcmp.o

clean:
	rm -f ft_putstr.o ft_swap.o ft_putchar.o ft_strlen.o ft_strcmp.o

fclean: clean
	rm -f libft.a

re: fclean all