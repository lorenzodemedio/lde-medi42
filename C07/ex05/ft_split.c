/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:42:18 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/28 02:55:46 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_splitter(char c, char *charset);
int		word_counter(char	*str, char	*charset);
char	*get_word(char *str, char *charset);

char	**ft_split(char *str, char *charset)
{
	char	**output;
	int		words;
	int		i;
	int		j;

	j = 0;
	words = word_counter(str, charset);
	output = (char **)malloc(sizeof(char *) * (words + 1));
	i = 0;
	while (str[j])
	{
		while (str[j] && is_splitter(str[j], charset))
			j++;
		if (str[j] && !is_splitter(str[j], charset))
		{
			output[i] = get_word(&str[j], charset);
			i++;
			while (str[j] && !is_splitter(str[j], charset))
				j++;
		}
	}
	output[i] = 0;
	return (output);
}

char	*get_word(char *str, char *charset)
{
	char	*output;
	int		i;

	i = 0;
	while (str[i] && !is_splitter(str[i], charset))
		i++;
	output = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (*str && !is_splitter(*str, charset))
	{
		output[i] = *str;
		i++;
		str++;
	}
	output[i] = '\0';
	return (output);
}

int	word_counter(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_splitter(str[i], charset))
			i++;
		if (str[i] && !is_splitter(str[i], charset))
		{
			count++;
			while (str[i] && !is_splitter(str[i], charset))
				i++;
		}
	}
	return (count);
}

int	is_splitter(char c, char	*charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

/* #include <stdio.h>
int main(int ac, char **av)
{
	char   **test = ft_split(av[1], av[2]);
} */