/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_man_struc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:43:27 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/05 20:29:37 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_generator.h"

void	*ft_free_arr(size_t size, char **arr)
{
	while (size--)
		free(arr[size]);
	free(arr);
	return (NULL);
}

void	*ft_free_all(t_map *map)
{
	map->map = ft_free_arr(map->size, map->map);
	if (map->sol)
		map->sol = ft_free_arr(map->size, map->sol);
	free(map);
	return (NULL);
}

static void	ft_init(t_map *map)
{
	map->start.x = 0;
	map->start.y = 0;
	map->exit.x = 0;
	map->exit.y = 0;
}

t_map	*ft_new_map(t_map *map)
{
	map = malloc(sizeof(t_map) * 1);
	if (!map)
		return (NULL);
	map->map = NULL;
	map->sol = NULL;
	map->size = (3 + rand() % 100);
	map->len = (5 + rand() % 100);
	map->coins = 0;
	map->players = 0;
	ft_init(map);
	return (map);
}

void	ft_fill_sol(t_map *map)
{
	size_t	len;
	size_t	size;

	size = 0;
	while (size <= map->size)
	{
		len = 0;
		while (len <= map->len)
		{
			map->sol[size][len] = map->map[size][len];
			if (map->map[size][len] != '1')
				map->sol[size][len] = '0';
			len++;
		}
		size++;
	}
}
