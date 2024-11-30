/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:33:52 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/26 02:35:31 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	process_map(char	*file_name)
{
	char	*buffer;
	t_map_d	map_data;

	buffer = NULL;
	init_struct(&map_data);
	if (!read_file(file_name, &buffer) || !parse_input(buffer, &map_data))
		return (0);
	free(buffer);
	try_all_cells(&map_data);
	write_bsq_to_grid(&map_data);
	print_grid(&map_data);
	free(map_data.grid);
	return (1);
}

int	find_bsq(t_map_d	*map_data, int line, int column)
{
	int	size;

	size = 1;
	while (line + size - 1 < map_data->lines_n
		&& column + size -1 < map_data->cols_n)
	{
		if (find_square(map_data, line, column, size - 1))
		{
			if (size > map_data->bsq.size)
			{
				map_data->bsq.line = line;
				map_data->bsq.column = column;
				map_data->bsq.size = size;
			}
		}
		else
			break ;
		size++;
	}
	return (1);
}

int	find_square(t_map_d *map_data, int line, int column, int size)
{
	int	i;
	int	j;
	int	coords;

	i = 0;
	while (i <= size)
	{
		j = 0;
		while (j <= size)
		{
			coords = (line + i) * map_data->cols_n + (column + j);
			if ((map_data->grid[coords] == map_data->obst_char)
				|| (!is_valid_char(map_data, map_data->grid[coords])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	try_all_cells(t_map_d	*map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->lines_n)
	{
		j = 0;
		while (j < map_data->cols_n)
		{
			find_bsq(map_data, i, j);
			j++;
		}
		i++;
	}
}
