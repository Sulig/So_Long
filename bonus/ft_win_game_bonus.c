/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:35:36 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/06 17:11:03 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_map_to_zero(t_player *player)
{
	size_t	size;
	size_t	len;

	size = 1;
	while (player->map->map[size])
	{
		len = 1;
		while (player->map->map[size][len])
		{
			if (player->map->map[size][len] != '1')
				player->map->map[size][len] = '1';
			len++;
		}
		size++;
	}
	player->act.x = 0;
	player->act.y = 0;
	player->win = 1;
	ft_paint_actmap(player->data, player->objs, player->map->map);
}

static void	ft_to_win(t_player *player, size_t len)
{
	size_t	size;
	t_data	data;
	t_objs	obj;

	size = 0;
	data = player->data;
	obj = player->objs;
	while (size < data.size)
	{
		mlx_put_image_to_window(data.mlx, data.mlx_win, obj.fl, len, size);
		size++;
	}
}

static void	ft_put_gamewin(t_player *player)
{
	size_t	len;
	size_t	size;
	t_data	data;
	t_text	obj;

	data = player->data;
	obj = player->text;
	size = data.size / 2 - 50;
	len = data.len / 2 - 150;
	mlx_put_image_to_window(data.mlx, data.mlx_win, obj.gw, len, size);
}

static int	ft_game_win(t_player *player)
{
	static size_t	len;

	if (len < player->data.len)
	{
		ft_to_win(player, len);
		len += 100;
	}
	else
		ft_put_gamewin(player);
	return (0);
}

void	ft_win_game(t_player *player)
{
	ft_map_to_zero(player);
	ft_printf("\033[1;32m\n~ **************************************** ~\n");
	ft_printf("\n ~\t\t Well done!\t\t ~\n");
	ft_printf(" ~ \t You scaped from the dungeon!\t ~\n");
	ft_printf("\n~ **************************************** ~\n\n");
	ft_printf("\033[1;33mClose the game with ESC or close the window\n\n");
	mlx_loop_hook(player->data.mlx, ft_game_win, player);
}
