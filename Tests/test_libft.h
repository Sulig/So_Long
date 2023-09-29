/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:52:18 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/27 12:32:12 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_LIBFT_H
# define TEST_LIBFT_H

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <xlocale.h>
# include "../Libft/libft.h"

/* //Aplications 4 tests: */
int		test_myapp_str(char *you, char *exp);
void	test_lstcnt_tn(void *cnt);
/**/

/* Tests: */
int		test_isalnum(void);
int		test_isalpha(void);
int		test_isascii(void);
int		test_isdigit(void);
int		test_isprint(void);
int		test_toupper(void);
int		test_tolower(void);
int		test_strlen(void);
int		test_bzero(void);
int		test_strlcpy(void);
int		test_strlcat(void);
int		test_strchr(void);
int		test_strrchr(void);
int		test_strncmp(void);
int		test_strnstr(void);
int		test_strdup(void);
int		test_atoi(void);

int		test_memset(void);
int		test_memcpy(void);
int		test_memchr(void);
int		test_memcmp(void);
int		test_memmove(void);

int		test_substr(void);
int		test_strjoin(void);
int		test_strtrim(void);
int		test_split(void);
int		test_itoa(void);
int		test_strmapi(void);

/* Manual Tests: */
void	test_striteri(void);
void	test_putchar_fd(void);
void	test_putstr_fd(void);
void	test_putendl_fd(void);
void	test_putnbr_fd(void);
/**/

/* TESTS FOR BONUS */
int		test_lstnew(void);
int		test_lstsize(void);
int		test_lstadd_front(void);
int		test_lstlast(void);
int		test_lstadd_back(void);
int		test_lstdelone(void);
int		test_lstclear(void);
int		test_lstiter(void);
int		test_lstmap(void);
/**/
#endif
