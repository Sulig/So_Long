/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:12:32 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/29 17:56:21 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strcut(char *str, char cut, char mode, char inc)
{
	if (!str)
		return (NULL);
	if (mode == '<')
	{
		if (inc == 'y' || inc == 'Y')
			str[ft_cnttoch_in(str, cut)] = '\0';
		else
			str[ft_cnttoch_out(str, cut)] = '\0';
	}
	else if (mode == '>')
	{
		if (inc == 'y' || inc == 'Y')
			return (str + ft_cnttoch_out(str, cut));
		else
			return (str + ft_cnttoch_out(str, cut));
	}
	return (str);
}
