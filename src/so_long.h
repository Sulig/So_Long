/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:46:14 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/28 20:28:40 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "./Libft/libft.h"

typedef struct	s_map
{
	char		**map;
}				t_map;

void	color(char color);

int		ft_check_format(char *file);
size_t	ft_check_size(int fd);

t_map	*fill_map(int fd, size_t size);

#endif
