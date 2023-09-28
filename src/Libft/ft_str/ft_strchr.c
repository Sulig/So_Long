/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:40:59 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/27 20:15:31 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * Search the first ocurrence of c in s.
 * Return the s + the pos where encountered the c
 * Or NULL if not.
*/

char	*ft_strchr(const char *s, int c)
{
	int		len;
	int		pos;

	len = 0;
	if (!s)
		return (NULL);
	while (s[len])
		len++;
	pos = 0;
	while (pos <= len)
	{
		if ((unsigned char) s[pos] == (unsigned char) c)
			return ((char *) s + pos);
		pos++;
	}
	return (NULL);
}

/*
 * Search the last ocurrence of c in s.
 * Return the s + the pos where encountered the last c
 * Or NULL if not.
*/

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = 0;
	if (!s)
		return (NULL);
	while (s[len] != '\0')
		len++;
	while (len >= 0)
	{
		if ((unsigned char) s[len] == (unsigned char) c)
			return ((char *) s + len);
		len--;
	}
	return (NULL);
}
