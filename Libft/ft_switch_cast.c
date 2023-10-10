/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch_cast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:47:28 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/27 20:27:08 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int		ret;
	int		cnt;

	ret = 0;
	cnt = -1;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[++cnt])
	{
		if (write(1, &str[cnt], 1) == -1)
			return (-1);
		ret++;
	}
	return (ret);
}

int	ft_putnbr(int nbr)
{
	char	*str;
	int		ret;

	str = ft_itoa(nbr);
	ret = ft_putstr(str);
	free(str);
	return (ret);
}

int	ft_putunsig(size_t nbr, char cast)
{
	char	*str;
	int		ret;
	int		save;

	save = 0;
	if (cast == 'p')
		save = ft_putstr("0x");
	if (save == -1)
		return (save);
	str = ft_unsig_tobase(nbr, cast);
	ret = ft_putstr(str);
	free(str);
	if (ret == -1)
		return (ret);
	return (ret + save);
}
