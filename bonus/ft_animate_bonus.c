/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:23:28 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/03 13:22:19 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_animate(t_player *player)
{
	ft_anim_player(player);
	ft_animate_key(player);
	ft_animate_bat(player);
	ft_move_bat(player);
	return (0);
}

void	ft_start_anims(t_player *player)
{
	ft_start_anim_player(player);
	ft_start_anim_keys(player);
	ft_start_anim_enemy(player);
	mlx_loop_hook(player->data.mlx, ft_animate, player);
}
