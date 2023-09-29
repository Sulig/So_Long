/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:09:04 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/21 15:35:00 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_1(void)
{
	int		pass = 0;
	t_list  *list, *wh, *last, *hi;

	list = ft_lstnew("Old front");
	wh = ft_lstnew("->next");
	last = ft_lstnew("last");

	list->next = wh;
	wh->next = last;
	last->next = NULL;
	/**/
	hi = ft_lstnew("New front");
	hi->next = NULL;

	ft_lstadd_front(&list, hi);
	pass += test_myapp_str(hi->content, "New front");
	pass += test_myapp_str(hi->next->content, "Old front");
	pass += test_myapp_str(hi->next->next->content, "->next");
	pass += test_myapp_str(hi->next->next->next->content, "last");
	/**/
	free(last);
	free(wh);
	free(hi->next);
	free(hi);
	/**/
	return (pass);
}

static int	test_2(void)
{
	int		pass = 0;
	t_list	*list, *wh, *last;

	list = ft_lstnew("Old front");
	wh = ft_lstnew("->next");
	last = ft_lstnew("last");

	list->next = wh;
	wh->next = last;
	last->next = NULL;
	/**/
	ft_lstadd_front(&list, NULL);
	pass += test_myapp_str(list->content, "Old front");
	pass += test_myapp_str(list->next->content, "->next");
	pass += test_myapp_str(list->next->next->content, "last");
	/**/
	free(last);
	free(wh);
	free(list);
	/**/
	return (pass);
}

int	test_lstadd_front(void)
{
	int		pass = 1;
	int		t1, t2;

	t1 = test_1();
	t2 = test_2();

	if (t1 == 4 && t2 == 3)
		printf("\033[92m\tOK\n");
	else
	{
		pass = 0;
		printf("\033[91m\tKO!\n");
		if (t1 != 4)
			printf(" Your lstadd_front don't work with basic input!\n");
		if (t2 != 3)
			printf(" Your lstadd_front don't work with NULL!\n");
	}
	return (pass);
}
