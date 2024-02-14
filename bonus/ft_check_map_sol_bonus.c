/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_sol_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:42:48 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/14 18:23:59 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
				map->start.x = len;
				map->start.y = size;
			}
			if (map->map[size][len] == 'E')
			{
				map->exit.x = len;
				map->exit.y = size;
			}
			len++;
		}
		size++;
	}
}

static void	ft_path(char **fill, t_lcn size, size_t y, size_t x)
{
	if (y == size.y && x == size.x)
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
	if (map[checkpoint.y][checkpoint.x + 1] == '+')
		return (1);
	if (map[checkpoint.y][checkpoint.x - 1] == '+')
		return (1);
	if (map[checkpoint.y + 1][checkpoint.x] == '+')
		return (1);
	if (map[checkpoint.y - 1][checkpoint.x] == '+')
		return (1);
	return (0);
}

int	ft_check_for_sol(t_map *map)
{
	int		ok;
	size_t	size;
	size_t	len;
	t_lcn	coin;

	ft_path(map->sol, map->exit, map->start.y, map->start.x);
	ok = ft_check_behind(map->sol, map->exit);
	size = 0;
	while (map->map[size] && ok == 1)
	{
		len = 0;
		while (map->map[size][len] && ok == 1)
		{
			if (map->map[size][len] == 'C')
			{
				coin.x = len;
				coin.y = size;
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
