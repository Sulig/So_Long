/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:58:59 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/09 16:59:42 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	color(char color)
{
	if (color == 'R' || color == 'r')
		ft_printf("\033[1;31m");
	else if (color == 'G' || color == 'g')
		ft_printf("\033[1;32m");
	else if (color == 'Y' || color == 'y')
		ft_printf("\033[1;33m");
	else if (color == 'B' || color == 'b')
		ft_printf("\033[1;34m");
	else if (color == 'M' || color == 'm')
		ft_printf("\033[1;35m");
	else if (color == 'C' || color == 'c')
		ft_printf("\033[1;36m");
	else if (color == 'W' || color == 'w')
		ft_printf("\033[1;37m");
	else
		ft_printf("\033[1;39m");
}
