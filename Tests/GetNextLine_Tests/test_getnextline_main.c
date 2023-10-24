/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getnextline_main.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:15:21 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/24 17:44:56 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_getnextline.h"

static int	read_line(int fd, char *exp, int line, char *txt)
{
	char		*str;
	int			ret;

	printf("|%i| ~ %s \tLine: |%i|", fd, txt, line);
	str = get_next_line(fd);
	ret = look4ko(str, exp);
	free(str);
	return (ret);
}

static void manual_test(char *txt)
{
	char	*str;
	int		fd;

	fd = open(txt, O_RDONLY);
	cc('w');
	printf("~ Manual test from file |%s|\n\nFD |%i|\t", txt, fd);
	str = get_next_line(fd);
	do
	{
	    printf("~ Output -> |%s|\n", str);
	    free(str);
	    str = get_next_line(fd);
        } while (str);
}

int	main(int argc, char **argv)
{
	int		fd1, fd2, fd3, fd4, fd5, fd6;
	int		res[40];
	int		cnt;
	int		a;

	/**/
	printf("\033[1;34m\t     ~ Made by Sadoming ~\n");
	printf("\n\033[1;36m**///////////////////////////////////////////**\n");
	printf("**/        Testing GetNextLine Bonus         /**\n");
	printf("**///////////////////////////////////////////**\n\n");
	/**/
	fd1 = open("GetNextLine_Tests/TXT/onln.txt", O_RDONLY);
	fd2 = open("GetNextLine_Tests/TXT/twln.txt", O_RDONLY);
	fd3 = open("GetNextLine_Tests/TXT/onechar.txt", O_RDONLY);
	fd4 = open("GetNextLine_Tests/TXT/empty.txt", O_RDONLY);
	fd5 = open("GetNextLine_Tests/TXT/mutnl.txt", O_RDONLY);
	fd6 = open("GetNextLine_Tests/TXT/41_with_nl.txt", O_RDONLY);
	/**/
	cc('C');
	printf("|---------- - >\n");
	printf("|Buf Size |%i|\n", BUFFER_SIZE);
	printf("{~~~~~~~~~~~~~~~}\n\n");
	cc('w');
	/**/
	a = 0;
	res[a++] = read_line(-1, NULL, -1, "Invalid fd");
	res[a++] = read_line(fd1, "one line\n", 0, "onln.txt");
	res[a++] = read_line(fd2, "0123456789\n", 0, "twln.txt");
	res[a++] = read_line(fd1, NULL, 1, "onln.txt");
	res[a++] = read_line(fd2, "9876543210\n", 1, "twln.txt");
	res[a++] = read_line(fd4, NULL, 0, "empty.txt");
	while (a < 11)
		res[a++] = read_line(fd5, "\n", 0, "mutnl.txt");
	res[a++] = read_line(fd6, "0123456789012345678901234567890123456789\n", 0, "41_with_nl.txt");
	res[a++] = read_line(fd3, "a\n", 0, "onechar.txt");
	res[a++] = read_line(fd6, "0", 1, "41_with_nl.txt");
	res[a++] = read_line(fd6, NULL, 2, "41_with_nl.txt");
	res[a++] = read_line(fd3, NULL, 1, "onechar.txt");
	res[a++] = read_line(fd5, NULL, 0, "mutnl.txt");
	/**/
	resume(17, res);
	/**/
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	close(fd6);
	/**/
	sep(0);
	/**/
	cc('c');
	cnt = 1;
	if (argc > 1)
	{
		while (cnt < argc)
			manual_test(argv[cnt++]);
	}
	else
		printf("~! For manual test of some *.txt, introduce it itself in ./test.out\t |Argc: %i|\n", argc);
	sep(0);
	/**/
	printf("\033[1;95m \n");
	return (0);
}
