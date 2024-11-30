/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:28:41 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/26 17:14:59 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_valid_char(t_map_d	*map_data, char c)
{
	return (c == map_data->empty_char || c == map_data->full_char
		|| c == map_data->obst_char);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_printable(char c)
{
	return ((unsigned char)c >= 33 && (unsigned char)c <= 127);
}

int	is_edge_case(t_map_d	*map_data)
{
	int		i;
	int		empty_chars;

	i = 0;
	empty_chars = 0;
	while (map_data->grid[i])
	{
		if (map_data->grid[i] == map_data->empty_char)
			empty_chars++;
		i++;
	}
	if (!empty_chars)
		return (1);
	else
		return (0);
}
