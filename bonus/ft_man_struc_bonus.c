/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_man_struc_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:46:44 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/26 19:47:33 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init(t_map *map)
{
	map->players = 0;
	map->exits = 0;
	map->coins = 0;
	map->start.x = 0;
	map->start.y = 0;
	map->exit.x = 0;
	map->exit.y = 0;
}

void	ft_fill_sol(t_map *map)
{
	size_t	len;
	size_t	size;

	size = 0;
	while (map->sol[size])
	{
		len = 0;
		while (map->sol[size][len])
		{
			if (map->map[size][len] != '1')
				map->sol[size][len] = '0';
			len++;
		}
		size++;
	}
}

void	*ft_free_map(t_map *map)
{
	if (map->map)
		map->map = ft_free_arr(map->size, map->map);
	if (map->sol)
		map->sol = ft_free_arr(map->size, map->sol);
	ft_init(map);
	free(map);
	return (NULL);
}

t_map	*ft_fill_map(int fd, t_map *map)
{
	char	*file;
	char	*tmp;

	file = NULL;
	tmp = get_next_line(fd);
	if (!tmp)
		ft_printf("\033[1;31mError\nSomething went wrong!\n");
	while (tmp)
	{
		file = ft_strjoin(file, tmp);
		free(tmp);
		tmp = NULL;
		tmp = get_next_line(fd);
	}
	if (file)
		map->map = ft_split(file, '\n');
	if (!map->map)
		return (NULL);
	map->sol = ft_split(file, '\n');
	if (!map->sol)
		return (NULL);
	ft_fill_sol(map);
	free(file);
	return (map);
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
	ft_init(map);
	return (map);
}
