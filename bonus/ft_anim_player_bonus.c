/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:56:23 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/14 18:29:11 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_anim	ft_init_anim_player(t_data dt, t_anim an)
{
	char	*path;
	char	*num;
	size_t	i;

	i = 0;
	an.sp = ft_calloc(sizeof(void *), an.size + 1);
	if (!an.sp)
		return (an);
	while (i <= an.size)
	{
		path = "./sprites/xpm/Player/Anim/Player_.xpm";
		num = ft_unsig_tobase(i, 'd');
		path = ft_strinter(path, num, 33);
		an.sp[i] = mlx_xpm_file_to_image(dt.mlx, path, &an.img_x, &an.img_y);
		free(path);
		free(num);
		i++;
	}
	return (an);
}

static void	ft_put_win(t_player *player, size_t x, size_t y)
{
	t_data	data;
	void	*sprite;

	data = player->data;
	sprite = player->anim_pla.ac;
	mlx_put_image_to_window(data.mlx, data.mlx_win, sprite, x, y);
}

static void	ft_where_is_player(t_player *player)
{
	size_t	size;
	size_t	len;
	t_lcn	ply;

	size = 0;
	while (player->map->map[size])
	{
		len = 0;
		while (player->map->map[size][len])
		{
			if (player->map->map[size][len] == 'P')
			{
				ply.x = len * player->anim_pla.img_x;
				ply.y = size * player->anim_pla.img_y;
				ft_put_win(player, ply.x, ply.y);
			}
			len++;
		}
		size++;
	}
}

void	ft_anim_player(t_player *player)
{
	static size_t	pos;
	static size_t	frame;
	size_t			time;

	time = 900;
	if ((frame % time) == 0)
	{
		if (pos > 3)
			pos = 0;
		player->anim_pla.ac = player->anim_pla.sp[pos];
		ft_where_is_player(player);
		pos++;
	}
	frame++;
}

void	ft_start_anim_player(t_player *player)
{
	t_anim	anim_player;

	anim_player.size = 3;
	anim_player.img_x = 100;
	anim_player.img_y = 100;
	anim_player.ac = NULL;
	anim_player = ft_init_anim_player(player->data, anim_player);
	player->anim_pla = anim_player;
}
