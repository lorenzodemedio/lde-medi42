/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:28:55 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/18 00:32:25 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int	nb,	int	power)
{
	if (power < 0)
		return (0);
	else if  (power > 0)
		return (ft_recursive_power(nb, power -1) * nb);
	else
		return (1);
}
