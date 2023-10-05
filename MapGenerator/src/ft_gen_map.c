/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:31:40 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/05 20:17:37 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_generator.h"

static t_map	*ft_close_map(t_map *map)
{
	size_t	size;
	size_t	len;

	size = 0;
	while (size <= map->size)
	{
		len = 0;
		while (len <= map->len)
		{
			if (size == 0 || size == map->size)
				map->map[size][len] = '1';
			else if (len == 0 || len == map->len)
				map->map[size][len] = '1';
			else
				map->map[size][len] = '0';
			len++;
		}
		size++;
	}
	return (map);
}

static t_map	*ft_rand_map(t_map *map)
{
	static size_t	seed;
	size_t			size;
	size_t			len;
	size_t			random;

	size = 1;
	while (size < map->size)
	{
		len = 1;
		while (len < map->len)
		{
			random = (rand() % 6);
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
			else
				map->map[size][len] = '0';
			len++;
		}
		size++;
	}
	srand(seed--);
	return (map);
}

char	**ft_create_arr(size_t max_size, size_t max_len)
{
	size_t	size;
	char	**arr;

	size = 0;
	arr = NULL;
	arr = ft_calloc(max_size + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	while (size <= max_size)
	{
		arr[size] = ft_calloc(max_len + 1, sizeof(char));
		if (!arr[size])
			return (NULL);
		size++;
	}
	return (arr);
}

t_map	*ft_gen_map(t_map *map)
{
	map->map = ft_create_arr(map->size, map->len);
	if (!map->map)
		return (NULL);
	map = ft_close_map(map);
	map = ft_rand_map(map);
	while (ft_check_map_sol(map) != 1)
	{
		map = ft_rand_map(map);
	}
	return (map);
}
