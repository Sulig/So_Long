/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:04:10 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/05 16:26:53 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "map_generator.h"

typedef struct	s_lctn
{
	size_t		x;
	size_t		y;
}				t_lctn;

typedef	struct	s_map
{
	char		**map;
	char		**sol;
	size_t		size;
	size_t		len;
	size_t		coins;
	size_t		players;
	size_t		exits;
	t_lctn		start;
	t_lctn		exit;
}				t_map;

#endif
