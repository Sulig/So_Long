/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:10:49 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/06 20:35:53 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_generator.h"

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

void	*ft_free_map_arr(t_map **arr, size_t size)
{
	while (arr[--size])
		arr[size] = ft_free_map(arr[size]);
	free(arr);
	return (NULL);
}
