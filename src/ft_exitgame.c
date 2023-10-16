/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exitgame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:34:27 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/16 20:34:32 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(void)
{
	exit(0);
}

void	ft_exit_with_key(int keycode, t_data data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}
