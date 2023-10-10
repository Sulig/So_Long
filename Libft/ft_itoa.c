/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:44:32 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/27 20:29:40 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_unsig_tobase(size_t num, char base)
{
	if (base == 'u' || base == 'd')
		return (ft_itoa_unsig(num, "0123456789"));
	else if (base == 'b' || base == 'B')
		return (ft_itoa_unsig(num, "01"));
	else if (base == 'o' || base == 'O')
		return (ft_itoa_unsig(num, "01234567"));
	else if (base == 'x' || base == 'p')
		return (ft_itoa_unsig(num, "0123456789abcdef"));
	else if (base == 'X')
		return (ft_itoa_unsig(num, "0123456789ABCDEF"));
	else
		return (ft_itoa_unsig(num, "0123456789"));
}

size_t	ft_numlen(size_t n, int base)
{
	size_t		cnt;

	cnt = 0;
	while (n > 0)
	{
		cnt++;
		n /= base;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*base;
	int		cnt;
	long	num;

	cnt = 0;
	num = (long) n;
	base = "0123456789";
	if (n <= 0)
	{
		num *= -1;
		cnt++;
	}
	cnt += ft_numlen(num, 10);
	str = calloc(cnt + 1, 1);
	if (!str)
		return (0);
	while (cnt > 0)
	{
		str[--cnt] = base[num % 10];
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_unsig(size_t num, char *base)
{
	char	*str;
	size_t	cnt;

	cnt = 0;
	if (num == 0)
		cnt++;
	cnt += ft_numlen(num, ft_strlen(base));
	str = calloc(cnt + 1, 1);
	if (!str)
		return (0);
	while (cnt > 0)
	{
		str[--cnt] = base[num % ft_strlen(base)];
		num /= ft_strlen(base);
	}
	return (str);
}
