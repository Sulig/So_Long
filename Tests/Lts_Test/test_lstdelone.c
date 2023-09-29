/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:31:59 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/21 18:51:07 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static void	test_2(void)
{
	t_list	*try, *non;

    try = malloc(sizeof(t_list) * 1);
    non = malloc(sizeof(t_list) * 1);
	try->next = non;
	non->next = NULL;
	ft_lstdelone(try, *test_lstcnt_tn);
	free(non);
}

static void	test_1(void)
{
	char	*ll = "Try";
    t_list  *try;

    try = malloc(sizeof(t_list) * 1);
    try->content = ll;
	try->next = NULL;
	ft_lstdelone(try, *test_lstcnt_tn);
}

int	test_lstdelone(void)
{
	test_1();
	test_2();
	printf("\033[92m\tOK!\n\033[0;93m *~ Comprobe that you don't have leaks :0\n");
	return (1);
}
