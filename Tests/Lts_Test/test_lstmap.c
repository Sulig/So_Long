/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:31:03 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/21 19:39:45 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static void	ft_free(void *lst)
{
	lst = NULL;
}

static void	*ft_ds(void *lst)
{
	return (lst);
}

int test_lstmap(void)
{
	int		pass = 0;
	t_list  *list, *wh, *last, *ret;

	list = malloc(sizeof(t_list) * 1);
	wh = malloc(sizeof(t_list) * 1);
	last = malloc(sizeof(t_list) * 1);

	list->content = "list";
	wh->content = "wh";
	last->content = "blast";

	list->next = wh;
	wh->next = last;
	last->next = NULL;

	ret = ft_lstmap(list, *ft_ds, *ft_free);
	pass += test_myapp_str(ret->content, "list");   
	pass += test_myapp_str(ret->next->content, "wh");
	pass += test_myapp_str(ret->next->next->content, "blast");
	if (pass == 3)
	{
		printf("\033[92m\tOK\n");
		pass = 1;
	}
	else
	{
		pass = 0;
		printf("\033[91m\tKO!\n Your lstmap don't work with basic input!\n");
	}
	/**/
	free(last);
	free(wh);
	free(list);
	ft_lstclear(&ret, *ft_free);
	return (pass);
}
