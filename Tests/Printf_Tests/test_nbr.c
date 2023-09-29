/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:49:08 by sadoming          #+#    #+#             */
/*   Updated: 2023/08/29 19:24:57 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_printf.h"

int	test_int(void)
{
	int		min, max, random;
	int		res[8];
	int		nn;

	min = -2147483648;
	max = 2147483647;
	random = rand();
	sep('i');
	/**/
	res[0] = look4ko(ft_printf("You: %i\n", 1), printf("Ori: %i\n", 1));
	res[1] = look4ko(ft_printf("You: %i\n", 0), printf("Ori: %i\n", 0));
	res[2] = look4ko(ft_printf("You: %i\n", -1), printf("Ori: %i\n", -1));
	res[3] = look4ko(ft_printf("You: %i\n", random), printf("Ori: %i\n", random));
	res[4] = look4ko(ft_printf("You: %i\n", max), printf("Ori: %i\n", max));
	res[5] = look4ko(ft_printf("You: %i\n", min), printf("Ori: %i\n", min));
	res[6] = look4ko(ft_printf("You: |%i| |%i| |%i|\n", 2, 0, -1), printf("Ori: |%i| |%i| |%i|\n", 2, 0, -1));
	res[7] = look4ko(ft_printf("You: |%i| |%i| |%i| |%i| |%i| |%i|\n", 0, 5, -10, random, min, max), printf("Ori: |%i| |%i| |%i| |%i| |%i| |%i|\n", 0, 5, -10, random, min, max));
	/**/
	nn = resume(8, res[0], res[1], res[2], res[3], res[4], res[5], res[6], res[7]);
	/**/
	sep(0);
	return (nn);
}

int	test_hex(void)
{
	int		min, max, random;
	int		res[16];
	int		nn;

	min = -2147483648;
	max = 2147483647;
	random = rand();
	/**/
	sep('x');
	res[0] = look4ko(ft_printf("You: %x\n", 1), printf("Ori: %x\n", 1));
	res[1] = look4ko(ft_printf("You: %x\n", 0), printf("Ori: %x\n", 0));
	res[2] = look4ko(ft_printf("You: %x\n", -1), printf("Ori: %x\n", -1));
	res[3] = look4ko(ft_printf("You: %x\n", 15), printf("Ori: %x\n", 15));
	res[4] = look4ko(ft_printf("You: %x\n", max), printf("Ori: %x\n", max));
	res[5] = look4ko(ft_printf("You: %x\n", min), printf("Ori: %x\n", min));
	res[6] = look4ko(ft_printf("You: |%x| |%x| |%x|\n", 2, 0, -1), printf("Ori: |%x| |%x| |%x|\n", 2, 0, -1));
	res[7] = look4ko(ft_printf("You: |%x| |%x| |%x| |%x| |%x| |%x|\n", 0, 5, -10, random, min, max), printf("Ori: |%x| |%x| |%x| |%x| |%x| |%x|\n", 0, 5, -10, random, min, max));
	/**/
	nn = resume(8, res[0], res[1], res[2], res[3], res[4], res[5], res[6], res[7]);
	if (nn == 0)
		return (0);
	sep(0);
	/**/
	sep('X');
	res[8] = look4ko(ft_printf("You: %X\n", 1), printf("Ori: %X\n", 1));
	res[9] = look4ko(ft_printf("You: %X\n", 0), printf("Ori: %X\n", 0));
	res[10] = look4ko(ft_printf("You: %X\n", -1), printf("Ori: %X\n", -1));
	res[11] = look4ko(ft_printf("You: %X\n", 15), printf("Ori: %X\n", 15));
	res[12] = look4ko(ft_printf("You: %X\n", max), printf("Ori: %X\n", max));
	res[13] = look4ko(ft_printf("You: %X\n", min), printf("Ori: %X\n", min));
	res[14] = look4ko(ft_printf("You: |%X| |%X| |%X|\n", 2, 0, -1), printf("Ori: |%X| |%X| |%X|\n", 2, 0, -1));
	res[15] = look4ko(ft_printf("You: |%X| |%X| |%X| |%X| |%X| |%X|\n", 0, 5, -10, random, min, max), printf("Ori: |%X| |%X| |%X| |%X| |%X| |%X|\n", 0, 5, -10, random, min, max));
	/**/
	nn = resume(8, res[8], res[9], res[10], res[11], res[12], res[13], res[14], res[15]);
	sep(0);
	/**/
	resume(16, res[0], res[1], res[2], res[3], res[4], res[5], res[6], res[7], res[8], res[9], res[10], res[11], res[12], res[13], res[14], res[15]);
	sep(0);
	return (nn);
}

int	test_unsig(void)
{
	int		min, max, random;
	int		res[8];
	int		nn;

	min = -2147483648;
	max = 2147483647;
	random = rand();
	sep('u');
	/**/
	res[0] = look4ko(ft_printf("You: %u\n", 1), printf("Ori: %u\n", 1));
	res[1] = look4ko(ft_printf("You: %u\n", 0), printf("Ori: %u\n", 0));
	res[2] = look4ko(ft_printf("You: %u\n", -1), printf("Ori: %u\n", -1));
	res[3] = look4ko(ft_printf("You: %u\n", random), printf("Ori: %u\n", random));
	res[4] = look4ko(ft_printf("You: %u\n", max), printf("Ori: %u\n", max));
	res[5] = look4ko(ft_printf("You: %u\n", min), printf("Ori: %u\n", min));
	res[6] = look4ko(ft_printf("You: |%u| |%u| |%u|\n", 1, 0, -1), printf("Ori: |%u| |%u| |%u|\n", 1, 0, -1));
	res[7] = look4ko(ft_printf("You: |%u| |%u| |%u| |%u| |%u| |%u|\n", 0, 5, -10, random, min, max), printf("Ori: |%u| |%u| |%u| |%u| |%u| |%u|\n", 0, 5, -10, random, min, max));
	/**/
	nn = resume(8, res[0], res[1], res[2], res[3], res[4], res[5], res[6], res[7]);
	/**/
	sep(0);
	return (nn);
}
