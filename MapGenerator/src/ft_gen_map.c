/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:31:40 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/06 17:34:50 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_generator.h"

static t_map	*ft_close_map(t_map *map)
{
	size_t	size;
	size_t	len;

	size = 0;
	while (size < map->size)
	{
		len = 0;
		while (len < map->len)
		{
			if (size == 0 || size == map->size - 1)
				map->map[size][len] = '1';
			else if (len == 0 || len == map->len - 1)
				map->map[size][len] = '1';
			else
				map->map[size][len] = '0';
			len++;
		}
		size++;
	}
	return (map);
}

static t_map	*ft_rand_map(t_map *map, size_t seed)
{
	size_t			size;
	size_t			len;
	size_t			random;

	size = 1;
	srand(seed);
	while (size < map->size - 1)
	{
		len = 1;
		while (len < map->len - 1)
		{
			random = (rand() % 7);
			if (random == 2)
				map->map[size][len] = '1';
			else if (random == 3)
				map->map[size][len] = 'C';
			else if (random == 4 && map->players == 0)
			{
				map->map[size][len] = 'P';
				map->players++;
			}
			else if (random == 5 && map->exits == 0)
			{
				map->map[size][len] = 'E';
				map->exits++;
			}
			len++;
		}
		size++;
	}
	return (map);
}

static t_map	*ft_open_way(t_map *map, t_lctn where)
{
	size_t	random;

	random = (rand() % 4);
	if (random == 1 && map->map[where.y][where.x + 1] == '1')
		map->map[where.y][where.x + 1] = '0';
	else if (random == 2 && map->map[where.y][where.x - 1] == '1')
		map->map[where.y][where.x - 1] = '0';
	else if (random == 3 && map->map[where.y + 1][where.x] == '1')
		map->map[where.y + 1][where.x] = '0';
	else if (random == 4 && map->map[where.y - 1][where.x] == '1')
		map->map[where.y -1][where.x] = 0;
	srand(random * 7);
	return (map);
}

static t_map	*ft_check_all(t_map *map)
{
	size_t	size;
	size_t	len;
	t_lctn	coin;

	size = 0;
	while (ft_check_behind(map->map, map->exit, '0') == 0)
		map = ft_open_way(map, map->exit);
	while (map->map[size])
	{
		len = 0;
		while (map->map[size][len])
		{
			if (map->map[size][len] == 'C')
			{
				coin.x = len;
				coin.y = size;
				while (ft_check_behind(map->map, coin, '0') == 0)
					map = ft_open_way(map, coin);
			}
			len++;
		}
		size++;
	}
	return (map);
}

t_map	*ft_gen_map(t_map *map, size_t seed)
{
	if (!map->map)
		map->map = ft_create_arr(map->size, map->len);
	if (!map->map)
		return (NULL);
	map = ft_close_map(map);
	map = ft_rand_map(map, seed);
	if (ft_check_map_sol(map) != 1)
		map = ft_check_all(map);
	return (map);
}
