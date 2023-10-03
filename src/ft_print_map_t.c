/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:59:29 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/03 20:19:30 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	ft_print_map_t(t_map *map)
{
	size_t	size;
	size_t	len;

	size = 0;
	ft_printf("Len of map: %u\n", map->len);
	ft_printf("Size of map: %u\n\n", map->size);
	ft_printf("Start are in [%u][%u]\n", map->start.y_pos, map->start.x_pos);
	ft_printf("Exit are in [%u][%u]\n", map->exit.y_pos, map->exit.x_pos);
	ft_printf("\nPreview of map:\n\n");
	while (map->map[size])
	{
		len = 0;
		while (map->map[size][len])
		{
			if (map->map[size][len] == '1')
				ft_printf("\033[1;31m#");
			else if (map->map[size][len] == '0')
				ft_printf("\033[1;32m ");
			else if (map->map[size][len] == 'C')
				ft_printf("\033[1;33m*");
			else
				ft_printf("\033[1;37m%c", map->map[size][len]);
			len++;
		}
		ft_printf("\n");
		size++;
	}
	ft_printf("\033[0;39\n");
}

void	ft_print_sol_t(char **map)
{
	size_t	size;
	size_t	len;

	size = 0;
	while (map[size])
	{
		len = 0;
		while (map[size][len])
		{
		  	ft_printf("\033[1;37m%c", map[size][len]);
			len++;
		}
		ft_printf("\n");
		size++;
	}
	ft_printf("\n");
}
