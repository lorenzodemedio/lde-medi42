/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:50:55 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/15 04:12:25 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	tf_len;

	i = 0;
	tf_len = 0;
	while (to_find[tf_len] != '\0')
		tf_len++;
	if (tf_len == 0)
		return (str);
	while (str[i] != '\0')
	{
		if (ft_strncmp(&str[i], to_find, tf_len) == 0)
			return (&str[i]);
		i++;
	}
	return ('\0');
}
