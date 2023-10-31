/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim_keys_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:45:25 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/31 19:45:55 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_anim	ft_init_anim_key(t_data dt, t_anim an)
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
		path = "./sprites/xpm/Collect/Anim/Key_.xpm";
		num = ft_unsig_tobase(i, 'd');
		path = ft_strinter(path, num, 31);
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

static void	ft_where_are_keys(t_player *player)
{
	size_t	size;
	size_t	len;
	t_lcn	coin;

	size = 0;
	while (player->map->map[size])
	{
		len = 0;
		while (player->map->map[size][len])
		{
			if (player->map->map[size][len] == 'C')
			{
				coin.x = len * player->anim_key.img_x;
				coin.y = size * player->anim_key.img_y;
				ft_put_win(player->data, player->anim_key.ac, coin.x, coin.y);
			}
			len++;
		}
		size++;
	}
}

static int	ft_animate_key(t_player *player)
{
	static size_t	pos;
	static size_t	frame;
	size_t			div;

	div = 900;
	if ((frame % div) == 0)
	{
		if (pos > 5)
			pos = 0;
		player->anim_key.ac = player->anim_key.sp[pos];
		ft_where_are_keys(player);
		pos++;
	}
	frame++;
	return (0);
}

void	ft_start_anim(t_player *player)
{
	t_anim	anim_key;

	anim_key.size = 5;
	anim_key.img_x = 100;
	anim_key.img_y = 100;
	anim_key.ac = NULL;
	anim_key = ft_init_anim_key(player->data, anim_key);
	player->anim_key = anim_key;
	mlx_loop_hook(player->data.mlx, ft_animate_key, player);
}
