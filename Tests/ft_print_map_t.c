/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:59:29 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/29 19:00:07 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	ft_print_map_t(t_map *map)
{
	size_t	size;

	size = 0;
	ft_printf("Len of map: %u\n", map->len);
	ft_printf("Size of map: %u\n\n", map->size);
	while (size < map->size)
	{
		ft_printf("|%u|~|%s|\n", size, map->map[size]);
		size++;
	}
	ft_printf("\n");
}
