/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:52:49 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/21 19:30:50 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static void	ft_free(void *cnt)
{
	cnt = NULL;
	printf("*");
}

static void	test_1(void)
{
	t_list	*list, *wh, *last;

	list = ft_lstnew("Old front");
	wh = ft_lstnew("->next");
	last = ft_lstnew("last");

	list->next = wh;
	wh->next = last;
	last->next = NULL;
	/**/
	ft_lstiter(list, *ft_free);
	/**/
	free(last);
	free(wh);
	free(list);
}

int	test_lstiter(void)
{
	printf("\033[93m\t*~ Manual Test! ~*\n");
	printf("\033[1;34m\t ~ Look at the \"*\", if there's 3, it's OK\n");
	printf("\033[1;37m\t ~ Iter: ");
	test_1();
	return (1);
}
