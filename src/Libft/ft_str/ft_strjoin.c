/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:11:30 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/27 20:21:41 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len;
	int		cnt;
	char	*join;

	join = malloc((ft_strllen(s1) + ft_strllen(s2)) + 1);
	if (!join)
		return (0);
	len = 0;
	cnt = 0;
	if (s1)
		while (s1[cnt])
			join[len++] = s1[cnt++];
	cnt = 0;
	if (s2)
		while (s2[cnt])
			join[len++] = s2[cnt++];
	join[len] = '\0';
	return (join);
}
