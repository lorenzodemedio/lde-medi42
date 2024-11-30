# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 05:35:19 by lde-medi          #+#    #+#              #
#    Updated: 2024/11/28 03:32:59 by lde-medi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc -Wall -Werror -Wextra -c ft_putstr.c ft_swap.c ft_putchar.c ft_strlen.c ft_strcmp.c
ar rcs libft.a ft_putstr.o ft_swap.o ft_putchar.o ft_strlen.o ft_strcmp.o
ranlib libft.a
rm -f *.o