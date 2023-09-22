/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:06:49 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/21 16:05:25 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	if (s == NULL)
		return (0);
	while (s[cnt])
		cnt++;
	return (cnt);
}

int	gnl_contains(const char *str, char in)
{
	size_t	cnt;

	cnt = 0;
	if (str == NULL)
		return (1);
	while (str[cnt])
	{
		if (str[cnt] == in)
			return (0);
		cnt++;
	}
	return (1);
}

char	*gnl_join(char *s1, const char *s2)
{
	size_t	len;
	size_t	cnt;
	char	*join;

	if (!s1)
		return (gnl_strlcpy(s2, gnl_strlen(s2)));
	join = malloc((gnl_strlen(s1) + gnl_strlen(s2)) + 1);
	if (!join)
		return (gnl_free(s1, 0));
	len = -1;
	cnt = 0;
	while (s1[++len])
		join[len] = s1[len];
	while (s2[cnt])
		join[len++] = s2[cnt++];
	join[len] = '\0';
	free(s1);
	return (join);
}

char	*gnl_strlcpy(const char *s1, size_t len)
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

char	*gnl_strcut(char *str)
{
	char	*trim;
	size_t	cnt;
	size_t	len;
	size_t	size;

	if (!str)
		return (NULL);
	len = 0;
	cnt = gnl_cnt_tojump(str);
	size = gnl_strlen(str + cnt);
	if (size == 0)
		return (gnl_free(str, 0));
	trim = malloc(sizeof(char) * size + 1);
	if (!trim)
		return (gnl_free(str, 0));
	while (str[cnt])
		trim[len++] = str[cnt++];
	trim[len] = '\0';
	free(str);
	return (trim);
}
