/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:24:02 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/19 18:38:59 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

int	test_lstsize(void)
{
	int		pass;
    t_list  *list, *wh, *last;

    list = malloc(sizeof(t_list) * 1);
    wh = malloc(sizeof(t_list) * 1);
    last = malloc(sizeof(t_list) * 1);

    list->next = wh;
    wh->next = last;
    last->next = NULL;

    if (ft_lstsize(list) != 3)
	{
		printf("\033[91m\tKO!\n Expected: 3\n Yours: %i\n", ft_lstsize(list));
		pass = 0;
	}
	else if (ft_lstsize(wh) != 2)
	{
		printf("\033[91m\tKO!\n Expected: 2\n Yours: %i\n", ft_lstsize(wh));
		pass = 0;
	}
	else if (ft_lstsize(last) != 1)
	{
		printf("\033[91m\tKO!\n Expected: 1\n Yours: %i\n", ft_lstsize(last));
		pass = 0;
	}
	else if (ft_lstsize(NULL) != 0)
	{
		printf("\033[91m\tKO!\n Don't work with NULL");
		pass = 0;
	}
	else
	{
		printf("\033[92m\tOK\n");
		pass = 1;
	}
	free(last);
	free(wh);
	free(list);
	return (pass);
}
