# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 17:07:32 by sadoming          #+#    #+#              #
#    Updated: 2023/10/18 14:25:39 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = map_gen
MAPNUM = 21
CFLAGS = -Wall -Wextra -Werror -g
# ------------------ #
# Directories:

MAPDIR = GeneratedMaps #The directory where the *.ber are been saved

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
	@make -s $(NAME)
	@make -s gen

#-------------------------------------------------------------#
gen: $(NAME)
	@echo "\033[1;34m~ Generating map...\n"
	@./$(NAME) $(MAPNUM)
	@make -s move

#-------------------------------------------------------------#
move:
	@mkdir -p $(MAPDIR)
	@mv *.ber ./$(MAPDIR)
	@echo "\033[1;34~ The maps are in $(MAPDIR) ~\n"

# ******************************************************************************* #
# Compiling Region:
$(ARL):
	@echo "\033[1;93m * Compiling Libft -->\033[1;97m\n"
	@make -s all -C $(LIBFT)

$(AR):
	@echo "\033[1;93m * Compiling SRC -->\033[1;97m\n"
	@make -s all -C $(DIR)

$(NAME): $(MAK) $(ARL) $(AR)
	@echo "\033[1;93m * Making Map_Gen -->\033[1;97m\n"
	@gcc -o $(NAME) $(ARL) $(AR)
	@echo "\033[1;35m Map_Gen is ready!\033[1;97m\n"
#-------------------------------------------------------------#

# ******************************************************************************* #
# Debuging region:
debug: $(NAME)
	@lldb $(NAME) $(MAPNUM)

val: $(NAME)
	@valgrind ./$(NAME) $(MAPNUM)

# ********************************************************************************* #
# Clean region
clean:
	@make -s clean -C $(LIBFT)
	@make -s clean -C $(DIR)
	@make -s fclean -C $(LIBFT)
	@make -s fclean -C $(DIR)
	@/bin/rm -f .DS_Store

fclean: clean
	@make -s fclean -C $(LIBFT)
	@make -s fclean -C $(DIR)
	@/bin/rm -f $(NAME)
	@/bin/rm -f *.ber
	@echo "\033[1;34m All cleaned succesfully\033[1;97m\n"

clear: fclean
	@clear

re: fclean all
# -------------------- #
.PHONY: all clean clear fclean debug leaks gen norm re val
# ********************************************************************************** #
