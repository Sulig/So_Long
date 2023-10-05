/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:53:25 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/05 20:24:07 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_generator.h"

static int	ft_gen_file(char *file)
{
	int		ok;

	ok = 0;
	if (fopen(file, "w"))
		ok = 1;
	if (ok == 0)
		ft_printf("\033[1;31mFailed making the file %s!\n", file);
	return (ok);
}

static int	ft_write_in_file(char *file, t_map *map)
{
	size_t	size;
	size_t	len;
	int		fd;
	int		check;

	fd = open(file, 1);
	if (fd == -1)
		return (0);
	size = 0;
	while (size <= map->size)
	{
		len = 0;
		while (len <= map->len)
		{
			check = write(fd, &map->map[size][len], 1);
			if (check == -1)
				return (0);
			len++;
		}
		write(fd, "\n", 1);
		size++;
	}
	close(fd);
	return (1);
}

/*
 * Regenerate the map of a existent file
*/
void	regenerate_map(char *file)
{
	static size_t	seed;
	t_map			*map;
	int				ok;

	ok = 0;
	seed = (rand() % 500);
	map = NULL;
	map = ft_new_map(map);
	if (map)
		map = ft_gen_map(map);
	if (map->map)
		ok = ft_write_in_file(file, map);
	if (ok)
	{
		ft_printf("\033[1;32mThe map has been regenerated successfully!\n");
		ft_printf("\nFile name as: %s\n\n", file);
		ft_printf("\033[1;33m ~\tSeed: |%u|\n", seed);
		ft_print_stat(map);
	}
	srand(seed++);
	if (ok == 0)
		regenerate_map(file);
}

/*
 * Generate a Random map
*/
void	gen_new_map(void)
{
	static size_t	num;
	static size_t	seed;
	char			*str;
	char			*name;
	t_map			*map;
	int				ok;

	ok = 0;
	map = NULL;
	name = "Generated_Map_";
	str = ft_itoa_unsig(num, "012345676789");
	name = ft_strjoin(name, str);
	name = ft_strjoin(name, ".ber");
	map = ft_new_map(map);
	if (map)
		map = ft_gen_map(map);
	if (map->map)
		if (ft_gen_file(name))
			ok = ft_write_in_file(name, map);
	if (ok)
	{
		ft_printf("\033[1;32mThe map has been generated successfully!\n");
		ft_printf("\nFile name as: %s\n\n", name);
		ft_printf("\033[1;33m ~\tSeed: |%u|\n", seed);
		ft_print_stat(map);
	}
	num++;
	srand(seed++);
	if (ok == 0)
		regenerate_map(name);
}

int	main(int argc, char **args)
{
	int	num;
	int	cnt;

	num = 0;
	if (argc == 2)
		num = ft_atoi(args[1]);
	if (num == 0)
		num++;
	cnt = 1;
	while (cnt++ <= num)
		gen_new_map();
	return (0);
}
