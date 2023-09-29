/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:19:30 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/27 20:25:18 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_PRINTF_H
# define TEST_PRINTF_H

# include <stdio.h>
# include "../../libft.h"

// Apliccations -->
void	cc(char color);
int		look4ko(int ori, int you);
void	sep(char c);
int		resume(int len, ...);

// Tests -->
int		test_nc(void);
int		test_char(void);
int		test_str(void);
int		test_int(void);
int		test_hex(void);
int		test_per(void);
int		test_pnt(void);
int		test_unsig(void);

#endif
