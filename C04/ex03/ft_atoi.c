/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 03:18:05 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/15 05:12:36 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_digit(char c);
int	ft_is_whitespace(char c);

int	ft_atoi(char	*str)
{
	int		i;
	int		output;
	int		minus_count;

	i = 0;
	minus_count = 0;
	output = 0;
	while (ft_is_whitespace(str[i]))
		i++;
	while (str[i])
	{
		if (str[i] == '-')
			minus_count++;
		if (!ft_char_is_digit(str[i]) && str[i] != '+'
			&& str[i] != '-')
			break ;
		if (ft_char_is_digit(str[i]))
			output = (output * 10) + str[i] - '0';
		if (ft_char_is_digit(str[i]) && !ft_char_is_digit(str[i + 1]))
			break ;
		i++;
	}
	if (minus_count % 2 != 0)
		output = -output;
	return (output);
}

int	ft_char_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

/* #include <stdio.h>
int	main(int	argc, char	*argv[])
{
	if (argc < 2)
		return 1;
	printf("atoi con el arg passato > %d\n", ft_atoi(argv[1]));
	return (0);
} */
