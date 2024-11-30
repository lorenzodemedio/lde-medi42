/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frankenmain2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:02:23 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/26 02:39:21 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_biggest_square
{
	int	line;
	int	column;
	int	size;
}	t_bsq;

typedef struct s_map_data
{
	int		lines_n;
	int		cols_n;
	char	empty_char;
	char	obst_char;
	char	full_char;
	char	*grid;
	t_bsq	bsq;
}	t_map_d;

void	init_struct(t_map_d *map_data);
void	print_grid(t_map_d *map_data);
void	fill_grid(char	*buffer, t_map_d	*map_data, int i, int len);
size_t	grid_arr_len(char	*buffer, t_map_d *map_data, int i);
int		is_valid_char(t_map_d	*map_data, char c);
int		is_digit(char c);
int		is_printable(char c);
int		validate_first_line(char *buffer, t_map_d *map_data, int *i);
int		lines_validation(char	*buffer, int i, t_map_d	*map_data);
int		validate_grid(char	*buffer, t_map_d	*map_data, int	*i);
int		read_file(char	*file_name, char **buffer);
int		parse_input(char	*buffer, t_map_d	*map_data);
int		process_map(char	*file_name);
ssize_t	get_file_size(char	*file_name);
int		find_bsq(t_map_d	*map_data, int line, int column);
void	try_all_cells(t_map_d	*map_data);
int		find_square(t_map_d *map_data, int line, int column, int size);
void	write_bsq_to_grid(t_map_d	*map_data);
int		first_line_len(char	*buffer);

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		write(2, "Launch program with n arguments (map files names.)\n", 51);
		return (1);
	}
	while (i < argc)
	{
		if (!process_map(argv[i]))
		{
			write(2, "map error\n", 10);
			return (1);
		}
		if (i != argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}

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
	return (1);
}

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
