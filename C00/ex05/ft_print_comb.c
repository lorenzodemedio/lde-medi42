/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:38:37 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/15 02:55:28 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_digit(int	n);

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				ft_put_digit(i);
				ft_put_digit(j);
				ft_put_digit(k);
				if (i == 7 && j == 8 && k == 9)
					return ;
				else
				{
					write(1, ", ", 2);
				}
				k++;
			}
			j++;
		}
		i++;
	}	
}
void	ft_put_digit(int	n)
{
	char	digit;

	digit = '0' + n;
	write(1, &digit, 1);
}
