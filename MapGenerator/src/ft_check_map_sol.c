/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_sol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:05:18 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/06 16:30:03 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_generator.h"

static int	ft_check_stat(t_map *map)
{
	size_t	size;
	size_t	len;

	size = 0;
	while (map->map[size])
	{
		len = 0;
		while (map->map[size][len])
		{
			if (map->map[size][len] == 'C')
				map->coins++;
			if (map->map[size][len] == 'E')
			{
				map->exit.x = len;
				map->exit.y = size;
			}
			if (map->map[size][len] == 'P')
			{
				map->start.x = len;
				map->start.y = size;
			}
			len++;
		}
		size++;
	}
	if (map->players != 1)
		return (1);
	if (map->exits != 1)
		return (1);
	if (map->coins < 1)
		return (1);
	return (0);
}

static void ft_find_path(char **map, t_lctn exit, size_t x, size_t y)
{
	if (y < 0 || x < 0 || !map[y])
		return ;
	if (x == exit.x && y == exit.y)
		return ;
	if (map[y][x] != '0')
		return ;
	if (map[y][x])
		map[y][x] = '+';
	ft_find_path(map, exit, x + 1, y);
	ft_find_path(map, exit, x - 1, y);
	ft_find_path(map, exit, x, y + 1);
	ft_find_path(map, exit, x, y - 1);
}

int ft_check_behind(char **map, t_lctn check, char cmp)
{
	if (map[check.y][check.x + 1] == cmp)
		return (1);
	if (map[check.y][check.x - 1] == cmp)
		return (1);
	if (map[check.y + 1])
		if (map[check.y + 1][check.x] == cmp)
			return (1);
	if (map[check.y - 1][check.x] == cmp)
		return (1);
	return (0);
}

static int ft_check_all(t_map *map)
{
	size_t	size;
	size_t	len;
	t_lctn	coin;

	size = 0;
	if (ft_check_behind(map->map, map->exit, '+') == 0)
		return (0);
	while (map->map[size])
	{
		len = 0;
		while (map->map[size][len])
		{
			if (map->map[size][len] == 'C')
			{
				coin.x = len;
				coin.y = size;
				if (ft_check_behind(map->map, coin, '+') == 0)
					return (0);
			}
			len++;
		}
		size++;
	}
	return (1);
}

int	ft_check_map_sol(t_map *map)
{
	if (ft_check_stat(map))
		return (0);
	if (!map->sol)
		map->sol = ft_create_arr(map->size, map->len);
	if (!map->sol)
		return (0);
	ft_fill_sol(map);
	ft_find_path(map->sol, map->exit, map->start.x, map->start.y);
	return (ft_check_all(map));
}
