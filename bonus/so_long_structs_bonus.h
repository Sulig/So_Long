/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:41 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/02 14:11:06 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_BONUS_H
# define SO_LONG_STRUCTS_BONUS_H

# include "so_long_bonus.h"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

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
	void		*cw;
	void		*wu;
	void		*wd;
	void		*wl;
	void		*wr;
	void		*ul;
	void		*ur;
	void		*dl;
	void		*dr;
	void		*fl;
	void		*pl;
	void		*cl;
	void		*mn;
	void		*ex;
	void		*ep;
	void		*op;
	void		*wn;
}				t_objs;

typedef struct s_anim
{
	int			img_x;
	int			img_y;
	size_t		size;
	void		**sp;
	void		*ac;
}				t_anim;

typedef struct s_text
{
	int			img_x;
	int			img_y;
	void		*tx;
	void		*nl;
	void		*ze;
	void		*on;
	void		*tw;
	void		*tr;
	void		*fo;
	void		*fi;
	void		*si;
	void		*se;
	void		*ei;
	void		*ni;
}				t_text;

typedef struct s_player
{
	t_data		data;
	t_anim		anim_key;
	t_anim		anim_pla;
	t_text		text;
	t_objs		objs;
	t_map		*map;
	t_lcn		act;
	size_t		rem;
	size_t		steps;
	size_t		enemys;
	int			win;
	int			lose;
}				t_player;
#endif
