/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_man_struc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:43:27 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/04 21:02:17 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_free_map(t_map *map)
{
	size_t	cnt;

	cnt = 0;
	while (map->map[--map->size])
		free(map->map[map->size]);
	free(map->map);
	free(map);
	return (NULL);
}

t_map	*ft_new_map(t_map *map)
{
	map = malloc(sizeof(t_map) * 1);
	if (!map)
		return (NULL);
	map->map = NULL;
	map->sol = NULL;
	map->len = 0;
	map->size = 0;
	map->coins = 0;
	return (map);
}

static void	ft_fill_sol(t_map *map)
{
	size_t	len;
	size_t	size;

	size = 0;
	while (map->sol[size])
	{
		len = 0;
		while (map->sol[size][len])
		{
			if (map->map[size][len] != '1')
				map->sol[size][len] = '0';
			len++;
		}
		size++;
	}
}

t_map	*ft_gen_map(t_map *map)
{
	map = ft_new_map(map);
	if (!map)
		return (NULL);
	map->size = (3 + rand() % 100);
	map->len = (5 + rand() % 100);
}
