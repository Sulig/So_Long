/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:50:01 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/20 13:04:05 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_paint_map(t_data data, t_objs obj, char **map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data.size)
	{
		x = 0;
		while (x < data.len)
		{
			if (map[y / 100][x / 100] == '1')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.wu, x, y);
			if (map[y / 100][x / 100] == '0')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.fl, x, y);
			if (map[y / 100][x / 100] == 'P')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.pl, x, y);
			if (map[y / 100][x / 100] == 'C')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.cl, x, y);
			if (map[y / 100][x / 100] == 'E')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.ex, x, y);
			x += obj.img_x;
		}
		y += obj.img_y;
	}
}

void	ft_style_map(t_player *player)
{
	ft_paint_map(player->data, player->objs, player->map->map);
}

void	ft_paint_actmap(t_data data, t_objs obj, char **map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data.size)
	{
		x = 0;
		while (x < data.len)
		{
			if (map[y / 100][x / 100] == 'S')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.ep, x, y);
			if (map[y / 100][x / 100] == '0')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.fl, x, y);
			if (map[y / 100][x / 100] == 'P')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.pl, x, y);
			if (map[y / 100][x / 100] == 'E')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.ex, x, y);
			if (map[y / 100][x / 100] == 'W')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.wn, x, y);
			x += obj.img_x;
		}
		y += obj.img_y;
	}
}
