/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grafics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:29:07 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/17 12:57:36 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_data	ft_new_window(t_map *map)
{
	t_data	data;

	data.size = map->size * 100;
	data.len = map->len * 100;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.len, data.size, "Dungeons");
	data.wimg = mlx_new_image(data.mlx, data.len, data.size);
	data.adr = mlx_get_data_addr(data.wimg, &data.btpx, &data.ln, &data.end);
	return (data);
}

static t_objs	ft_init_objs(t_data data)
{
	t_objs	obj;
	char	*path;

	obj.img_x = 100;
	obj.img_y = 100;
	path = "./sprites/xpm/Walls/Wall_v2.xpm";
	obj.wl = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Floor/Black_floor.xpm";
	obj.fl = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Player/Triangle_Pl.xpm";
	obj.pl = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Collect/Key_demo.xpm";
	obj.cl = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Exit/Exit_v0.xpm";
	obj.ex = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	return (obj);
}

static char	**ft_clone_map(t_map *map, char **clone)
{
	char	*join;
	size_t	size;

	size = 0;
	join = NULL;
	clone = NULL;
	while (size < map->size)
	{
		join = ft_strjoin(join, map->map[size]);
		join = ft_strjoin(join, "\n");
		size++;
	}
	clone = ft_split(join, '\n');
	if (!clone)
		return (NULL);
	free(join);
	return (clone);
}

void	ft_paint_map(t_data data, t_objs obj, char **map)
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
				mlx_put_image_to_window(data.mlx, data.mlx_win, obj.wl, x, y);
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

void	ft_start(t_map *map)
{
	t_data		data;
	t_objs		objs;
	t_player	player;

	data = ft_new_window(map);
	objs = ft_init_objs(data);
	player.act_map = ft_clone_map(map, player.act_map);
	ft_paint_map(data, objs, player.act_map);
	player.act.x = map->start.x;
	player.act.y = map->start.y;
	player.recol = 0;
	player.steps = 0;
	mlx_key_hook(data.mlx_win, ft_man_events, &data);
	mlx_hook(data.mlx_win, 17, 0, ft_exit, &data);
	mlx_loop(data.mlx);
}