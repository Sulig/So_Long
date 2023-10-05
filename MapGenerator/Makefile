# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 17:07:32 by sadoming          #+#    #+#              #
#    Updated: 2023/10/05 20:27:15 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = map_gen
MAPNUM = 1
CFLAGS = -Wall -Wextra -Werror -g
# ------------------ #
# Directories:
DIR = ./src
DIRD = ./src/

LIBFT = ./src/Libft
LIBFTD = ./src/Libft/
# ------------------- #
# Sorces:
MAK = Makefile

AR = $(DIRD)gen.a
ARL = $(LIBFTD)libft.a
ARML = $(MLBXD)libmlx.a
#-------------------------------------------------------------#
all: $(MAK) 
	@make $(NAME)
	@make gen

#-------------------------------------------------------------#
gen: $(NAME)
	@echo "\033[1;34m Generating map...\n"
	@./$(NAME) $(MAPNUM)

#-------------------------------------------------------------#

# ******************************************************************************* #
# Compiling Region:
$(ARL):
	@echo "\033[1;93m * Compiling Libft -->\033[1;97m\n"
	@make all -C $(LIBFT)

$(AR):
	@echo "\033[1;93m * Compiling SRC -->\033[1;97m\n"
	@make all -C $(DIR)

$(NAME): $(MAK) $(ARL) $(AR)
	@echo "\033[1;93m * Making Map_Gen -->\033[1;97m\n"
	@gcc -o $(NAME) $(ARL) $(AR)
	@echo "\033[1;35m Map_Gen is ready!\033[1;97m\n"
#-------------------------------------------------------------#

# ******************************************************************************* #
# Debuging region:
debug: $(NAME)
	@lldb $(NAME)

val: $(NAME)
	@valgrind ./$(NAME)

# ********************************************************************************* #
# Clean region
clean:
	@make clean -C $(LIBFT)
	@make clean -C $(DIR)
	@/bin/rm -f .DS_Store

fclean: clean
	@make fclean -C $(LIBFT)
	@make fclean -C $(DIR)
	@/bin/rm -f $(NAME)
	@/bin/rm -frd map_gen.dSYM
	@echo "\033[1;34m All cleaned succesfully\033[1;97m\n"

clear: fclean
	@clear

re: fclean all
# -------------------- #
.PHONY: all clean clear fclean debug leaks gen norm re val
# ********************************************************************************** #
