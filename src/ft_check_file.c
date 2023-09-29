/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:53:49 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/29 19:43:27 by sadoming         ###   ########.fr       */
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

int	ft_check_size(t_map *map)
{
	size_t	act;
	size_t	cnt;

	cnt = 0;
	map->len = ft_strllen(map->map[0]);
	while (map->map[cnt])
	{
		act = ft_strllen(map->map[cnt]);
		if (act == map->len)
			map->size++;
		else
		{
			color('r');
			ft_printf("Error\nMap have diferent sizes!\n");
			return (0);
		}
		cnt++;
	}
	return (1);
}

int	ft_check_sym(t_map *map)
{
	size_t	len;
	size_t	size;

	size = 0;
	while (map->map[size])
	{
		len = 0;
		while (map->map[size][len])
		{
			if (map->map[size][len] == 'C')
				map->coins++;
			else if (map->map[size][len] == 'E')
				map->exits++;
			else if (map->map[size][len] == 'P')
				map->players++;
			else if (map->map[size][len] != '1' && map->map[size][len] != '0')
			{
				ft_printf("\033[1;31mError\nMap contains something wrong!\n");
				return (0);
			}
			len++;
		}
		size++;
	}
	return (1);
}

int	ft_check_minstat(t_map *map)
{
	if (map->exits != 1)
	{
		ft_printf("\033[1;31mError\nThe map don't have exit!\n");
		ft_printf("Or have more than one exit!\n");
		return (0);
	}
	if (map->coins < 1)
	{
		ft_printf("\033[1;31mError\nThe map don't have collectables!\n");
		return (0);
	}
	if (map->players != 1)
	{
		ft_printf("\033[1;31mError\nThe map don't have player!\n");
		ft_printf("Or have more than one player!\n");
		return (0);
	}
	return (1);
}
