/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:16:49 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/29 17:44:26 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	ln;
	size_t	cnt;

	if (s1[0] == '\0')
		return (ft_strcpyl("", 0));
	if (set[0] == '\0')
		return (ft_strcpyl((char *)s1, ft_strllen(s1)));
	ln = 0;
	while (s1[ln])
	{
		if (ft_strchr(set, s1[ln]) != 0)
			break ;
		ln++;
	}
	cnt = 0;
	while (s1[cnt + 1])
		cnt++;
	while (cnt >= 0)
	{
		if (ft_strchr(set, s1[cnt]) != 0)
			break ;
		cnt--;
	}
	return (ft_strcpyl((char *) s1 + ln, (cnt + 1) - ln));
}
