/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_sol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:05:18 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/05 20:28:51 by sadoming         ###   ########.fr       */
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

int	ft_check_map_sol(t_map *map)
{
	if (ft_check_stat(map))
		return (0);
	map->sol = ft_create_arr(map->size, map->len);
	if (!map->sol)
		return (0);
	return (1);
}
