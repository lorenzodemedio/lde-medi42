/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gridops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:26:27 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/26 02:29:51 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_grid(t_map_d *map_data)
{
	int	i;

	i = 0;
	while (map_data->grid[i])
	{
		if (i % map_data->cols_n == 0 && i != 0)
			write(1, "\n", 1);
		write(1, &map_data->grid[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	fill_grid(char	*buffer, t_map_d	*map_data, int i, int len)
{
	int	j;

	j = 0;
	while (buffer[i] && j < len)
	{
		if (buffer[i] == '\n')
			i++;
		else
		{
			map_data->grid[j] = buffer[i];
			j++;
			i++;
		}
	}
	map_data->grid[j] = '\0';
}

size_t	grid_arr_len(char	*buffer, t_map_d *map_data, int i)
{
	size_t	len;

	len = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			i++;
		else if (is_valid_char(map_data, buffer[i]))
		{
			len++;
			i++;
		}
		else
			return (0);
	}
	return (len);
}

void	write_bsq_to_grid(t_map_d	*map)
{
	int	i;
	int	j;
	int	coords;

	i = 0;
	while (i < map->bsq.size)
	{
		j = 0;
		while (j < map->bsq.size)
		{
			coords = (map->bsq.line + i) * map->cols_n +(map->bsq.column + j);
			map->grid[coords] = map->full_char;
			j++;
		}
		i++;
	}
}
