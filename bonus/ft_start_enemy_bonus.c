/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_enemy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:15:39 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/02 16:16:27 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static size_t	ft_can_locate(char **map, size_t size, size_t len)
{
	size_t	ok;

	ok = 1;
	if (map[size][len + 1] == 'P' || map[size][len + 1] == '1')
		ok = 0;
	if (map[size][len - 1] == 'P' || map[size][len - 1] == '1')
		ok = 0;
	if (map[size - 1][len] == 'P' || map[size - 1][len] == '1')
		ok = 0;
	if (map[size + 1][len] == 'P' || map[size + 1][len] == '1')
		ok = 0;
	if (map[size][len + 1] == 'C' || map[size][len + 1] == 'E')
		ok = 0;
	if (map[size][len - 1] == 'C' || map[size][len - 1] == 'E')
		ok = 0;
	if (map[size - 1][len] == 'C' || map[size - 1][len] == 'E')
		ok = 0;
	if (map[size + 1][len] == 'C' || map[size + 1][len] == 'E')
		ok = 0;
	return (ok);
}

static void	ft_locate_enemys(t_player *player)
{
	size_t	size;
	size_t	len;
	size_t	ok;

	size = 1;
	ok = 0;
	while (player->map->map[size])
	{
		len = 1;
		while (player->map->map[size][len])
		{
			if (player->map->map[size][len] == '0' && !ok)
			{
				ok = ft_can_locate(player->map->map, size, len);
				if (ok)
				{
					player->map->map[size][len] = 'M';
					player->enemys++;
				}
			}
			len++;
		}
		ok = 0;
		size++;
	}
}

void	ft_start_enemy(t_player *player)
{
	ft_locate_enemys(player);
	ft_paint_actmap(player->data, player->objs, player->map->map);
}
