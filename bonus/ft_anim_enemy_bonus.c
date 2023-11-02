/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:48:50 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/02 16:10:03 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_anim	ft_init_anim_bat(t_data dt, t_anim an)
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
		path = "./sprites/xpm/Enemy/Anim/Bat_.xpm";
		num = ft_unsig_tobase(i, 'd');
		path = ft_strinter(path, num, 29);
		an.sp[i] = mlx_xpm_file_to_image(dt.mlx, path, &an.img_x, &an.img_y);
		free(path);
		free(num);
		i++;
	}
	return (an);
}

static void	ft_put_win(t_data data, void *sprite, size_t x, size_t y)
{
	mlx_put_image_to_window(data.mlx, data.mlx_win, sprite, x, y);
}

static void	ft_where_are_bats(t_player *player)
{
	size_t	size;
	size_t	len;
	t_lcn	bat;

	size = 0;
	while (player->map->map[size])
	{
		len = 0;
		while (player->map->map[size][len])
		{
			if (player->map->map[size][len] == 'M')
			{
				bat.x = len * player->anim_eny.img_x;
				bat.y = size * player->anim_eny.img_y;
				ft_put_win(player->data, player->anim_eny.ac, bat.x, bat.y);
			}
			len++;
		}
		size++;
	}
}

void	ft_animate_bat(t_player *player)
{
	static size_t	pos;
	static size_t	frame;
	size_t			time;

	time = 600;
	if ((frame % time) == 0)
	{
		if (pos > 4)
			pos = 0;
		player->anim_eny.ac = player->anim_eny.sp[pos];
		ft_where_are_bats(player);
		pos++;
	}
	frame++;
}

void	ft_start_anim_enemy(t_player *player)
{
	t_anim	anim_bat;

	anim_bat.size = 4;
	anim_bat.img_x = 100;
	anim_bat.img_y = 100;
	anim_bat.ac = NULL;
	anim_bat = ft_init_anim_bat(player->data, anim_bat);
	player->anim_eny = anim_bat;
}
