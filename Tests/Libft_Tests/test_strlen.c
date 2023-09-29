/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:56:29 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/14 17:44:24 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_1(void)
{
	char	*str = "0123456789";

	if (ft_strlen(str) == strlen(str))
		return (1);
	return (0);
}

static int	test_2(void)
{
	char	*str = "\200\t\12\n\15\1\e\0";

	if (ft_strlen(str) == strlen(str))
		return (1);
	return (0);
}

static int	test_3(void)
{
	char	*null = "\0";

	if (ft_strlen(null) == strlen(null))
		return (1);
	return (0);
}

int	test_strlen(void)
{
	int		test1 = test_1();
	int		test2 = test_2();
	int		test3 = test_3();

	if (test1 == 1 && test2 == 1 && test3 == 1)
		printf("\t\033[92mOK\033[97m\n");
	else
	{
		printf("\033[91m\tKO!\n");
		if (test1 == 0)
			printf(" Failed in Test 1\n Don't work with basic input\n");
		if (test2 == 0)
			printf(" Failed in Test 2\n Don't work with no ascii chars\n");
		if (test3 == 0)
			printf(" Failed in Test 3\n Don't work with NULL\n");
		return (0);
	}
	return (1);
}
