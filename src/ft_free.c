/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:37:35 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/28 19:39:39 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_free_map(char **map)
{
	size_t	cnt;

	cnt = 0;
	while (map[cnt++])
		free(map[cnt]);
	free(map);
	return (NULL);
}
