/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:47:53 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/03 13:26:12 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			if (map[y / obj.img_y][x / obj.img_x] == '1')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.cw, x, y);
			if (map[y / obj.img_y][x / obj.img_x] == '0')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.fl, x, y);
			if (map[y / obj.img_y][x / obj.img_x] == 'P')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.pl, x, y);
			if (map[y / obj.img_y][x / obj.img_x] == 'C')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.cl, x, y);
			if (map[y / obj.img_y][x / obj.img_x] == 'E')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.ex, x, y);
			x += obj.img_x;
		}
		y += obj.img_y;
	}
}

static void	ft_paint_corners(t_data data, t_objs obj)
{
	size_t	size;
	size_t	len;

	size = data.size - obj.img_y;
	len = data.len - obj.img_x;
	mlx_put_image_to_window(data.mlx, data.mlx_win, obj.ul, 0, 0);
	mlx_put_image_to_window(data.mlx, data.mlx_win, obj.ur, len, 0);
	mlx_put_image_to_window(data.mlx, data.mlx_win, obj.dl, 0, size);
	mlx_put_image_to_window(data.mlx, data.mlx_win, obj.dr, len, size);
}

static void	ft_paint_walls(t_data data, t_objs obj)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	while (x < data.len)
	{
		mlx_put_image_to_window(data.mlx, data.mlx_win, obj.wu, x, y);
		x += obj.img_x;
	}
	while (y < data.size - obj.img_y)
	{
		x = 0;
		mlx_put_image_to_window(data.mlx, data.mlx_win, obj.wl, x, y);
		x = data.len - obj.img_x;
		mlx_put_image_to_window(data.mlx, data.mlx_win, obj.wr, x, y);
		y += obj.img_y;
	}
	x = 0;
	while (x < data.len)
	{
		mlx_put_image_to_window(data.mlx, data.mlx_win, obj.wd, x, y);
		x += obj.img_x;
	}
}

void	ft_style_map(t_player *player)
{
	ft_paint_map(player->data, player->objs, player->map->map);
	ft_paint_walls(player->data, player->objs);
	ft_paint_corners(player->data, player->objs);
}
