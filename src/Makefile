# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 17:17:46 by sadoming          #+#    #+#              #
#    Updated: 2023/10/03 19:13:54 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = arch.a
CFLAGS = -Wall -Wextra -Werror -g
#-----------------------------#
# Sources:
MAK = Makefile
LIB = so_long.h so_long_structs.h

SRC = so_long_main.c ft_check_file.c ft_check_map_sol.c ft_man_struc.c ft_print_map_t.c
OBJ = $(SRC:%.c=%.o)
#------------------------------------------------------------------------------#

all: $(NAME)

%.o : %.c $(MAK) $(LIB)
	@gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[1;32m SRC Compiled Successfully\033[1;97m\n"

#-------------------------------------------------------------#
norm:
	@echo "\n\033[1;93m~ Norminette:"
	@norminette $(SRC)
	@norminette -R CheckForbiddenSourceHeader $(SRC)
	@echo "\033[1;32m ~ OK"
	@echo "\033[0;39m\n"
#-------------------------------------------------------------#
clean:
	@/bin/rm -f *.o

fclean : clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f .DS_Store

re: fclean all

.PHONY: all clean fclean norm re
# ******************************************* #
