/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:30:26 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/19 18:16:48 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

int	test_itoa(void)
{
	int		pass = 1;
	char	*exp, *you;

	/* Test_1 */
	you = ft_itoa(12345);
	exp = "12345";
	if (test_myapp_str(you, exp) == 0)
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your itoa don't work with basic input!\n");
		printf(" Expec: %s\n", exp);
		printf(" Yours: %s\n", you);
	}
	free(you);
	/**/
	/* Test_2 */
	you = ft_itoa(-12345);
	exp = "-12345";
	if (test_myapp_str(you, exp) == 0)
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your itoa don't work with negative numbers!\n");
		printf(" Expec: %s\n", exp);
		printf(" Yours: %s\n", you);
	}
	free(you);
	/**/
	/* Test_3 */
	you = ft_itoa(-2147483648);
	exp = "-2147483648";
	if (test_myapp_str(you, exp) == 0)
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your itoa don't work with INTMIN!\n");
		printf(" Expec: %s\n", exp);
		printf(" Yours: %s\n", you);
	}
	free(you);
	/**/
	/* Test_4 */
	you = ft_itoa(-0);
	exp = "0";
	if (test_myapp_str(you, exp) == 0)
	{
		pass = 0;
		printf("\033[91m\tKO!\n your itoa don't work with -0!\n");
		printf(" Expec: %s\n", exp);
		printf(" Yours: %s\n", you);
	}
	free(you);
	/**/
	/* Test_5 */
	you = ft_itoa(-2147483648 + 1);
	exp = "-2147483647";
	if (test_myapp_str(you, exp) == 0)
	{
		pass = 0;
		printf("\033[91m\tKO!\n");
		printf(" Expec: %s\n", exp);
		printf(" Yours: %s\n", you);
	}
	free(you);
	/**/
	if (pass == 1)
		printf("\033[92m\tOK\n");
	return (pass);
}
