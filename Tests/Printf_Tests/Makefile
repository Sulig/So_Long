# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 16:38:54 by sadoming          #+#    #+#              #
#    Updated: 2023/08/29 19:04:00 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_printf.a
# ---------------- #
CFLAGS = -Wall -Wextra -Werror
# ---------------- #
# Sources:
MAK = Makefile
LIB = test_printf.h

SRC = test_printf_main.c test_csp_and_noformat.c test_nbr.c test_utils.c
OBJ = $(SRC:%.c=%.o)
#------------------------------------------------------------------------------#
all: $(NAME)
# ---------------- #
%.o : %.c $(LIB) $(MAK)
	@gcc $(CFLAGS) $(PF) -c $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[1;32m Printf Tests Compiled Successfully\033[1;97m\n"

clean:
	@/bin/rm -f *.o

fclean : clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f .DS_Store

re: fclean all

.PHONY: all bonus clean fclean re
# ******************************************* #