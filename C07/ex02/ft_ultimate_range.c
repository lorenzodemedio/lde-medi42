/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utimate_range.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 02:35:08 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/21 02:35:11 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_range(int	*range, int min, int max);

int	ft_ultimate_range(int	**range, int min, int max)
{
	int		i;
	size_t	size;

	size = 0;
	i = min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	while (i < max)
	{
		size++;
		i++;
	}
	*range = (int *)malloc((size) * sizeof(int));
	if (*range == NULL)
		return (-1);
	ft_range(*range, min, max);
	return (size);
}

void	ft_range(int	*range, int min, int max)
{
	int		i;

	i = 0;
	while (min < max)
	{
		range[i] = min;
		i++;
		min++;
	}
}
