/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:01:03 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/21 16:14:30 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_1(void)
{
	int		pass;
	t_list	*list, *wh, *last, *ret;

	list = ft_lstnew("Old front");
	wh = ft_lstnew("->next");
	last = ft_lstnew("last");

	list->next = wh;
	wh->next = last;
	last->next = NULL;
	/**/
	ret = ft_lstlast(list);
	pass = test_myapp_str(ret->content, "last");
	/**/
	free(last);
	free(wh);
	free(list);
	/**/
	return (pass);
}

static int	test_2(void)
{
	int		pass;
	t_list	*ret;

	ret = ft_lstlast(NULL);
	if (ret == NULL)
		pass = 1;
	else
		pass = 0;
	return (pass);
}

int	test_lstlast(void)
{
	int		pass = 1;
	int		t1, t2;

	t1 = test_1();
	t2 = test_2();
	if (t1 == 1 && t2 == 1)
		printf("\033[92m\tOK\n");
	else
	{
		pass = 0;
		printf("\033[91m\tKO!\n");
		if (t1 != 1)
			printf(" Your lstlast don't work with basic input!\n");
		if (t2 != 1)
			printf(" Your lstlast don't return NULL if lst is NULL!\n");
	}
	return (pass);
}
