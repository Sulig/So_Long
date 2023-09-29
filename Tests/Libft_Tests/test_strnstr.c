/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:08:03 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/19 18:10:21 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

int	test_strnstr(void)
{
	int		pass;
	char	*src, *sec;

	pass = 1;
	/**/
	src = "0123456789_Search_0123456789_n.n";
	sec = "45";
	if (ft_strnstr(src, sec, 10) != strnstr(src, sec, 10))
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your strnstr don't work with basic input!\n");
		printf(" Expec: %s\n", strnstr(src, sec, 10));
		printf(" Yours: %s\n", ft_strnstr(src, sec, 10));
	}
	/**/
	sec = "U";
	if (ft_strnstr(src, sec, strlen(src) + 1) != strnstr(src, sec, strlen(src) + 1))
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your strnstr don't return NULL!\n");
		printf(" Expec: %s\n", strnstr(src, sec, strlen(src) + 1));
		printf(" Yours: %s\n", ft_strnstr(src, sec, strlen(src) + 1));
	}
	/**/
	sec = "\0";
	if (ft_strnstr(src, sec, strlen(src) + 1) != strnstr(src, sec, strlen(src) + 1))
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your strnstr don't return the \"haystack\"!\n");
		printf(" Expec: %s\n", strnstr(src, sec, strlen(src) + 1));
		printf(" Yours: %s\n", ft_strnstr(src, sec, strlen(src) + 1));
	}
	/**/
	src = "\0";
	sec = "1";
	if (ft_strnstr(src, sec, 2) != strnstr(src, sec, 1))
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your strnstr don't work with NULL src!\n");
		printf(" Expec: %s\n", strnstr(src, sec, 1));
		printf(" Yours: %s\n", ft_strnstr(src, sec, 1));
	}
	/**/
	if (pass == 1)
	{
		printf("\033[92m\tOK\n");
		return (1);
	}
	return (0);
}
