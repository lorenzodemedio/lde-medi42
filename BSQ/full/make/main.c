/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:35:52 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/26 17:12:23 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		write(2, "Launch program with n arguments (map files names.)\n", 51);
		return (1);
	}
	while (i < argc)
	{
		if (!process_map(argv[i]))
		{
			write(2, "map error\n", 10);
		}
		if (i != argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
