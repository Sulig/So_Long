/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:46:14 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/16 18:17:21 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../Libft/libft.h"
# include "../mlx/mlx.h"
# include "./so_long_structs.h"

void	color(char color);

int		ft_check_format(char *file);
int		ft_check_size(t_map *map);
int		ft_check_sym(t_map *map);
int		ft_check_minstat(t_map *map);
int		ft_check_closed(t_map *map);
int		ft_check_map_sol(t_map *map);

void	ft_paint_map(t_data data, t_objs objs, char **map);
void	ft_start(t_map *map);

void	*ft_free_map(t_map *map);
t_map	*ft_new_map(t_map *map);
t_map	*ft_fill_map(int fd, t_map *map);

#endif
