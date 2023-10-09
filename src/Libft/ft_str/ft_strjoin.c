/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:11:30 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/09 17:19:56 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * Join the s2 after the s1, and return new string of joined
 * Free the s1 before returning the join
*/
char	*ft_strjoin(char *s1, const char *s2)
{
	int		len;
	int		cnt;
	char	*join;

	join = malloc((ft_strllen(s1) + ft_strllen(s2)) + 1);
	if (!join)
		return (NULL);
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
	free(s1);
	s1 = NULL;
	return (join);
}
