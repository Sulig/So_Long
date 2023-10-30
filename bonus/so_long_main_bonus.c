/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:42:03 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/26 19:55:46 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_check_map(char *file, t_map *map)
{
	int		fd;
	int		ok;

	ok = 0;
	fd = open(file, O_RDONLY);
	map = ft_fill_map(fd, map);
	if (map)
	{
		if (map->map)
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
		ft_printf("\033[1;31mError\nIncorrect number of arguments\n");
		ft_printf("\033[1;33mPlease introduce ONE file .ber");
		ft_printf(" like this example:\n./so_long map.ber\n");
		exit(0);
	}
	if (ft_check_format(args[1]))
	{
		map = ft_new_map(map);
		if (map)
		{
			if (ft_check_map(args[1], map))
				ft_start(map);
			map = ft_free_map(map);
		}
	}
	exit(0);
}
