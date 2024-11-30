/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 02:49:30 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/10 03:34:40 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap_int(int	*a, int	*b);

void	ft_sort_int_tab(int	*tab, int size)
{
	int	i;
	int	is_sort;

	is_sort = 1;
	while (is_sort != 0)
	{
		i = 0;
		is_sort = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap_int(&tab[i], &tab[i + 1]);
				is_sort++;
			}
			i++;
		}
	}
}

void	ft_swap_int(int	*a, int	*b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
