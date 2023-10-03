/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_sol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:13:15 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/03 14:21:54 by sadoming         ###   ########.fr       */
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

static char	*ft_fill_sol(t_map *map)
{
	size_t	len;
	size_t	size;

	size = 0;
	map->sol = ft_calloc(sizeof(char *), map->size);
	if (!map->sol)
		return (NULL);
	while (map->map[size])
	{
		len = 0;
		map->sol[size] = ft_strdup(map->map[size]);
		while (map->sol[size][len])
		{
			if (map->sol[size][len] == 'C')
				map->sol[size][len] == '0';
			len++;
		}
	}
}

int	ft_check_all(t_map *map)
{
	t_location	coin;
	int			ok;
	size_t		len;
	size_t		size;

	ok = 1;
	size = 0;
	while (map->map[size] && ok == 1)
	{
		len = 0;
		while (map->map[size][len] && ok == 1)
		{
			if (map->map[size][len] == 'C')
				ok = 1;
			len++;
		}
		size++;
	}
	return (ok);
}

int	ft_check_map_sol(t_map *map)
{
	ft_locate(map);
	if (ft_check_all(map))
		return (1);
	else
	{
		ft_printf("\033[1;31mError\nThe map don't have solution!\n");
		return (0);
	}
}
