/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:29:15 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/21 18:29:47 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

static int	test_1(void)
{
	int		pass = 0;
    char  *ll = "ll", *jj = "jj", *nn = "nn", *ss = "ss";
    t_list  *list, *wh, *ii, *last;
    
    list = malloc(sizeof(t_list) * 1);
    wh = malloc(sizeof(t_list) * 1);
    ii = malloc(sizeof(t_list) * 1);
    last = malloc(sizeof(t_list) * 1);
    
    list->content = ll;
    wh->content = jj;
    ii->content = ss;
    last->content = nn;
    
    list->next = wh;
    wh->next = ii;
	ii->next = last;
    last->next = NULL;
    
    ft_lstclear(&list, *test_lstcnt_tn);
    if (list == 0)
	{
      printf("\033[92m\tOK\n");
	  pass = 1;
	}
	else
		printf("\033[91m\tKO!\n Your lstclear don't work!\n");
	return (pass);
}

int	test_lstclear(void)
{
	return (test_1());
}
