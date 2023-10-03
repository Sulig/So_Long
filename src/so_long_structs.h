/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:04:36 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/03 14:08:13 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H

# include "so_long.h"

typedef	struct	s_location
{
	size_t		x_pos;
	size_t		y_pos;
}				t_location;

typedef struct	s_map
{
	char		**map;
	char		**sol;
	size_t		len;
	size_t		size;
	size_t		coins;
	size_t		exits;
	size_t		players;
	t_location	start;
	t_location	exit;
	t_location	act;
}				t_map;

#endif
