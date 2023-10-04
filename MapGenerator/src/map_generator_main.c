/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:53:25 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/04 21:02:24 by sadoming         ###   ########.fr       */
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
		ft_printf("\033[1;31mFailed making the file %s!\n", name);
	return (ok);
}

static int	ft_write_in_file(char *file, char **map)
{
	size_t	size;
	size_t	len;
	size_t	fd;
	size_t	check;

	fd = open(file, 1);
	if (fd == -1)
		return (0);
	size = 0;
	while (map[size])
	{
		while (map[size][len])
		{
			check = write(fd, &file[len], 1);
			if (check == -1)
				return (0);
			len++;
		}
		size++;
	}
	return (1);
}

int	main(int argc, char **args)
{
	t_map	*map;
	char	*name;
	int		ok;

	name = "Gen_Map_0";
	if (argc == 2)
		name = args[1];
	name = ft_strjoin(name, ".ber");
	ok = 0;
	//gen_map
	if (ft_gen_file(name))
		ok = ft_write_in_file(name, );
	if (ok)
	{
		ft_printf("\033[1;32mThe map has been generated successfully!\n");
		ft_printf("\nFile name as: %s\n\n", file);
	}
	return (0);
}
