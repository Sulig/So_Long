/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:57:24 by sadoming          #+#    #+#             */
/*   Updated: 2023/08/29 19:27:26 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_printf.h"

int		main(void)
{
	int		res[9];

	printf("\033[1;34m\t     ~ Made by Sadoming ~\n");
	printf("\n\033[1;36m**///////////////////////////////////////////**\n");
	printf("**/             Testing Printf              /**\n");
	printf("**///////////////////////////////////////////**\n\n");
	/**/
	res[0] = test_nc();
	res[1] = test_char();
	res[2] = test_str();
	res[3] = test_int();
	res[4] = test_hex();
	res[5] = test_pnt();
	res[6] = test_unsig();
	res[7] = test_per();
	cc('y');
	printf("Tests Result:\n");
	res[8] = resume(8, res[0], res[1], res[2], res[3], res[4], res[5], res[6], res[7]);
	/**/
	sep(0);
	printf("\033[1;95m \n");
	return (0);
}
