/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:21:36 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/14 17:46:31 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

int	test_strrchr(void)
{
	int		pass;
	char	*str;

	pass = 1;
	/**/
	str = "404_9876543210";
	if (ft_strrchr(str, '4') != strrchr(str, '4'))
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your strrchr don't work with basic input!\n");
		printf(" Expec: %s\n", strrchr(str, '4'));
		printf(" Yours: %s\n", ft_strrchr(str, '4'));
	}
	/**/
	str = "Search NULL\0:D";
	if (ft_strrchr(str, 0) != strrchr(str, 0))
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your strrchr don't work with int 0!\n");
		printf(" Expec: %s\n", strrchr(str, 0));
		printf(" Yours: %s\n", ft_strrchr(str, 0));
	}
	/**/
	str = "Don't appear\n";
	if (ft_strrchr(str, '1') != strrchr(str, '1'))
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your strrchr don't return NULL if the int don't appear!\n");
		printf(" Expec: %s\n", strrchr(str, '1'));
		printf(" Yours: %s\n", ft_strrchr(str, '1'));
	}
	/**/
	str = "\0";
	if (ft_strrchr(str, '1') != strrchr(str, '1'))
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your strrchr don't work with NULL str!\n");
		printf(" Expec: %s\n", strrchr(str, '1'));
		printf(" Yours: %s\n", ft_strrchr(str, '1'));
	}
	/**/
	if (pass == 1)
	{
		printf("\033[92m\tOK\n");
		return (1);
	}
	return (0);
}
