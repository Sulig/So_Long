/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:45:41 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/06 16:47:37 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include "../Libft/libft.h"
# include "../mlx/mlx.h"
# include "./so_long_structs_bonus.h"

int		ft_check_format(char *file);
int		ft_check_size(t_map *map);
int		ft_check_sym(t_map *map);
int		ft_check_minstat(t_map *map);
int		ft_check_closed(t_map *map);
int		ft_check_map_sol(t_map *map);

void	ft_print_stat(t_map *map);
void	ft_print_map_t(char **map);

void	ft_start(t_map *map);
void	ft_start_enemy(t_player *player);
void	ft_act_stat(t_player *player);
void	ft_move_bat(t_player *player);
void	ft_update(t_player player);
void	ft_lose_game(t_player *player);
void	ft_win_game(t_player *player);

void	ft_style_map(t_player *player);
void	ft_paint_actmap(t_data data, t_objs obj, char **map);

void	ft_start_anims(t_player *player);
void	ft_start_anim_enemy(t_player *player);
void	ft_start_anim_keys(t_player *player);
void	ft_start_anim_player(t_player *player);
void	ft_anim_player(t_player *player);
void	ft_animate_key(t_player *player);
void	ft_animate_bat(t_player *player);

int		ft_on_keydown(int keycode, t_player *player);
int		ft_print_key(int keycode);
int		ft_exit(void);

void	*ft_free_map(t_map *map);
t_map	*ft_new_map(t_map *map);
t_map	*ft_fill_map(int fd, t_map *map);
t_text	ft_init_text(t_player *player);

#endif
