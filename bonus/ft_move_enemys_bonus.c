/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemys_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:16:42 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/02 19:44:09 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_where_can_not_move(char ch)
{
	if (ch == '0' || ch == 'P')
		return (0);
	else
		return (1);
}

static int	ft_can_move(t_player *player, size_t size, size_t len, int move_to)
{
	if (!move_to)
		move_to = 1;
	if (ft_where_can_not_move(player->map->map[size][len + move_to]))
		move_to *= -1;
	return (move_to);
}

static void	ft_move_to(t_player *player, size_t size, size_t len, int move_to)
{
	if (player->map->map[size][len + move_to] == 'P')
		ft_lose_game(player);
	else
	{
		player->map->map[size][len] = '0';
		player->map->map[size][len + move_to] = 'M';
		ft_paint_actmap(player->data, player->objs, player->map->map);
	}
}

static void	ft_where_are_bats(t_player *player)
{
	static int	move_to;
	size_t		size;
	size_t		len;

	size = 1;
	while (player->map->map[size])
	{
		len = 1;
		while (player->map->map[size][len])
		{
			if (player->map->map[size][len] == 'M')
			{
				move_to = ft_can_move(player, size, len, move_to);
				ft_move_to(player, size, len, move_to);
				break ;
			}
			len++;
		}
		size++;
	}
}

void	ft_move_bat(t_player *player)
{
	static size_t	frame;
	size_t			time;

	time = 1200;
	if ((frame % time) == 0)
		ft_where_are_bats(player);
	frame++;
}
