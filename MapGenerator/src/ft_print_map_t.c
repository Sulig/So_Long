/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:59:29 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/04 19:57:32 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_generator.h"

void	ft_print_stat(t_map *map)
{
	ft_printf("Len of map: %u\n", map->len);
	ft_printf("Size of map: %u\n\n", map->size);
	ft_printf("Num of collectables: %u", map->coins);
	ft_printf("Start are in [%u][%u]\n", map->start.y, map->start.x);
	ft_printf("Exit are in [%u][%u]\n", map->exit.y, map->exit.x);
	ft_printf("\nPreview of map:\n\n");
	ft_print_map_t(map->map);
	ft_printf("\nPreview of sol:\n\n");
	ft_print_map_t(map->sol);
}

void	ft_print_map_t(char **map)
{
	size_t	size;
	size_t	len;

	size = 0;
	while (map[size])
	{
		len = 0;
		while (map[size][len])
		{
			if (map[size][len] == '1')
				ft_printf("\033[1;34m#");
			else if (map[size][len] == 'C')
				ft_printf("\033[1;33m*");
			else if (map[size][len] == '+')
				ft_printf("\033[1;32m+");
			else if (map[size][len] == '0')
				ft_printf("\033[0;34m0");
			else if (map[size][len] == 'E' || map[size][len] == 'P')
				ft_printf("\033[1;37m%c", map[size][len]);
			else
				ft_printf("\033[0;31m%c", map[size][len]);
			len++;
		}
		ft_printf("\n");
		size++;
	}
	ft_printf("\n");
}
