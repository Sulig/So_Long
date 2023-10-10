/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:07:49 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/29 17:05:25 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	len;

	len = 0;
	while (s1[len])
		len++;
	cpy = malloc(len + 1);
	if (cpy == 0)
		return (0);
	len = 0;
	while (s1[len])
	{
		cpy[len] = s1[len];
		len++;
	}
	cpy[len] = '\0';
	return (cpy);
}

char	*ft_strcpyl(const char *s1, size_t len)
{
	char	*cpy;
	size_t	cnt;

	if (!s1 || len <= 0)
		return (NULL);
	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	cnt = 0;
	while (cnt < len)
	{
		cpy[cnt] = s1[cnt];
		cnt++;
	}
	cpy[len] = '\0';
	return (cpy);
}
