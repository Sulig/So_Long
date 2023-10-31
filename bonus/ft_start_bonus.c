/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:49:59 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/31 20:31:50 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_data	ft_new_window(t_map *map, t_objs obj)
{
	char	*title;
	t_data	data;

	title = "The Dungeons Bonus";
	data.size = map->size * obj.img_y;
	data.len = map->len * obj.img_x;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.len, data.size, title);
	data.wimg = mlx_new_image(data.mlx, data.len, data.size);
	data.adr = mlx_get_data_addr(data.wimg, &data.btpx, &data.ln, &data.end);
	return (data);
}

static void	ft_start_player(t_player *player)
{
	player->act.x = player->map->start.x;
	player->act.y = player->map->start.y;
	player->rem = player->map->coins;
	player->steps = 0;
	player->win = 0;
}

static t_objs	ft_init_corners(t_data data, t_objs obj)
{
	char	*path;

	path = "./sprites/xpm/Walls/Up_Wall.xpm";
	obj.wu = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Walls/Down_Wall.xpm";
	obj.wd = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Walls/Left_Wall.xpm";
	obj.wl = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Walls/Right_Wall.xpm";
	obj.wr = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Walls/Up_Left_Wall.xpm";
	obj.ul = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Walls/Up_Right_Wall.xpm";
	obj.ur = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Walls/Down_Left_Wall.xpm";
	obj.dl = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Walls/Down_Right_Wall.xpm";
	obj.dr = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	return (obj);
}

static t_objs	ft_init_objs(t_data data, t_objs obj)
{
	char	*path;

	path = "./sprites/xpm/Walls/Cross_Wall.xpm";
	obj.cw = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Floor/Tile_v3.xpm";
	obj.fl = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Player/Player_v2.xpm";
	obj.pl = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Collect/Key_v3.xpm";
	obj.cl = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Exit/Exit_v2.xpm";
	obj.ex = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Exit/PlayerinExit_v2.xpm";
	obj.ep = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Exit/Exit_Open_v2.xpm";
	obj.op = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Exit/Win_v2.xpm";
	obj.wn = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	return (obj);
}

void	ft_start(t_map *map)
{
	t_data		data;
	t_objs		objs;
	t_player	player;

	objs.img_x = 100;
	objs.img_y = 100;
	data = ft_new_window(map, objs);
	objs = ft_init_corners(data, objs);
	objs = ft_init_objs(data, objs);
	player.map = map;
	player.data = data;
	player.objs = objs;
	ft_start_player(&player);
	ft_style_map(&player);
	player.text = ft_init_text(&player);
	ft_start_anims(&player);
	ft_update(player);
}
