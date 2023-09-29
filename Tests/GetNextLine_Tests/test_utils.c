/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:38:07 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/21 16:04:35 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_getnextline.h"

void	sep(char c)
{
	cc('y');
	if (!c || c == '\0')
		printf("~ ------------------------- ~\n");
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

size_t	my_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	if (!s)
	  return (0);
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

int		contains(const char *str, char in)
{
	size_t	cnt;

	cnt = 0;
	if (str == NULL)
		return (1);
	while (str[cnt])
	{
		if (str[cnt] == in)
			return (0);
		cnt++;
	}
	return (1);
}

int		look4ko(char *you, char *exp)
{
	int		ok;
	int		len;
	int		cnt;

	ok = 1;
	cnt = 0;
	if ((!exp && you) || (exp && !you))
		ok = 0;
	len = my_strlen(exp) + 1;
	while (cnt < len && ok != 0 && exp)
	{
		if (you[cnt] != exp[cnt])
			ok = 0;
		cnt++;
	}
	if (ok == 1)
	{
		cc('G');
		printf(" \t\t~ |OK| ~");
	}
	else
	{
		cc('R');
		printf(" \t\t~ |KO!| ~\t In pos: |%i|\n", cnt);
		printf("You don't return the expected! ->\n");
		printf("Org |Len = %zu|~|%s|\nYou |Len = %zu|~|%s|\n", my_strlen(exp), exp, my_strlen(you), you);
		printf("!! ----------------------------------- !!");
	}
	cc('W');
	printf("\n");
	return (ok);
}

int	resume(int len, int *res)
{
	int		cnt;
	int		ok;

	cnt = 0;
	ok = 1;
	cc('C');
	printf("|---------- - >\n");
	printf("| Tests Resume: ");
	while (cnt < len)
	{
		if (res[cnt] == 1)
		{
			cc('G');
			printf("|OK| ");
		}
		else if (res[cnt] == 0)
		{
			cc('R');
			printf("|KO| ");
			ok = 0;
		}
		else
		{
			cc('Y');
			printf("|%i| ", res[cnt]);
		}
		cnt++;
	}
	cc('C');
	printf("\n{~~~~~~~~~~~~~~~}");
	if (ok == 1)
	{
		cc('g');
		printf("\t   |All tests are OK!|\n");
		return (1);
	}
	else
	{
		cc('y');
		printf("\t   |Revise your code|\n");
		return (0);
	}
}
