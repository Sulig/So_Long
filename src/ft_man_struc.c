/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_man_struc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:43:27 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/29 19:05:40 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*ft_new_map(t_map *map)
{
	map = malloc(sizeof(t_map) * 1);
	if (!map)
		return (NULL);
	map->map = NULL;
	map->len = 0;
	map->size = 0;
	map->coins = 0;
	map->exits = 0;
	map->players = 0;
	return (map);
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
	return (map);
}
