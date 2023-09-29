/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_myapp_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:54:29 by sadoming          #+#    #+#             */
/*   Updated: 2023/06/19 18:18:44 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

int	test_myapp_str(char *you, char *exp)
{
	int		pass;
	int		len;
	int		cnt;

	pass = 1;
	cnt = 0;
	len = strlen(exp) + 1;
	while (cnt < len)
	{
		if (you[cnt] != exp[cnt])
			pass = 0;
		cnt++;
	}
	return (pass);
}
