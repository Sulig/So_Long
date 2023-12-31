/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exitgame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:34:27 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/17 13:22:12 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(void)
{
	exit(0);
	return (0);
}

int	ft_print_key(int keycode)
{
	ft_printf("\n~ Key down: |%i| ~\n", keycode);
	return (0);
}
