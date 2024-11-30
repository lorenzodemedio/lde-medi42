/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 02:22:14 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/22 02:22:16 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_base_valid(char	*base);
int	ft_strlen(char	*str);
int	base_index(char c, char	*base);

int	ft_atoi_base(char	*str, char	*base)
{
	int		i;
	int		output;
	int		minus_count;

	i = 0;
	output = 0;
	minus_count = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] && is_base_valid(base))
	{
		if (str[i] == '-')
			minus_count++;
		if ((str[i] == '-' || str[i] == '+') && str[i + 1] == ' ')
			return (0);
		if (str[i] != '+' && str[i] != '-' && base_index(str[i], base) >= 0)
			output = output * ft_strlen(base) + base_index(str[i], base);
		if ((str[i] != '+' && str[i] != '-')
			&& !(str[i + 1] != '+' && str[i + 1] != '-'))
			break ;
		i++;
	}
	if (minus_count % 2 != 0)
		output = -output;
	return (output);
}

int	base_index(char c, char	*base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
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

int	ft_strlen(char	*str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}
#include <stdio.h>
int main(int	argc, char	*argv[])
{
	if (argc)
		printf("%d",ft_atoi_base(argv[1], argv[2]));
}