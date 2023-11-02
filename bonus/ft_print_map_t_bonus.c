/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map_t_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:48:46 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/02 13:04:06 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_print_case(char c)
{
	if (c == '1')
		ft_printf("\033[1;34m#");
	else if (c == 'C')
		ft_printf("\033[1;33m*");
	else if (c == '+')
		ft_printf("\033[1;32m+");
	else if (c == '0')
		ft_printf("\033[0;34m0");
	else if (c == 'E' || c == 'P')
		ft_printf("\033[1;37m%c", c);
	else
		ft_printf("\033[0;31m%c", c);
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
			ft_print_case(map[size][len]);
			len++;
		}
		ft_printf("\n");
		size++;
	}
	ft_printf("\n");
}

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
