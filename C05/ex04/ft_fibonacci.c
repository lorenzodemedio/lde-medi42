/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:50:23 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/18 01:06:38 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{	
	if (index < 0)
		return (-1);
	if (index == 0 || index == 1)
		return (index);
	else
		return(ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
