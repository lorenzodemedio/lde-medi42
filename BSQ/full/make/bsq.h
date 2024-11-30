/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:10:41 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/26 17:14:02 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

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

void	print_grid(t_map_d *map_data);
void	fill_grid(char	*buffer, t_map_d	*map_data, int i, int len);
size_t	grid_arr_len(char	*buffer, t_map_d *map_data, int i);
void	write_bsq_to_grid(t_map_d	*map_data);

int		is_valid_char(t_map_d	*map_data, char c);
int		is_digit(char c);
int		is_printable(char c);
int		is_edge_case(t_map_d	*map_data);

int		validate_first_line(char *buffer, t_map_d *map_data, int *i);
int		lines_validation(char	*buffer, int i, t_map_d	*map_data);
int		validate_grid(char	*buffer, t_map_d	*map_data, int	*i);
int		parse_input(char	*buffer, t_map_d	*map_data);

int		read_file(char	*file_name, char **buffer);
ssize_t	get_file_size(char	*file_name);
int		first_line_len(char	*buffer);
void	init_struct(t_map_d *map_data);

int		process_map(char	*file_name);
int		find_bsq(t_map_d	*map_data, int line, int column);
int		find_square(t_map_d *map_data, int line, int column, int size);
void	try_all_cells(t_map_d	*map_data);

#endif