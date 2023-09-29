/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:24:04 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/19 18:10:52 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

int	test_atoi(void)
{
	int		pass;
	char	*test;

	pass = 1;
	//Test_1:
	test = "1234";
	if (ft_atoi(test) != atoi(test))
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your atoi don't work with basic input!\n");
		printf(" Expec: %i\n", atoi(test));
		printf(" Yours: %i\n", ft_atoi(test));
	}
	//Test_2:
	test = "-1234";
	if (ft_atoi(test) != atoi(test))
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your atoi don't work with negative numbers!\n");
		printf(" Expec: %i\n", atoi(test));
		printf(" Yours: %i\n", ft_atoi(test));
	}
	//Test_3:
	test = "-2147483648";
	if (ft_atoi(test) != atoi(test))
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your atoi don't work with max int\n");
		printf(" Expec: %i\n", atoi(test));
		printf(" Yours: %i\n", ft_atoi(test));
	}
	//Test_4
	test = "-12a-12";
	if (ft_atoi(test) != atoi(test))
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your atoi don't work with special cast\n");
		printf(" Expec: %i\n", atoi(test));
		printf(" Yours: %i\n", ft_atoi(test));
	}
	//Test_5
	test = "1234ascii567";
	if (ft_atoi(test) != atoi(test))
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your atoi find numbers after non digit!\n");
		printf(" Expec: %i\n", atoi(test));
		printf(" Yours: %i\n", ft_atoi(test));
	}
	//Test_6
	test = "   \n\t\e\200\2\5\23-2345  234";
	if (ft_atoi(test) != atoi(test))
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your atoi don't work with non printable before the digit!\n");
		printf(" Expec: %i\n", atoi(test));
		printf(" Yours: %i\n", ft_atoi(test));
	}
	if (pass != 0)
	{
		printf("\033[92m\tOK\n");
		return (1);
	}
	return (0);
}
