/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lose_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:35:01 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/02 20:34:21 by sadoming         ###   ########.fr       */
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
	player->lose = 1;
	ft_paint_actmap(player->data, player->objs, player->map->map);
}

static void	ft_to_black(t_player *player, size_t len)
{
	size_t	size;
	t_data	data;
	t_text	obj;

	size = 0;
	data = player->data;
	obj = player->text;
	while (size < data.size)
	{
		mlx_put_image_to_window(data.mlx, data.mlx_win, obj.bl, len, size);
		size++;
	}
}

static int	ft_game_over(t_player *player)
{
	static size_t	len;

	if (len < player->data.len)
	{
		ft_to_black(player, len);
		len += 32;
	}
	return (0);
}

void	ft_lose_game(t_player *player)
{
	player->lose = 1;
	player->steps++;
	ft_act_stat(player);
	ft_map_to_zero(player);
	ft_printf("\033[1;31m\n~ **************************************** ~\n");
	ft_printf("\n ~\t\t So Bad!\t\t ~\n");
	ft_printf(" ~ \t\tYou Died!\t\t ~\n");
	ft_printf("\n~ **************************************** ~\n\n");
	ft_printf("\033[1;33mClose the game with ESC or close the window\n\n");
	mlx_loop_hook(player->data.mlx, ft_game_over, player);
}
