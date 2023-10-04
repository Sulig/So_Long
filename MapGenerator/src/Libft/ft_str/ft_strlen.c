/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:15:53 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/28 19:16:30 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

size_t	ft_strllen(const char *s)
{
	size_t	counter;

	counter = 0;
	if (!s)
		return (0);
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

size_t	ft_cnttoch_in(const char *str, char c)
{
	size_t	cnt;

	cnt = 0;
	if (!str)
		return (0);
	while (str[cnt] && str[cnt] != c)
		cnt++;
	if (str[cnt] == c)
		cnt++;
	return (cnt);
}

size_t	ft_cnttoch_out(const char *str, char c)
{
	size_t	cnt;

	cnt = 0;
	if (!str)
		return (0);
	while (str[cnt] && str[cnt] != c)
		cnt++;
	return (cnt);
}
