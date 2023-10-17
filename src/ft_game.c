/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:24:22 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/17 14:30:25 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_man_events(int keycode, t_data data)
{
	if (keycode == ESC)
		ft_exit();
	if (keycode == W)
		return (ft_print_key(keycode));
	return (0);  
}
