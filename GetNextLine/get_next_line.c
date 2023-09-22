/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:06:43 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/21 16:01:15 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_free(char *to_free, char *tmp)
{
	if (to_free)
		free(to_free);
	to_free = NULL;
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

size_t	gnl_cnt_tojump(const char *str)
{
	size_t	cnt;

	cnt = 0;
	if (!str)
		return (0);
	while (str[cnt] && str[cnt] != '\n')
		cnt++;
	if (str[cnt] == '\n')
		cnt++;
	return (cnt);
}

char	*ft_get_readed(int fd, char *store)
{
	int		btrd;
	char	*tmp;

	btrd = 1;
	tmp = malloc((BUFFER_SIZE) * sizeof(char) + 1);
	if (!tmp)
		return (gnl_free(store, 0));
	while (btrd > 0 && (gnl_contains(store, '\n') != 0))
	{
		btrd = read(fd, tmp, BUFFER_SIZE);
		if (btrd == -1)
			return (gnl_free(store, tmp));
		if (btrd > 0)
		{
			tmp[btrd] = '\0';
			store = gnl_join(store, tmp);
			if (!store)
				return (gnl_free(store, tmp));
		}
	}
	free(tmp);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;
	size_t		cnt;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = ft_get_readed(fd, store);
	if (!store)
		return (gnl_free(store, 0));
	if (gnl_strlen(store) == 0)
	{
		store = gnl_free(store, 0);
		return (NULL);
	}
	cnt = gnl_cnt_tojump(store);
	line = gnl_strlcpy(store, cnt);
	if (!line)
	{
		store = gnl_free(store, 0);
		return (NULL);
	}
	store = gnl_strcut(store);
	return (line);
}
