/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:07:25 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/19 18:09:41 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

int	test_strchr(void)
{
	int		pass;
	char	*str;

	pass = 1;
	/**/
	str = "0123456789_404";
	if (ft_strchr(str, '4') != strchr(str, '4'))
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your strchr don't work with basic input!\n");
		printf(" Expec: %s\n", strchr(str, '4'));
		printf(" Yours: %s\n", ft_strchr(str, '4'));
	}
	/**/
	str = "Search NULL\0:D";
	if (ft_strchr(str, 0) != strchr(str, 0))
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your strchr don't work with int 0!\n");
		printf(" Expec: %s\n", strchr(str, 0));
		printf(" Yours: %s\n", ft_strchr(str, 0));
	}
	/**/
	str = "Don't appear\n";
	if (ft_strchr(str, '1') != strchr(str, '1'))
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your strchr don't return NULL if the int don't appear!\n");
		printf(" Expec: %s\n", strchr(str, '1'));
		printf(" Yours: %s\n", ft_strchr(str, '1'));
	}
	/**/
	str = "\0";
	if (ft_strchr(str, '1') != strchr(str, '1'))
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your strchr don't work with NULL str!\n");
		printf(" Expec: %s\n", strchr(str, '1'));
		printf(" Yours: %s\n", ft_strchr(str, '1'));
	}
	/**/
	if (pass == 1)
	{
		printf("\033[92m\tOK\n");
		return (1);
	}
	return (0);
}
