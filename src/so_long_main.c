/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:45:10 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/28 20:26:48 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_file(char *file)
{
	int		fd;
	size_t	size;

	if (ft_check_format(file))
	{
		fd = open(file, O_RDONLY);
		size = ft_check_size(fd);
		if (size != 0)
			if (fill_map(fd, size))
				ft_printf("OK\n");
		close(fd);
	}
	else
		fd = 0;
}

int	main(int argc, char **args)
{
	if (argc == 2)
		ft_check_file(args[1]);
	else
	{
		color('r');
		ft_printf("Error\nIncorrect number of arguments\n");
		color('y');
		ft_printf("Please introduce ONE file .ber");
		ft_printf(" like this example:\n./so_long map.ber\n");
	}
	return (0);
}

void	color(char color)
{
	if (color == 'R' || color == 'r')
		ft_printf("\033[1;31m");
	else if (color == 'G' || color == 'g')
		ft_printf("\033[1;32m");
	else if (color == 'Y' || color == 'y')
		ft_printf("\033[1;33m");
	else if (color == 'B' || color == 'b')
		ft_printf("\033[1;34m");
	else if (color == 'M' || color == 'm')
		ft_printf("\033[1;35m");
	else if (color == 'C' || color == 'c')
		ft_printf("\033[1;36m");
	else if (color == 'W' || color == 'w')
		ft_printf("\033[1;37m");
	else
		ft_printf("\033[1;39m");
}
