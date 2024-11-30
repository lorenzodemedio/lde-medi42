/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:44:37 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/22 01:44:40 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char	*str);
int		is_base_valid(char	*base);
void	print_reverse(char	*str, int size);

void	ft_putnbr_base(int nbr, char	*base)
{
	int		i;
	long	res;
	char	output[35];

	i = 0;
	if (!is_base_valid(base))
		return ;
	res = nbr;
	if (res == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	if (res < 0)
	{
		write(1, "-", 1);
		res = -res;
	}
	while (res > 0)
	{
		output[i++] = base[res % ft_strlen(base)];
		res /= ft_strlen(base);
	}
	output[i] = '\0';
	print_reverse(output, ft_strlen(output));
}

void	print_reverse(char	*str, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		write(1, &str[i--], 1);
	}
}

int	ft_strlen(char	*str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	is_base_valid(char	*base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		j = 0;
		while (j < ft_strlen(base))
		{
			if ((base[i] == base[j] && i != j)
				|| base[i] == '+' || base[i] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* int main (int argc, char	**argv)
{
	ft_putnbr_base(12, argv[1]);
} */