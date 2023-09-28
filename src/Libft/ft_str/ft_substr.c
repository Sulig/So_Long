/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:52:22 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/27 17:34:33 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	cnt;
	size_t	ln;
	char	*sub;

	ln = ft_strlen(s);
	if (start > ln)
		start = ln;
	if (len >= ft_strlen(s + start))
		len = ft_strlen(s) - start;
	sub = malloc(len + 1);
	if (sub == 0)
		return (0);
	cnt = 0;
	while (cnt < len && s[start])
	{
		sub[cnt] = s[start];
		start++;
		cnt++;
	}
	sub[cnt] = '\0';
	return (sub);
}
