/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 03:17:18 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/16 04:38:04 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_HEADER_H
# define RUSH_HEADER_H

void	ft_putstr(char	*str);
int		is_char_digit(char c);
int		is_even_number(int n);
int		is_valid_input(int argc, char	*input);
int		ft_strlen(char	*str);

typedef struct s_towers_visibility
{
	int	col_up[4];
	int	col_down[4];
	int	row_left[4];
	int	row_right[4];
}	t_towers_visibility;

#endif
