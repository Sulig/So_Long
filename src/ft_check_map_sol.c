/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_sol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:13:15 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/02 20:33:31 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_sol(t_map *map)
{
	size_t	len;
	size_t	size;

	size = 0;
	while (map->map[size])
	{
		len = 0;
		while (map->map[size][len])
		{
			if (map->map[size][len] == '1')
				ft_printf("\033[1;31m#");
			else if (map->map[size][len] == '0')
				ft_printf("\033[1;32m+");
			else if (map->map[size][len] == 'C')
				ft_printf("\033[1;32m+");
			else
				ft_printf("\033[1;37m%c", map->map[size][len]);
			len++;
		}
		ft_printf("\n");
		size++;
	}
	return (1);
}
