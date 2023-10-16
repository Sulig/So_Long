/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:04:36 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/16 19:45:56 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H

# include "so_long.h"

typedef struct s_lcn
{
	size_t		x;
	size_t		y;
}				t_lcn;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*wimg;
	char	*adr;
	int		btpx;
	int		ln;
	int		end;
	size_t	size;
	size_t	len;
}				t_data;

typedef struct s_map
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
}				t_map;

typedef struct s_objs
{
	int			img_x;
	int			img_y;
	void		*wl;
	void		*fl;
	void		*pl;
	void		*cl;
	void		*ex;
}				t_objs;

typedef struct s_player
{
	char		**act_map;
	t_lcn		act;
	size_t		recol;
	size_t		steps;
}				t_player;
#endif
