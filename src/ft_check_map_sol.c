/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_sol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:13:15 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/06 18:32:17 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_locate(t_map *map)
{
	size_t		len;
	size_t		size;

	size = 0;
	while (map->map[size])
	{
		len = 0;
		while (map->map[size][len])
		{
			if (map->map[size][len] == 'P')
			{
				map->start.x_pos = len;
				map->start.y_pos = size;
			}
			if (map->map[size][len] == 'E')
			{
				map->exit.x_pos = len;
				map->exit.y_pos = size;
			}
			len++;
		}
		size++;
	}
}

static void	ft_path(char **fill, t_lcn size, size_t y, size_t x)
{
	if (y < 0 || x < 0)
		return ;
	if (y == size.y_pos && x == size.x_pos)
	{
		if (fill[y][x])
			fill[y][x] = '+';
		return ;
	}
	if (fill[y][x] != '0')
		return ;
	if (fill[y][x])
		fill[y][x] = '+';
	ft_path(fill, size, y, x + 1);
	ft_path(fill, size, y, x - 1);
	ft_path(fill, size, y - 1, x);
	ft_path(fill, size, y + 1, x);
}

static	int	ft_check_behind(char **map, t_lcn checkpoint)
{
	if (map[checkpoint.y_pos][checkpoint.x_pos + 1] == '+')
		return (1);
	if (map[checkpoint.y_pos][checkpoint.x_pos - 1] == '+')
		return (1);
	if (map[checkpoint.y_pos + 1][checkpoint.x_pos] == '+')
		return (1);
	if (map[checkpoint.y_pos - 1][checkpoint.x_pos] == '+')
		return (1);
	return (0);
}

int	ft_check_for_sol(t_map *map)
{
	int		ok;
	size_t	size;
	size_t	len;
	t_lcn	coin;

	ft_path(map->sol, map->exit, map->start.y_pos, map->start.x_pos);
	ok = ft_check_behind(map->sol, map->exit);
	size = 0;
	while (map->map[size] && ok == 1)
	{
		len = 0;
		while (map->map[size][len] && ok == 1)
		{
			if (map->map[size][len] == 'C')
			{
				coin.x_pos = len;
				coin.y_pos = size;
				ok = ft_check_behind(map->sol, coin);
			}
			len++;
		}
		size++;
	}
	return (ok);
}

int	ft_check_map_sol(t_map *map)
{
	int		ok;

	ft_locate(map);
	ok = 0;
	if (ft_check_for_sol(map))
		ok = 1;
	if (ok == 0)
		ft_printf("\033[1;31mError\nThe map don't have solution!\n");
	return (ok);
}
