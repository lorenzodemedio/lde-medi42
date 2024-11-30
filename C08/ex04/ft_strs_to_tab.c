/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 03:36:08 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/26 19:31:07 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strdup(char	*src);
int		ft_strlen(char	*str);

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*output;

	i = 0;
    if (ac == 0)
        return (NULL);
	output = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!output)
		return (NULL);
	while (i < ac)
	{
		output[i].str = av[i];
		output[i].size = ft_strlen(av[i]);
		output[i].copy = ft_strdup(av[i]);
		i++;
	}
	output[i].str = '\0';
	return (output);
}

char	*ft_strdup(char	*src)
{
	size_t	i;
	size_t	n;
	char	*duplicate;	

	i = 0;
	if (!src)
		return (NULL);
	n = (size_t)ft_strlen(src) + 1;
	duplicate = (char *)malloc((n) * sizeof(char));
	if (!duplicate)
		return (NULL);
	while (i < n - 1)
	{
		duplicate[i] = src[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

int	ft_strlen(char	*str)
{
	int	size;
    
	if (!str)
		return (0);
	size = 0;
	while (str[size])
		size++;
	return (size);
}

int main(int ac, char **av)
{
    char *args[2] = {"test1", "2tset"};
    t_stock_str *test;

    test = ft_strs_to_tab(0, args );
    for (int i = 1; i > 0; i--)
        free(test[i].copy);
    free(test);
    return (0);
}