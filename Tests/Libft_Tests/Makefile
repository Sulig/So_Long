# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 19:55:18 by sadoming          #+#    #+#              #
#    Updated: 2023/09/27 18:23:46 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_libft.a
# ---------------- #
CFLAGS = -Wall -Wextra -Werror -g
# ---------------- #
MAK = Makefile
LIB = test_libft.h

SRC = *.c
OBJ = $(SRC:%.c=%.o)
#------------------------------------------------------------------------------#
all: $(NAME)
# ---------------- #
%.o : %.c $(LIB) $(MAK)
	@gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[1;32m Libft Tests Compiled Successfully\033[1;97m\n"

clean:
	@/bin/rm -f *.o
	@/bin/rm -f $(DIR)/*.o

fclean : clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f .DS_Store

re: fclean all

.PHONY: all bonus clean fclean re
# ******************************************* #
