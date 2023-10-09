# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 17:07:32 by sadoming          #+#    #+#              #
#    Updated: 2023/10/09 16:57:42 by sadoming         ###   ########.fr        #
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

MAP = ./maps/cross_map.ber
#-------------------------------------------------------------#
all: $(MAK)
	@make norm
	@make $(NAME)
	@make run

#-------------------------------------------------------------#
norm:
	@make norm -C $(DIR)
	@make norm -C $(LIBFT)
	@echo "\033[1;32m ~ Norminette OK"
	@echo "\033[0;39m\n"

#-------------------------------------------------------------#
run: $(NAME)
	@echo "\033[1;34m Running ./$(NAME) $(MAP)\n"
	@./$(NAME) $(MAP)

#-------------------------------------------------------------#

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


# ******************************************************************************* #
# Debuging region:
debug: $(NAME)
	@echo "\033[1;34m Running ./$(NAME) $(MAP)\n"
	@lldb $(NAME) $(MAP)

leaks: $(NAME)
	@echo "\033[1;34m Running ./$(NAME) $(MAP)"
	@echo "\033[1;35m\n"
	@leaks -atExit -- ./$(NAME) $(MAP)
	@echo "\033[0;39m\n"
	@make fclean

valgrind: $(NAME)
	@valgrind ./$(NAME) $(MAP)

# ********************************************************************************* #
# Clean region
clean:
	@make clean -C $(MLBX)
	@make clean -C $(LIBFT)
	@make clean -C $(DIR)

dsrm: clean
	@/bin/rm -f .DS_Store
	@/bin/rm -f ./maps/DS_Store
	@/bin/rm -f ./sprites/DS_Store
	@/bin/rm -f $(DIRD)MinilibX/DS_Store

fclean: clean dsrm
	@make fclean -C $(LIBFT)
	@make fclean -C $(DIR)
	@/bin/rm -f $(NAME)
	@echo "\033[1;34m All cleaned succesfully\033[1;97m\n"

clear: fclean
	@clear

re: fclean all
# -------------------- #
.PHONY: all clean clear fclean debug norm re run valgrind
# ********************************************************************************** #
