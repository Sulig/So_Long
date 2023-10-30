/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:44:16 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/30 19:30:31 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_wingame(t_player *player, size_t x, size_t y)
{
	char	*ms;

	ms = "Well done!";
	player->map->map[y][x] = 'S';
	if (player->rem == 0)
	{
		player->win = 1;
		player->map->map[y][x] = 'W';
	}
	player->steps++;
	player->map->map[player->act.y][player->act.x] = '0';
	player->act.x = x;
	player->act.y = y;
	ft_paint_actmap(player->data, player->objs, player->map->map);
	ft_printf("Steps: %u\tKeys: %u\n", player->steps, player->rem);
	if (player->win)
	{
		ft_printf("\033[1;32m\n~ **************************************** ~\n");
		ft_printf("\n ~\t\t Well done!\t\t ~\n");
		ft_printf(" ~ \t You scaped from the dungeon!\t ~\n");
		ft_printf("\n~ **************************************** ~\n\n");
		ft_printf("\033[1;33mClose the game with ESC or close the window\n\n");
	}
}

void	ft_move(t_player *player, size_t x, size_t y)
{
	if (player->map->map[y][x] == 'E')
		ft_wingame(player, x, y);
	else if (player->map->map[y][x] != '1' && !player->win)
	{
		if (player->map->map[y][x] == 'C' && player->rem != 0)
			player->rem--;
		player->map->map[player->act.y][player->act.x] = '0';
		if (player->act.y == player->map->exit.y)
			if (player->act.x == player->map->exit.x)
				player->map->map[player->act.y][player->act.x] = 'E';
		player->steps++;
		player->act.x = x;
		player->act.y = y;
		player->map->map[y][x] = 'P';
		ft_paint_actmap(player->data, player->objs, player->map->map);
		ft_printf("Steps: %u\tKeys: %u\n", player->steps, player->rem);
	}
}

int	ft_on_keydown(int keycode, t_player *player)
{
	if (keycode == ESC)
		ft_exit();
	if (!player->win)
	{
		if (keycode == W || keycode == UP)
			ft_move(player, player->act.x, player->act.y - 1);
		if (keycode == A || keycode == LEFT)
			ft_move(player, player->act.x - 1, player->act.y);
		if (keycode == S || keycode == DOWN)
			ft_move(player, player->act.x, player->act.y + 1);
		if (keycode == D || keycode == RIGHT)
			ft_move(player, player->act.x + 1, player->act.y);
	}
	return (keycode);
}

void	ft_update(t_player player)
{
	mlx_hook(player.data.mlx_win, 2, 0, ft_on_keydown, &player);
	mlx_hook(player.data.mlx_win, 17, 0, ft_exit, &player);
	mlx_loop(player.data.mlx);
}
