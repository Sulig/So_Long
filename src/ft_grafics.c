/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grafics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:29:07 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/10 20:37:49 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window(t_map *map)
{
	void	*mlx;
	void	*mlx_win;

	map->size *= 25;
	map->len *= 25;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map->len, map->size, "The dungeons");
	mlx_loop(mlx);
}
