/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_csp_and_noformat.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:53:00 by sadoming          #+#    #+#             */
/*   Updated: 2023/08/29 19:23:35 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_printf.h"

int	test_nc(void)
{
	int		res[3];
	int		nn;

	cc('Y');
	printf("~ Testing no \"%%\" cases:\t\t\t\t\t\t~ \"None\" ~");
	cc('W');
	printf("\n");
	/**/
	res[0] = look4ko(ft_printf("You: abcdefghijklmnopqrstuvwxyz\n"), printf("Ori: abcdefghijklmnopqrstuvwxyz\n"));
	res[1] = look4ko(ft_printf("You: \"\t\"\"\12\"\"\13\"\n"), printf("Ori: \"\t\"\"\12\"\"\13\"\n"));
	res[2] = look4ko(ft_printf(""), printf(""));
	nn = resume(3, res[0], res[1], res[2]);
	/**/
	sep(0);
	return (nn);
}

int	test_char(void)
{
	int		min;
	int		max;
	int		res;
	int		nn;

	sep('c');
	/**/
	min = -200;
	max = 182;
	res = 0;
	while (min < max)
	{
		res += look4ko(ft_printf("%c", min), printf("%c", min));
		min++;
	}
	nn = resume(1, look4ko(res, 382));
	/**/
	sep(0);
	return (nn);
}

int	test_str(void)
{
	char	*str;
	int		res[4];
	int		nn;

	sep('s');
	str = "0123STR str";
	/**/
	res[0] = look4ko(ft_printf("You: |%s|\n", str), printf("Ori: |%s|\n", str));
	res[1] = look4ko(ft_printf("You: |%s|\n", "%%%"), printf("Ori: |%s|\n", "%%%"));
	res[2] = look4ko(ft_printf("You: |%s|\n", NULL), printf("Ori: |%s|\n", NULL));
	res[3] = look4ko(ft_printf("You: |%s|\n", ""), printf("Ori: |%s|\n", ""));
	/**/
	nn = resume(4, res[0], res[1], res[2], res[3]);
	/**/
	sep(0);
	return (nn);
}

int	test_pnt(void)
{
	int		*pnt;
	int		res[4];
	int		nn;

	sep('p');
	pnt = &res[0];
	/**/
	res[0] = look4ko(ft_printf("You: |%p|\n", pnt), printf("Ori: |%p|\n", pnt));
	res[1] = look4ko(ft_printf("You: |%p|\n", ""), printf("Ori: |%p|\n", ""));
	res[2] = look4ko(ft_printf("You: |%p|\n", NULL), printf("Ori: |%p|\n", NULL));
	res[3] = look4ko(ft_printf("You: |%p|\n", (void *) -14), printf("Ori: |%p|\n", (void *)-14));
	/**/
	nn = resume(4, res[0], res[1], res[2], res[3]);
	/**/
	sep(0);
	return (nn);
}

int	test_per(void)
{
	int		res[5];
	int		nn;

	sep('%');
	res[0] = look4ko(ft_printf(" %% "), printf(" %% "));
	printf("\n");
	res[1] = look4ko(ft_printf("%%"), printf("%%"));
	printf("\n");
	res[2] = look4ko(ft_printf("%%%%\n"), printf("%%%%\n"));
	res[3] = look4ko(ft_printf("%%%c%%\n", '\t'), printf("%%%c%%\n", '\t'));
	res[4] = look4ko(ft_printf("%%%%%%\n"), printf("%%%%%%\n"));
	/**/
	nn = resume(5, res[0], res[1], res[2], res[3], res[4]);
	sep(0);
	return (nn);
}
