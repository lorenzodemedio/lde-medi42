/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:41:16 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/15 02:29:30 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_int(int n);
void	ft_print_dd(int n);

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
				ft_print_dd(a);
				write(1, " ", 1);
				ft_print_dd(b);
				if (a == 98 && b == 99)
					return ;
				else
					write(1, ", ", 2);
			b++;
		}
		a++;
	}
}

void	ft_print_int(int n)
{
	char	out;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_print_int(n / 10);
	}
	out = (n % 10) + '0';
	write(1, &out, 1);
}

void	ft_print_dd(int n)
{
	if (n < 10)
	{
		write(1, "0", 1);
		ft_print_int(n);
	}
	else
		ft_print_int(n);
}
