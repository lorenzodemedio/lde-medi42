/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:23:43 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/26 17:13:23 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	validate_first_line(char *buffer, t_map_d *map_data, int *i)
{
	int	len;

	len = first_line_len(buffer);
	map_data->lines_n = 0;
	while (buffer[*i])
	{
		if ((map_data->lines_n == 0 && !is_digit(buffer[*i])))
			return (0);
		if (is_digit(buffer[*i]) && *i < len - 3)
			map_data->lines_n = (map_data->lines_n * 10) + (buffer[*i] - '0');
		else if (is_printable(buffer[*i]) && map_data->empty_char == '\0')
			map_data->empty_char = buffer[*i];
		else if (is_printable(buffer[*i]) && map_data->obst_char == '\0')
			map_data->obst_char = buffer[*i];
		else if (is_printable(buffer[*i]) && map_data->full_char == '\0')
			map_data->full_char = buffer[*i];
		else if (buffer[*i] == '\n')
		{
			return (++(*i), 1);
		}
		else
			return (0);
		(*i)++;
	}
	return (0);
}

int	lines_validation(char	*buffer, int i, t_map_d	*map_data)
{
	int	ln_skips;
	int	curr_len;

	ln_skips = 0;
	curr_len = 0;
	while (buffer[i])
	{
		if (buffer[i++] == '\n')
		{
			if (!ln_skips++)
				map_data->cols_n = curr_len;
			else if (curr_len != map_data->cols_n)
				return (0);
			curr_len = 0;
		}
		else
			curr_len++;
	}
	if (ln_skips != map_data->lines_n)
		return (0);
	else
		return (1);
}

int	validate_grid(char	*buffer, t_map_d	*map_data, int	*i)
{
	size_t	len;

	if (!lines_validation(buffer, *i, map_data))
		return (0);
	len = grid_arr_len(buffer, map_data, *i);
	if (!len)
		return (0);
	map_data->grid = malloc((len * sizeof(char)) + 1);
	fill_grid(buffer, map_data, *i, (int)len);
	if (is_edge_case(map_data))
		return (0);
	else
		return (1);
}

int	parse_input(char	*buffer, t_map_d	*map_data)
{
	int		i;

	i = 0;
	if (!validate_first_line(buffer, map_data, &i))
		return (0);
	else if (!validate_grid(buffer, map_data, &i))
		return (0);
	else
		return (1);
}
