/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:04:36 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/09 16:51:45 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H

# include "so_long.h"

typedef	struct	s_lcn
{
	size_t		x;
	size_t		y;
}				t_lcn;

typedef struct	s_map
{
	char		**map;
	char		**sol;
	size_t		len;
	size_t		size;
	size_t		coins;
	size_t		exits;
	size_t		players;
	t_lcn		start;
	t_lcn		exit;
	t_lcn		act;
}				t_map;

#endif
