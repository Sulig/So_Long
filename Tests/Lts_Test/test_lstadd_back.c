/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:15:06 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/21 16:30:36 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_1(void)
{
	int		pass = 0;
	t_list	*list, *wh, *last, *hi;

	list = ft_lstnew("Old front");
	wh = ft_lstnew("->next");
	last = ft_lstnew("last");

	list->next = wh;
	wh->next = last;
	last->next = NULL;
	/**/
	hi = ft_lstnew("New last");
	hi->next = NULL;

	ft_lstadd_back(&list, hi);
	pass += test_myapp_str(list->content, "Old front");
	pass += test_myapp_str(list->next->content, "->next");
	pass += test_myapp_str(list->next->next->content, "last");
	pass += test_myapp_str(list->next->next->next->content, "New last");
	/**/
	free(hi);
	free(last);
	free(wh);
	free(list);
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
	ft_lstadd_back(&list, NULL);
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

static int	test_3(void)
{
	int		pass = 0;
	t_list	*list, *wh, *last, *hi, *beh;

	list = ft_lstnew("Front");
	wh = ft_lstnew("->next");
	last = ft_lstnew("last");

	list->next = wh;
	wh->next = last;
	last->next = NULL;
	/**/
	hi = ft_lstnew("42");
	beh = ft_lstnew("Last");
	hi->next = beh;
	beh->next = NULL;

	ft_lstadd_back(&list, hi);
	pass += test_myapp_str(list->content, "Front");
	pass += test_myapp_str(list->next->content, "->next");
	pass += test_myapp_str(list->next->next->content, "last");
	pass += test_myapp_str(list->next->next->next->content, "42");
	pass += test_myapp_str(list->next->next->next->next->content, "Last");
	/**/
	free(beh);
	free(hi);
	free(last);
	free(wh);
	free(list);
	/**/
	return (pass);
}

int	test_lstadd_back(void)
{
	int		pass = 1;
	int		t1, t2, t3;

	t1 = test_1();
	t2 = test_2();
	t3 = test_3();

	if (t1 == 4 && t2 == 3 && t3 == 5)
		printf("\033[92m\tOK\n");
	else
	{
		pass = 0;
		printf("\033[91m\tKO!\n");
		if (t1 != 4)
			printf(" Your lstadd_back don't work with basic input!\n");
		if (t2 != 3)
			printf(" Your lstadd_back don't work with NULL!\n");
		if (t3 != 5)
			printf(" Your lstadd_back don't work with 2 nodes!\n");
	}
	return (pass);
}
