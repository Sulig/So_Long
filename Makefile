# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 17:07:32 by sadoming          #+#    #+#              #
#    Updated: 2023/09/28 20:31:07 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror -g
# ------------------ #
# Directories:
DIR = ./src
DIRD = ./src/

LIBFT = ./src/Libft
LIBFTD = ./src/Libft/

MLBX = ./src/MinilibX
MLBXD = ./src/MinilibX/
# ------------------- #
# Sorces:
MAK = Makefile

AR = $(DIRD)arch.a
ARL = $(LIBFTD)libft.a
ARML = $(MLBXD)libmlx.a

MAP = ./maps/exemple.ber
#-------------------------------------------------------------#
all:
	@make norm
	@make $(NAME)

# ******************************************************************************* #
# Compiling Region:
$(ARL):
	@echo "\033[1;93m * Compiling Libft -->\033[1;97m\n"
	@make all -C $(LIBFT)

$(ARML):
	@echo "\033[1;93m * Compiling MiniLibX -->\033[1;97m\n"
	@make all -C $(MLBX)

$(AR):
	@echo "\033[1;93m * Compiling SRC -->\033[1;97m\n"
	@make all -C $(DIR)

$(NAME): $(MAK) $(ARL) $(AR)
	@echo "\033[1;93m * Making so_long -->\033[1;97m\n"
	@gcc -o $(NAME) $(ARL) $(AR)
	@echo "\033[1;35m So_Long is ready!\033[1;97m\n"
#-------------------------------------------------------------#
norm:
	@echo "\n\033[1;93m~ Norminette:"
	@make norm -C $(DIR)
	@make norm -C $(LIBFT)
	@echo "\033[1;32m ~ Norminette OK"
	@echo "\033[0;39m\n"
#-------------------------------------------------------------#
run: $(NAME)
	@./$(NAME) $(MAP)
	@make fclean

leaks: $(NAME)
	@echo "\033[1;35m"
	@leaks -atExit -- ./$(NAME) $(MAP)
	@echo "\033[0;39m\n"
	@make fclean

# ******************************************************************************* #
# Debuging region:
debug: $(NAME)
	@lldb $(NAME)

valgrind: $(NAME)
	@valgrind ./$(NAME)

# ********************************************************************************* #
# Clean region
clean:
	@make clean -C $(MLBX)
	@make clean -C $(LIBFT)
	@make clean -C $(DIR)

fclean: clean
	@make fclean -C $(LIBFT)
	@make fclean -C $(DIR)
	@/bin/rm -f $(NAME)
	@/bin/rm -frd debug.out.dSYM
	@/bin/rm -f .DS_Store
	@echo "\033[1;34m All cleaned succesfully\033[1;97m\n"

clear: fclean
	@clear

re: fclean all
# -------------------- #
.PHONY: all clean clear fclean debug norm re run valgrind
# ********************************************************************************** #
