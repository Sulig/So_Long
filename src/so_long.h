/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:46:14 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/29 19:40:58 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "./Libft/libft.h"

typedef struct	s_map
{
	char		**map;
	size_t		len;
	size_t		size;
	size_t		coins;
	size_t		exits;
	size_t		players;
}				t_map;

void	color(char color);

int		ft_check_format(char *file);
int		ft_check_size(t_map *map);
int		ft_check_sym(t_map *map);
int		ft_check_minstat(t_map *map);

t_map	*ft_new_map(t_map *map);
t_map	*ft_fill_map(int fd, t_map *map);
void	ft_print_map_t(t_map *map);

#endif
