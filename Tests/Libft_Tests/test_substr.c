/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:50:53 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/19 18:13:46 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

int	test_substr(void)
{
	int		pass = 1;
	char	*src, *sub, *exp;

	/* Test_1 */
	src = "0123456789";
	sub = ft_substr(src, 4, 3);
	exp = "456";
	if (test_myapp_str(sub, exp) == 0)
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your substr don't work with basic input!\n");
		printf(" Expec: %s\n", exp);
		printf(" Yours: %s\n", sub);
	}
	free(sub);
	/**/
	/* Test_2 */
	sub = ft_substr(src, 0, 20);
	exp = "0123456789";
	if (test_myapp_str(sub, exp) == 0)
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your substr don't work with len > strlen!\n");
		printf(" Expec: %s\n", exp);
		printf(" Yours: %s\n", sub);
	}
	free(sub);
	/**/
	/* Test_3 */
	sub = ft_substr("\0", 0, 1);
	exp = "\0";
	if (test_myapp_str(sub, exp) == 0)
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your substr don't work wth NULL s!\n");
		printf(" Expec: %s\n", exp);
		printf(" Yours: %s\n", sub);
	}
	free(sub);
	/**/
	/* Test_4 */
	sub = ft_substr("LOLLOLOLOLOL", 20, 2);
	exp = "\0";
	if (test_myapp_str(sub, exp) == 0)
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your substr don't work if start > strlen!\n");
		printf(" Expec: %s\n", exp);
		printf(" Yours: %s\n", sub);
	}
	free(sub);
	/**/
	if (pass == 1)
	{
		printf("\033[92m\tOK\n");
		return (1);
	}
	return (0);
}
