/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:06:43 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/29 17:44:41 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*gnl_free(char *to_free, char *tmp)
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

static char	*gnl_strcut(char *str, int ch)
{
	char	*cut;
	size_t	cnt;
	size_t	len;
	size_t	size;

	if (!str)
		return (NULL);
	len = 0;
	cnt = ft_cnttoch_in(str, ch);
	size = ft_strllen(str + cnt);
	if (size == 0)
		return (gnl_free(str, 0));
	cut = malloc(sizeof(char) * size + 1);
	if (!cut)
		return (gnl_free(str, 0));
	while (str[cnt])
		cut[len++] = str[cnt++];
	cut[len] = '\0';
	free(str);
	return (cut);
}

static char	*get_readed(int fd, char *store)
{
	int		btrd;
	char	*tmp;

	btrd = 1;
	tmp = malloc((BUFFER_SIZE) * sizeof(char) + 1);
	if (!tmp)
		return (gnl_free(store, 0));
	while (btrd > 0 && (ft_strchr(store, '\n') == NULL))
	{
		btrd = read(fd, tmp, BUFFER_SIZE);
		if (btrd == -1)
			return (gnl_free(store, tmp));
		if (btrd > 0)
		{
			tmp[btrd] = '\0';
			store = ft_strjoin(store, tmp);
			if (!store)
				return (gnl_free(store, tmp));
		}
	}
	free(tmp);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store[4096];
	char		*line;
	size_t		cnt;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store[fd] = get_readed(fd, store[fd]);
	if (!store[fd])
		return (gnl_free(store[fd], 0));
	if (ft_strllen(store[fd]) == 0)
	{
		store[fd] = gnl_free(store[fd], 0);
		return (NULL);
	}
	cnt = ft_cnttoch_in(store[fd], '\n');
	line = ft_strcpyl(store[fd], cnt);
	if (!line)
	{
		store[fd] = gnl_free(store[fd], 0);
		return (NULL);
	}
	store[fd] = gnl_strcut(store[fd], '\n');
	return (line);
}
