/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:51:08 by sadoming          #+#    #+#             */
/*   Updated: 2023/08/29 19:18:53 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_printf.h"

void	sep(char c)
{
	cc('y');
	if (!c || c == '\0')
		printf("~ ------------------------- ~\t\t\t\t\t*~~~~~~~*\n");
	else
		 printf("~ Testing \"%%%c\" cases:\t\t\t\t\t\t~ \"%%%c\" ~", c, c);
	cc('w');
	printf("\n");
}

void	cc(char color)
{
	if (color == 'R' || color == 'r')
		printf("\033[1;91m");
	else if (color == 'G' || color == 'g')
		printf("\033[1;92m");
	else if (color == 'B' || color == 'b')
		printf("\033[1;34m");
	else if (color == 'Y' || color == 'y')
		printf("\033[1;93m");
	else if (color == 'W' || color == 'w')
		printf("\033[1;37m");
	else if (color == 'C' || color == 'c')
		printf("\033[1;36m");
}

int	look4ko(int you, int ori)
{
	int		ok;

	if (you == ori)
	{
		cc('G');
		printf(" \t\t\t\t\t\t\t\t~ |OK| ~");
		ok = 1;
	}
	else
	{
		cc('R');
		printf(" \t\t\t\t\t\t\t\t~ |KO!| ~\n");
		printf("Diferent Length! -> Org |%i|\tYou |%i|\n", ori, you);
		printf("!! ----------------------------------- !!");
		ok = 0;
	}
	cc('W');
	printf("\n");
	return (ok);
}

int	resume(int len, ...)
{
	va_list	args;
	int		cnt;
	int		res;
	int		now;

	cnt = 0;
	res = 0;
	va_start(args, len);
	cc('C');
	printf("|---------- - >\n");
	printf("| Tests Resume: ");
	while (cnt < len)
	{
		now = va_arg(args, int);
		if (now == 1)
		{
			cc('G');
			printf("|OK| ");
			res++;
		}
		else if (now == 0)
		{
			cc('R');
			printf("|KO| ");
		}
		else
		{
			cc('Y');
			printf("|%i| ", now);
		}
		cnt++;
	}
	va_end(args);
	cc('C');
	printf("\n{~~~~~~~~~~~~~~~}");
	/**/
	if (res == len)
	{
		cc('g');
		printf("\t\t\t\t\t       |OK Region|\n");
		return (1);
	}
	else
	{
		cc('y');
		printf("\t\t\t\t\t   |Revise your code|\n");
		return (0);
	}
}
