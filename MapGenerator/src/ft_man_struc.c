/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_man_struc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:43:27 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/06 20:02:01 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_generator.h"

void	ft_init(t_map *map)
{
	map->players = 0;
	map->exits = 0;
	map->coins = 0;
	map->start.x = 0;
	map->start.y = 0;
	map->exit.x = 0;
	map->exit.y = 0;
}

void	ft_fill_sol(t_map *map)
{
	size_t	len;
	size_t	size;

	size = 0;
	while (map->map[size])
	{
		len = 0;
		while (map->map[size][len])
		{
			map->sol[size][len] = map->map[size][len];
			if (map->map[size][len] != '1')
				map->sol[size][len] = '0';
			len++;
		}
		size++;
	}
}

void	*ft_free_map(t_map *map)
{
	if (map->map)
		map->map = ft_free_arr(map->size, map->map);
	if (map->sol)
		map->sol = ft_free_arr(map->size, map->sol);
	ft_init(map);
	free(map);
	return (NULL);
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
	while (size < max_size)
	{
		arr[size] = ft_calloc(max_len + 1, sizeof(char));
		if (!arr[size])
			return (NULL);
		size++;
	}
	return (arr);
}

t_map	*ft_new_map(t_map *map, size_t seed)
{
	map = malloc(sizeof(t_map) * 1);
	if (!map)
		return (NULL);
	map->map = NULL;
	map->sol = NULL;
	srand(seed);
	map->size = (3 + rand() % 100);
	map->len = (5 + rand() % 100);
	ft_init(map);
	return (map);
}
