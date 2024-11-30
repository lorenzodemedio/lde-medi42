/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:53:12 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/20 18:02:18 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
		return (1);
}
/*
#include <stdio.h>
int main()
{
	printf("is number 7 prime? -> %d", ft_is_prime(7));
	printf("is number 31 prime? -> %d", ft_is_prime(31));
	printf("is number 12 prime? -> %d", ft_is_prime(12));
}*/
