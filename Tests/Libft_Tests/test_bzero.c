/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:50:15 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/19 18:19:49 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_1(void)
{
	char	*inip, *youp;
	char	ini[30] = "123456";
	char	you[30] = "123456";

	inip = ini;
	youp = you;
	bzero(ini, strlen(ini));
	ft_bzero(you, strlen(you));
	if (test_myapp_str(youp, inip) == 0)
	{
		printf("\033[91m\tKO!\n Your bzero don't work with basic input!\n");
		printf(" Tested: [30]\"123456\", strlen(you)\n");
		return (0);
	}
	return (1);
}

static int  test_2(void)
{
	char	*inip, *youp;
	char	ini[30] = "\0";
	char	you[30] = "\0";

	inip = ini;
	youp = you;
	bzero(ini, 1);
	ft_bzero(you, 1);
	if (test_myapp_str(youp, inip) == 0)
	{
		printf("\033[91m\tKO!\n Your bzero don't work with NULL src!\n");
		printf(" Expec: %s\n", ini);
		printf(" Yours: %s\n", you);
		return (0);
	}
	return (1);
}

static int	test_3(void)
{
	char	*inip, *youp;
	char	ini[30] = "NNNNNN";
	char	you[30] = "NNNNNN";

	inip = ini;
	youp = you;
	bzero(ini, 30);
	ft_bzero(you, 40);
	if (test_myapp_str(youp, inip) == 0)
	{
		printf("\033[91m\tKO!\n Your bzero don't work with len > strlen!\n");
		printf(" Tested: [30]\"NNNNNN\", 40\n");
		return (0);
	}
	return (1);
}

int	test_bzero(void)
{
	int		t1, t2, t3;

	t1 = test_1();
	t2 = test_2();
	t3 = test_3();
	if (t1 == 1 && t2 == 1 && t3 == 1)
	{
		printf("\033[92m\tOK\n");
		return (1);
	}
	return (0);
}
