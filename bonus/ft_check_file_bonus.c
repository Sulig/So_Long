/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:40:15 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/26 20:22:45 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_format(char *file)
{
	char	*format;
	int		ok;

	ok = 1;
	if (open(file, O_RDONLY) == -1)
	{
		ft_printf("\033[1;31mError\nThis file don't exist!\n");
		ok = 0;
	}
	format = ft_strstr(file, ".ber");
	if (!format && ok)
	{
		ft_printf("\033[1;31mError\nInvalid Extension\n");
		ft_printf("\033[1;33mPlease introduce one file .ber");
		ft_printf(" like this example:\n./so_long map.ber\n");
		ok = 0;
	}
	format = NULL;
	return (ok);
}

int	ft_check_size(t_map *map)
{
	size_t	act;
	size_t	cnt;
	int		ok;

	cnt = 0;
	ok = 1;
	map->len = ft_strllen(map->map[0]);
	while (map->map[cnt])
	{
		map->size++;
		act = ft_strllen(map->map[cnt]);
		if (act != map->len && ok)
		{
			ft_printf("\033[1;31mError\nMap have diferent lenght!\n");
			ok = 0;
		}
		cnt++;
	}
	return (ok);
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

int	ft_check_closed(t_map *map)
{
	int		ok;
	size_t	cnt;
	size_t	len;

	ok = 1;
	cnt = 0;
	while (ok == 1 && map->map[cnt])
	{
		len = 0;
		while (ok == 1 && map->map[cnt][len])
		{
			if (map->map[cnt][len] != '1')
			{
				if (cnt == 0 || cnt == (map->size - 1))
					ok = 0;
				if (len == 0 || len == (ft_strlen(map->map[cnt]) - 1))
					ok = 0;
			}
			len++;
		}
		cnt++;
	}
	if (ok == 0)
		ft_printf("\033[1;31mError\nThe map is not closed!\n");
	return (ok);
}
