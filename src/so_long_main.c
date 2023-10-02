/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:45:10 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/02 20:02:33 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_map(char *file, t_map *map)
{
	int		fd;
	int		ok;

	ok = 0;
	fd = open(file, O_RDONLY);
	map = ft_fill_map(fd, map);
	if (map->map)
	{
		if (ft_check_size(map))
			if (ft_check_sym(map))
				if (ft_check_minstat(map))
					if (ft_check_closed(map))
						if (ft_check_map_sol(map))
							ok = 1;
	}
	close(fd);
	return (ok);
}

int	main(int argc, char **args)
{
	t_map	*map;

	map = NULL;
	if (argc != 2)
	{
		color('r');
		ft_printf("Error\nIncorrect number of arguments\n");
		color('y');
		ft_printf("Please introduce ONE file .ber");
		ft_printf(" like this example:\n./so_long map.ber\n");
	}
	else
	{
		if (ft_check_format(args[1]))
		{
			map = ft_new_map(map);
			if (map)
			{
				if (ft_check_map(args[1], map))
					ft_printf("Ok\n");
			}
		}
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
