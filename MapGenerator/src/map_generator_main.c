/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:53:25 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/18 14:25:51 by sadoming         ###   ########.fr       */
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
	while (map->map[size])
	{
		len = 0;
		while (map->map[size][len])
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

t_map	*gen_new_map(size_t num, t_map *map, size_t seed)
{
	char	*str;
	char	*name;
	int		ok;

	ok = 0;
	srand(seed);
	str = ft_itoa_unsig(num, "0123456789");
	name = ft_strinter("Generated_Map_.ber", str, 14);
	map = ft_new_map(map, seed);
	if (map)
		map = ft_gen_map(map, seed);
	if (map)
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
	free(str);
	free(name);
	return (map);
}

size_t	ft_range(size_t seed)
{
	size_t	cnt;
	size_t	com[25] = {6, 13, 19, 26, 39, 41, 45, 76, 86, 91, 104, 110, 117, 123, 130, 143};
	com[16] = 154;
	com[17] = 156;
	com[18] = 162;
	com[19] = 169;
	com[20] = 181;
	com[21] = 188;
	com[22] = 201;
	com[23] = 98;
	com[24] = 182;
	cnt = 0;
	while (cnt < 25)
	{
		if (seed == com[cnt] || seed > 200)
		{
			seed = (rand() % 200);
			srand(seed);
			seed = ft_range(seed);
		}
		cnt++;
	}
	return (seed);
}

int	main(int argc, char **args)
{
	int				num;
	int				cnt;
	static size_t	seed;
	t_map			**map;

	num = 0;
	map = NULL;
	if (argc == 2)
		num = ft_atoi(args[1]);
	if (num > 0)
		map = ft_calloc(++num, sizeof(t_map *));
	if (map)
	{
		cnt = 0;
		while (cnt < num)
		{
			seed = (num + rand() % 200);
			srand(seed);
			seed = ft_range(seed);
			ft_printf("Seed: %u\n", seed);
			map[cnt] = gen_new_map(cnt, map[cnt], seed);
			cnt++;
		}
		cnt--;
		while (cnt > -1)
		{
			map[cnt] = ft_free_map(map[cnt]);
			cnt--;
		}
		free(map);
		map = NULL;
	}
	exit(0);
}
