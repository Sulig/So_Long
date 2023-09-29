/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:58:54 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/19 18:33:54 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static void	ft_free(char **you, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(you[i]);
		i++;
	}
	free(you);
}

static int	test_1(void)
{
	char	**you;
	char	*exp[] = {"Split", "the", "words", "uwu"};
	int		pass = 1;
	int		i = 0;

	you = ft_split("Split the words uwu", ' ');
	while (i < 4)
	{
		if (test_myapp_str(you[i], exp[i]) == 0)
		{
			pass = 0;
			break ;
		}
		i++;
	}
	if (pass != 0 && you[i] != NULL)
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your split is not NULL terminated!\n");
	}
	if (pass == 0)
	{
		printf("\033[91m\tKO!\n Your split don't work!\n Failed in %i\n", i);
		printf(" Expec: %s\n", exp[i]);
		printf(" Yours: %s\n", you[i]);
	}
	ft_free(you, 4);
	return (pass);
}

static int	test_2(void)
{
	char	**words;
	char	*exp;
	int		pass = 0;

	exp = "hello!";
	words = ft_split("\t\t\t\thello!\t\t\t\t", '\t');
	if (test_myapp_str(words[0], exp) != 0)
		if (words[1] == 0)
			pass = 1;
	if (pass == 0)
	{
		printf("\033[91m\tKO!\n Your split don't work with one word!\n");
		printf(" Expec: %s\n", exp);
		printf(" Yours: %s\n", words[0]);
	}
	ft_free(words, 1);
	return (pass);
}

static int	test_3(void)
{
	char	**words;
	char	*exp;
	int		pass = 1;

	exp = "\0";
	words = ft_split("\0", ' ');
	if (words == NULL)
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your split don't work with NULL!\n");
	}
	ft_free(words, 1);
	return (pass);
}

int		test_split(void)
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
