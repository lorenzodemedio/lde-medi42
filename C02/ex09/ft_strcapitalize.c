/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 05:03:00 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/15 03:39:06 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// returns 1 when c is an alphabetic char
int	ft_is_alphanumeric(char	c)
{
	return ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'));
}

void	ft_charupcase(char	*c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

void	ft_charlowcase(char	*c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}

char	*ft_strcapitalize(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((ft_is_alphanumeric(str[i]) && !(ft_is_alphanumeric(str[i - 1])))
			|| i == 0)
			ft_charupcase(&str[i]);
		if (ft_is_alphanumeric(str[i]) && ft_is_alphanumeric(str[i - 1]))
			ft_charlowcase(&str[i]);
		i++;
	}
	return (str);
}
		

#include <stdio.h>


