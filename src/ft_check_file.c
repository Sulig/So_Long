/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:53:49 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/28 20:29:02 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_format(char *file)
{
	char	*format;

	format = ft_strstr(file, ".ber");
	if (!format)
	{
		color('r');
		ft_printf("Error\nInvalid Extension\n");
		color('y');
		ft_printf("Please introduce one file .ber");
		ft_printf(" like this example:\n./so_long map.ber\n");
		return (0);
	}
	else
		return (1);
}

size_t	ft_check_size(int fd)
{
	char	*line;
	size_t	len;
	size_t	size;

	size = 0;
	line = get_next_line(fd);
	len = ft_cnttoch_out(line, '\n');
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			if (ft_cnttoch_out(line, '\n') == len)
				size++;
			else
			{
				free(line);
				color('r');
				ft_printf("Error\nInvalid Map\nThis map have diferent sizes\n");
				return (0);
			}
		}
	}
	return (size);
}

t_map	*fill_map(int fd, size_t size)
{
	t_map	*map;
	size_t	cnt;

	ft_printf("Size |%u|\n", size);
	map = malloc(sizeof(t_map) * 1);
	if (!map)
		return (NULL);
	map->map = ft_calloc(size + 1, sizeof(char *));
	if (!map)
		return (NULL);
	cnt = 0;
	while (cnt++ < size)
	{
		map->map[cnt] = get_next_line(fd);
		map->map[cnt] = ft_strtrim(map->map[cnt], "\n");
		ft_printf("Line: |%s|\n", map->map[cnt]);
	}
	return (map);
}
