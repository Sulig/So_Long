/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:57:36 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/28 18:03:11 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	cnt;
	size_t	cntn;

	if (needle[0] == 0 || haystack == needle)
		return ((char *) haystack);
	cnt = 0;
	while (haystack[cnt] != '\0')
	{
		cntn = 0;
		while (haystack[cnt] == needle[cntn] && haystack[cnt])
		{
			++cnt;
			++cntn;
		}
		if (needle[cntn] == '\0')
			return ((char *) haystack + (cnt - cntn));
		cnt = cnt - cntn + 1;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cnt;
	size_t	cntn;

	if (needle[0] == 0 || haystack == needle)
		return ((char *) haystack);
	cnt = 0;
	while (cnt < len && haystack[cnt] != '\0')
	{
		cntn = 0;
		while (cnt < len && haystack[cnt] == needle[cntn] && haystack[cnt])
		{
			++cnt;
			++cntn;
		}
		if (needle[cntn] == '\0')
			return ((char *) haystack + (cnt - cntn));
		cnt = cnt - cntn + 1;
	}
	return (NULL);
}
