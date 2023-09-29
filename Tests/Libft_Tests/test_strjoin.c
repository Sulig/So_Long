/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:56:41 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/19 18:14:20 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

int	test_strjoin(void)
{
	int		pass = 1;
	char	*you, *exp;

	/* Test_1 */
	you = ft_strjoin("Concatenate", " this");
	exp = "Concatenate this";
	if (test_myapp_str(you, exp) == 0)
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your strjoin don't work with basic input!\n");
		printf(" Expec: %s\n", exp);
		printf(" Yours: %s\n", you);
	}
	free(you);
	/**/
	/* Test_2 */
	you = ft_strjoin("\200\t\3\4\5\23\14", "");
	exp = "\200\t\3\4\5\23\14";
	if (test_myapp_str(you, exp) == 0)
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your strjoin don't wotk with \\!\n");
		printf(" Expec: %s\n", exp);
		printf(" Yours: %s\n", you);
	}
	free(you);
	/**/
	/* Test_3 */
	you = ft_strjoin("\0", "\0");
	exp = "";
	if (test_myapp_str(you, exp) == 0)
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your strjoin don't work with NULL!\n");
		printf(" Expec: %s*\n", exp);
		printf(" Yours: %s*\n", you);
	}
	free(you);
	/**/
	if (pass == 1)
		printf("\033[92m\tOK\n");
	return (pass);
}
