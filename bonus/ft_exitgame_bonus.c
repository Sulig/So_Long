/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exitgame_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:43:35 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/26 19:43:58 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
