/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:27:22 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/19 18:22:28 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

int	test_strdup(void)
{
	int		pass = 1;
	char	*src, *ori, *you;

	/* Test_1 */
	src = "Duplicate";
	you = ft_strdup(src);
	ori = ft_strdup(src);
	if (test_myapp_str(you, ori) == 0)
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your strdup don't work with basic input!\n");
		printf(" Expec: %s\n", ori);
		printf(" Yours: %s\n", you);
	}
	free(you);
	free(ori);
	/**/
	/* Test_2 */
	src = "\200\1\2\7\t\e";
	you = ft_strdup(src);
	ori = strdup(src);
	if (test_myapp_str(you, ori) == 0)
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your strdup don't work with \\!\n");
		printf(" Expec: %s\n", ori);
		printf(" Yours: %s\n", you);
	}
	free(you);
	free(ori);
	/**/
	if (pass == 1)
	{
		printf("\033[92m\tOK\n");
		return (1);
	}
	return (0);
}
