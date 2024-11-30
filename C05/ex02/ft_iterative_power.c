/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:19:16 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/18 00:26:13 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int output;

	i = 0;
	output = 1;
	if (power <  0)
		return (0);
	while (i < power)
	{
		output *= nb;
		i++;
	}
	return (output);
}
