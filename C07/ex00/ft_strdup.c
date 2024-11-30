/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 02:49:59 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/18 03:04:47 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char	*str);

char	*ft_strdup(char	*src)
{
	size_t	i;
	size_t	n;
	char	*duplicate;	

	i = 0;
	n = ft_strlen(src) + 1;
	duplicate = (char *)malloc((n) * sizeof(char));
	while (i < n)
	{
		duplicate[i] = src[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

size_t	ft_strlen(char	*str)
{
	size_t	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}
