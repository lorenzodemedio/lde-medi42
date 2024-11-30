/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:31:44 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/26 02:33:19 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	read_file(char	*file_name, char	**buffer)
{
	int		file;
	ssize_t	file_size;
	ssize_t	bytes_read;

	file = 0;
	file_size = get_file_size(file_name);
	*buffer = malloc((file_size + 1) * sizeof(char));
	if (!*buffer)
		return (0);
	file = open(file_name, O_RDONLY);
	if (file < 0)
	{
		free(*buffer);
		return (0);
	}
	bytes_read = read(file, *buffer, file_size);
	(*buffer)[file_size] = '\0';
	if (bytes_read != file_size)
	{
		free(*buffer);
		return (0);
	}
	return (1);
}

ssize_t	get_file_size(char	*file_name)
{
	int		file;
	ssize_t	size;
	char	buf;

	size = 0;
	file = open(file_name, O_RDONLY);
	if (file < 0)
		return (0);
	while (read(file, &buf, 1) == 1)
		size++;
	close(file);
	return (size);
}

int	first_line_len(char	*buffer)
{
	int	len;

	len = 0;
	while (buffer[len])
	{
		if (buffer[len] == '\n')
			break ;
		len++;
	}
	return (len);
}

void	init_struct(t_map_d *map_data)
{
	map_data->lines_n = 0;
	map_data->cols_n = 0;
	map_data->empty_char = '\0';
	map_data->obst_char = '\0';
	map_data->full_char = '\0';
	map_data->grid = NULL;
	map_data->bsq.line = 0;
	map_data->bsq.column = 0;
	map_data->bsq.size = 0;
}
