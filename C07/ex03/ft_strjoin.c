/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 03:51:30 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/26 04:50:31 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char	*str);
void	add_to_string(char	*s1, char	*s2);
void	init_string_null(char	*str, size_t size);

char	*ft_strjoin(int size, char	**strs, char *sep)
{
	int		i;
	size_t	joined_size;
	char	*output;

	i = 0;
	joined_size = 0;
    output = NULL;
	while (i < size)
		joined_size += ft_strlen(strs[i++]);
    if (size == 0)
		return (output);
	output = (char *)malloc((joined_size + (size - 1)
				* (ft_strlen(sep))) * sizeof(char));
    if (output == NULL)
    {
        return (NULL);
    }
	init_string_null(output, joined_size + (size) * (ft_strlen(sep)));
	i = 0;
	while (i < size)
	{
		add_to_string(output, strs[i]);
		if (i < size - 1)
			add_to_string(output, sep);
		i++;
	}
    output[(joined_size + ((size - 1) * ft_strlen(sep)))] = '\0';
	return (output);
}

void	init_string_null(char	*str, size_t size)
{
	int	i;

	i = 0;
	while (i < (int)size)
		str[i++] = '\0';
}

void	add_to_string(char	*s1, char	*s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
}

size_t	ft_strlen(char	*str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}
#include <stdio.h>
int main(int argc, char	*argv[])
{
	char	*test;

	test = ft_strjoin(argc, argv, " o-o ");
	if (argc)
		printf("%s\n",test);
	free(test);
}