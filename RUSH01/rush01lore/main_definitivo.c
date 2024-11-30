/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_definitivo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:24:29 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/17 06:27:09 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* AQUI DENTRO HAY TODO LO QUE HACE FALTA PARA EL RUSH TENEMOS QUE REPARTIR LAS
	FUNCIONES EN VARIOS FILES .C Y EN UN .H (COMO HICE EN UN PRINCIPIO) PARA
	QUE ESTO PASE LA NORMINETTE.. he intentado "mantenerlo" sencillo con un solo
	file main, como podeis ver, todo en un main es un caos que no se entiende una
	mierda, pero bueno, aqui esta y funciona. Si se os ocurren nombres mejores
	para que las variables se expliquen mejor o como llamar los files de los 
	varios componentes y que funciones iran en que file (ejemplo el file 
	validation.c de la que ya que queremos ir de programadores llamaremos la 
	v0.0.1-alpha que contenia todas las funciones de logica de validacion,
	en esta v.0.1.0-beta no tenemos nada de orden. nos falta esto para llegar
	a v1.0.0! confio en vosotros. 											
																			*/

#include <unistd.h>
#include <stdio.h>

typedef struct s_views_list
{
	int	col_up[4];
	int	col_down[4];
	int	row_left[4];
	int	row_right[4];
}	t_views;

void	put_digit(int n);
void	print_grid(int grid[4][4]);
void	init_grid(int grid[4][4]);
int		is_even(int n);
int		is_char_digit(char c);
int		ft_strlen(char	*str);
int		is_input_valid(int argc, char	*input);
void	remove_whitespace(char	*str);
void	parse_input(char	*input, t_views *views);
int		calc_visible(int line[]);
int		is_puzzle_solved(int grid[4][4], t_views views);
int		find_solution(int grid[4][4], t_views views, int row, int column);
int		is_number_repeated(int grid[4][4], int row, int column, int number);
void	set_next_position(int *row, int *column);

int	main(int argc, char	*argv[])
{
	int		grid[4][4];
	t_views	views;

	if (!is_input_valid(argc, argv[1]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	parse_input(argv[1], &views);
	init_grid(grid);
	if (find_solution(grid, views, 0, 0))
		print_grid(grid);
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

void	print_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			put_digit(grid[i][j]);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	put_digit(int n)
{
	char	c;

	c = '0';
	if (n >= 0 && n <= 9)
	{
		c += n;
		write(1, &c, 1);
	}
}

// rellena la grid con 0s
void	init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	is_even(int n)
{
	return (n % 2 == 0);
}

int	is_char_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strlen(char	*str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

// comprueba que el programa se haya lanzado con el arg correcto
int	is_input_valid(int argc, char	*input)
{
	int	i;
	int	input_len;

	i = 0;
	if (argc != 2)
		return (0);
	input_len = ft_strlen(input);
	while (input[i])
	{
		if ((is_even(i) && !is_char_digit(input[i]))
			|| (!is_even(i) && input[i] != ' ')
			|| input_len != 31)
			return (0);
		i++;
	}
	return (1);
}

void	remove_whitespace(char	*str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
}

// transforma el input de un string a ints y los distribuye en el struct views
void	parse_input(char	*input, t_views *views)
{
	int	i;

	i = 0;
	remove_whitespace(input);
	while (input[i])
	{
		if (i <= 3)
			views->col_up[i] = input[i] - '0';
		if (i >= 4 && i <= 7)
			views->col_down[i - 4] = input[i] - '0';
		if (i >= 8 && i <= 11)
			views->row_left[i - 8] = input[i] - '0';
		if (i >= 12)
			views->row_right[i - 12] = input[i] - '0';
		i++;
	}
}

int	calc_visible(int line[])
{
	int	i;
	int	highest_found;
	int	count;

	i = 0;
	highest_found = 0;
	count = 0;
	while (i <= 3)
	{
		if (line[i] > highest_found)
		{
			count++;
			highest_found = line[i];
		}
		i++;
	}
	return (count);
}

int	is_puzzle_solved(int grid[4][4], t_views views)
{
	int		i;
	int		j;
	t_views	lines;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			lines.col_up[j] = grid[j][i];
			lines.col_down[j] = grid[3 - j][i];
			lines.row_left[j] = grid[i][j];
			lines.row_right[j] = grid[i][3 - j];
			j++;
		}
		if (calc_visible(lines.col_up) != views.col_up[i]
			|| calc_visible(lines.col_down) != views.col_down[i]
			|| calc_visible(lines.row_left) != views.row_left[i]
			|| calc_visible(lines.row_right) != views.row_right[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_number_repeated(int grid[4][4], int row, int column, int number)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i != column && grid[row][i] == number)
			return (1);
		if (i != row && grid[row][column] == number)
			return (1);
		i++;
	}
	return (0);
}

void	set_next_position(int *row, int *column)
{
	if (*column == 3)
	{
		*row += 1;
		*column = 0;
	}
	else
		*column += 1;
}

int	find_solution(int grid[4][4], t_views views, int row, int column)
{
	int	number;
	int	next_row;
	int	next_column;

	number = 1;
	if (row >= 4)
		return (is_puzzle_solved(grid, views));
	while (number <= 4)
	{
		if (!is_number_repeated(grid, row, column, number))
		{
			grid[row][column] = number;
			next_row = row;
			next_column = column;
			set_next_position(&next_row, &next_column);
			if (find_solution(grid, views, next_row, next_column))
				return (1);
		}
		number++;
	}
	grid[row][column] = 0;
	return (0);
}
