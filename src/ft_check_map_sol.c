/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_sol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:13:15 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/03 20:27:26 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_locate(t_map *map)
{
	size_t		len;
	size_t		size;

	size = 0;
	while (map->map[size])
	{
		len = 0;
		while (map->map[size][len])
		{
			if (map->map[size][len] == 'P')
			{
				map->start.x_pos = len;
				map->start.y_pos = size;
			}
			if (map->map[size][len] == 'E')
			{
				map->exit.x_pos = len;
				map->exit.y_pos = size;
			}
			len++;
		}
		size++;
	}
}

int	ft_check_sol(char **map, t_lcn str, t_lcn exit, size_t x, size_t y)
{
	ft_printf("ACT: |%c| on [%u][%u]\n", map[y][x], y, x);
	if (map[y][x])
		if (x == exit.x_pos && y == exit.y_pos)
			return (1);
	if (!map[y][x + 1])
	{
		x = 0;
		y++;
	}
	ft_printf("%i ", ft_check_sol(map, str, exit, x + 1, y));
	return (1);
}

int	ft_check_all(t_map *map)
{
	t_lcn	coin;
	int		ok;
	size_t	len;
	size_t	size;

	ok = ft_check_sol(map->sol, map->start, map->exit, 0, 0);
	size = 0;
	while (map->map[size] && ok == 1)
	{
		len = 0;
		while (map->map[size][len] && ok == 1)
		{
			if (map->map[size][len] == 'C')
			{
				coin.x_pos = len;
				coin.y_pos = size;
				ok = ft_check_sol(map->sol, map->start, coin, coin.x_pos, coin.y_pos);
			}
			len++;
		}
		size++;
	}
	return (ok);
}

int	ft_check_map_sol(t_map *map)
{
	int		ok;

	ok = 0;
	ft_locate(map);
	ft_print_map_t(map);
	if (ft_check_all(map))
		ok = 1;
	if (ok == 0)
		ft_printf("\033[1;31mError\nThe map don't have solution!\n");
	return (ok);
}
