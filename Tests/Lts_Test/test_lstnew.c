/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:44:19 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/20 13:25:57 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

int	test_lstnew(void)
{
	int		pass;
	t_list	*nn;

	nn = ft_lstnew(NULL);
	if (!nn)
	{
		printf("\033[91m\tKO!\n Maybe the malloc chrash?\n");
		pass = 0;
	}
	else
	{
		if (nn->content)
		{
			printf("\033[91m\tKO!\n content is not NULL\n");
			pass = 0;
		}
		else
		{
			printf("\033[92m\tOK\n");
			pass = 1;
		}
	}
	free(nn);
	return (1);
}
