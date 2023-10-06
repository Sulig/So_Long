/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:54:41 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/06 14:06:50 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_GENERATOR_H
# define MAP_GENERATOR_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "./Libft/libft.h"
# include "./structs.h"

void	ft_print_stat(t_map *map);
void	ft_print_map_t(char **map);

void	ft_init(t_map *map);
void	ft_fill_sol(t_map *map);

int		ft_check_behind(char **map, t_lctn check, char cmp);
int		ft_check_map_sol(t_map *map);

char	**ft_create_arr(size_t max_size, size_t max_len);

void	*ft_free_map(t_map *map);
t_map	*ft_new_map(t_map *map, size_t seed);
t_map	*ft_gen_map(t_map *map, size_t seed);

#endif
