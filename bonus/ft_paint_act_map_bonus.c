/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_act_map_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:25:38 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/03 13:46:27 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_paint_other(t_data data, t_objs obj, char **map, t_lcn lcn)
{
	size_t	x;
	size_t	y;

	x = lcn.x;
	y = lcn.y;
	if (map[y / obj.img_y][x / obj.img_x] == 'M')
		mlx_put_image_to_window(data.mlx, data.mlx_win, obj.mn, x, y);
	if (map[y / obj.img_y][x / obj.img_x] == 'W')
		mlx_put_image_to_window(data.mlx, data.mlx_win, obj.wn, x, y);
	if (map[y / obj.img_y][x / obj.img_x] == 'O')
		mlx_put_image_to_window(data.mlx, data.mlx_win, obj.op, x, y);
}

void	ft_paint_actmap(t_data data, t_objs obj, char **map)
{
	t_lcn	lcn;
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data.size)
	{
		x = 0;
		while (x < data.len)
		{
			if (map[y / obj.img_y][x / obj.img_x] == 'S')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.ep, x, y);
			if (map[y / obj.img_y][x / obj.img_x] == '0')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.fl, x, y);
			if (map[y / obj.img_y][x / obj.img_x] == 'P')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.pl, x, y);
			if (map[y / obj.img_y][x / obj.img_x] == 'E')
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.ex, x, y);
			lcn.x = x;
			lcn.y = y;
			ft_paint_other(data, obj, map, lcn);
			x += obj.img_x;
		}
		y += obj.img_y;
	}
}
