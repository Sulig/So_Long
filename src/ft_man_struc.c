/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_man_struc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:43:27 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/03 20:26:28 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_free_map(t_map *map)
{
	size_t	cnt;

	cnt = 0;
	while (map->map[--map->size])
		free(map->map[map->size]);
	free(map->map);
	free(map);
	return (NULL);
}

t_map	*ft_new_map(t_map *map)
{
	map = malloc(sizeof(t_map) * 1);
	if (!map)
		return (NULL);
	map->map = NULL;
	map->sol = NULL;
	map->len = 0;
	map->size = 0;
	map->coins = 0;
	map->exits = 0;
	map->players = 0;
	map->act.x_pos = 0;
	map->act.y_pos = 0;
	return (map);
}

static int	ft_fill_sol(t_map *map)
{
	size_t	len;
	size_t	size;

	size = 0;
	map->sol = ft_calloc(sizeof(char *), map->size);
	if (!map->sol)
		return (0);
	while (map->map[size])
	{
		len = 0;
		map->sol[size] = ft_strdup(map->map[size]);
		while (map->sol[size][len])
		{
			if (map->sol[size][len] == 'C' || map->sol[size][len] == 'P')
				map->sol[size][len] = '0';
			if (map->sol[size][len] == 'E')
				map->sol[size][len] = '0';
			len++;
		}
		size++;
	}
	ft_print_sol_t(map->sol);
	return (1);
}

t_map	*ft_fill_map(int fd, t_map *map)
{
	char	*file;
	char	*tmp;

	file = NULL;
	tmp = get_next_line(fd);
	while (tmp)
	{
		file = ft_strjoin(file, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	map->map = ft_split(file, '\n');
	if (map)
		if (ft_fill_sol(map))
			return (map);
	return (NULL);
}
