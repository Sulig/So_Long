# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 17:07:32 by sadoming          #+#    #+#              #
#    Updated: 2023/10/11 19:59:51 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
MAP = ./maps/cross_map.ber
# ------------------ #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I mlx 
FML = -framework OpenGL -framework AppKit
# ------------------ #
# Directories:
DIR = ./src
DIRD = ./src/

LIBFT = ./Libft
LIBFTD = ./Libft/

MLX = ./mlx
MLXD = ./mlx/
# ------------------- #
# Sorces:
MAK = Makefile

ARL = $(LIBFTD)libft.a
ARML = $(MLXD)libmlx.a

LIB = so_long.h so_long_structs.h
SRC = so_long_main ft_check_file ft_check_map_sol ft_man_struc colors\
	  ft_grafics

OBJ = $(addprefix $(DIRD), $(addsuffix .o, $(SRC)))
# ******************************************************************************* #
#-------------------------------------------------------------#
all:
	@make -s norm
	@echo "\033[0;37m\n~ **************************************** ~\n"
	@make $(NAME)
	@make -s run

#-------------------------------------------------------------#
norm:
	@make -s norm -C $(LIBFT)
	@echo "\n\033[1;93m~ Norminette:"
	@norminette $(DIR)
	@norminette -R CheckForbiddenSourceHeader $(DIR)
	@echo "\033[1;32m\n ~ Norminette:\t~ OK"

#-------------------------------------------------------------#
run: $(NAME)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) $(MAP)"
	@echo "\n~ **************************************** ~\n"
	@./$(NAME) $(MAP)

#-------------------------------------------------------------#

# ******************************************************************************* #
# Compiling Region:

$(ARML):
	@echo "\033[1;93m * Compiling MiniLibX -->\033[1;97m\n"
	@make -s -C $(MLX)

$(ARL):
	@echo "\033[1;93m * Compiling Libft -->\033[1;97m\n"
	@make -s -C $(LIBFT)

$(DIRD)%.o : $(DIR)/%.c ./src/$(LIB)
	$(CC) $(CFLAGS) -c $<
	@echo "\033[1;32m SRC Compiled Successfully\033[1;97m\n"

$(NAME): $(ARML) $(ARL) $(OBJ)
	@echo "\033[1;37m\n~ **************************************** ~\n"
	@echo "\033[1;93m * Making so_long -->\033[1;97m\n"
	@$(CC) $(ARML) $(ARL) $(OBJ) $(FML) -L mlx -l mlx -o $(NAME)
	@echo "\033[1;35m So_Long is ready!\033[1;97m\n"
#-------------------------------------------------------------#

# ******************************************************************************* #
# Debuging region:
debug: $(NAME)
	@echo "\033[1;34m Running ./$(NAME) $(MAP)\n"
	@lldb $(NAME) $(MAP)

val: $(NAME)
	@valgrind ./$(NAME) $(MAP)

# ********************************************************************************* #
# Clean region
clean:
	@make -s clean -C $(MLX)
	@make -s clean -C $(LIBFT)
	@/bin/rm -f $(DIRD)*.o
	@echo "\033[1;34m All obj removed\033[1;97m\n"

dsrm: clean
	@/bin/rm -f .DS_Store
	@/bin/rm -f ./maps/DS_Store
	@/bin/rm -f ./sprites/DS_Store
	@/bin/rm -f ./$(DIR)/DS_Store
	@/bin/rm -f $(MLX)/DS_Store

fclean: dsrm
	@make -s clean -C $(MLX)
	@make -s fclean -C $(LIBFT)
	@/bin/rm -f $(NAME)
	@/bin/rm -frd so_long.dSYM
	@echo "\033[1;34m All cleaned succesfully\033[1;97m\n"

clear: fclean
	@clear

re: fclean all
# -------------------- #
.PHONY: all clean clear fclean debug norm re run val
# ********************************************************************************** #
