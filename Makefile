# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 17:07:32 by sadoming          #+#    #+#              #
#    Updated: 2023/11/06 17:38:02 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS = so_long_bonus

MAP = ./maps/sadoming_map.ber
# ------------------ #
# Flags:

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I mlx 
FML = -framework OpenGL -framework AppKit
# ------------------ #
# Directories:

DIR = ./src
DIRB = ./bonus

LIBFT = ./Libft
MLX = ./mlx
# ------------------- #
# Sorces:

MAK = Makefile

ARL = $(LIBFT)/libft.a
ARML = $(MLX)/libmlx.a

LIB = so_long.h so_long_structs.h
SRC = so_long_main ft_check_file ft_check_map_sol ft_man_struc\
	  ft_print_map_t ft_start ft_paint_map ft_game ft_exitgame

LIBB = so_long_bonus.h so_long_structs_bonus.h
SRCB = so_long_main_bonus ft_check_file_bonus ft_check_map_sol_bonus ft_man_struc_bonus\
	   ft_start_bonus ft_print_map_t_bonus ft_paint_map_bonus ft_paint_act_map_bonus\
	   ft_start_enemy_bonus ft_game_bonus ft_text_bonus ft_anim_keys_bonus\
	   ft_anim_player_bonus ft_anim_enemy_bonus ft_animate_bonus\
	   ft_move_enemys_bonus ft_lose_game_bonus ft_win_game_bonus ft_exitgame_bonus

OBJ = $(addprefix $(DIR)/, $(addsuffix .o, $(SRC)))
OBJB = $(addprefix $(DIRB)/, $(addsuffix .o, $(SRCB)))
# ******************************************************************************* #
#-------------------------------------------------------------#
all: $(NAME)

bonus: $(BONUS)
#-------------------------------------------------------------#
trueall:
	@make -s norm
	@echo "\033[0;37m\n~ **************************************** ~\n"
	@make -s $(NAME)
	@make -s $(BONUS)
	@make -s run
	@make -s run_bonus

#-------------------------------------------------------------#
norm:
	@make -s norm -C $(LIBFT)
	@echo "\n\033[1;93m~ Norminette:"
	@norminette $(DIR)
	@norminette -R CheckForbiddenSourceHeader $(DIR)
	@echo "\033[1;32m\n ~ Norminette:\t~ OK"
	@echo "\n\033[1;93m~ Norminette bonus:"
	@norminette $(DIRB)
	@norminette -R CheckForbiddenSourceHeader $(DIRB)
	@echo "\033[1;32m\n ~ Norminette bonus:\t~ OK"

#-------------------------------------------------------------#
run: $(NAME)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) $(MAP)"
	@echo "\n~ **************************************** ~\n"
	@./$(NAME) $(MAP)

#-------------------------------------------------------------#
run_bonus: $(BONUS)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(BONUS) $(MAP)"
	@echo "\n~ **************************************** ~\n"
	@./$(BONUS) $(MAP)

#-------------------------------------------------------------#
# ******************************************************************************* #
# Compiling Region:

$(ARML):
	@echo "\033[1;93m\n * Compiling MiniLibX -->\033[1;97m\n"
	@make -s -C $(MLX)

$(ARL):
	@echo "\033[1;93m\n * Compiling Libft -->\033[1;97m\n"
	@make -s -C $(LIBFT)
	@echo "\033[1;37m\n~ **************************************** ~\n"

$(DIR)/%.o : $(DIR)/%.c ./src/$(LIB)
	$(CC) $(CFLAGS) -c $<

#-------------------------------------------------------------#
$(NAME): $(MAK) $(ARML) $(ARL) $(OBJ)
	@echo "\033[1;37m\n~ **************************************** ~\n"
	@echo "\033[1;93m * Making so_long -->\033[1;97m\n"
	@$(CC) $(ARML) $(ARL) $(OBJ) $(FML) -L mlx -l mlx -o $(NAME)
	@echo "\033[1;35m\n~ **************************************** ~\n"
	@echo "  ~\t     So_Long is ready!\t\t ~\n"
	@echo "~ **************************************** ~\n"
#-------------------------------------------------------------#
# Bonus:

$(DIRB)/%.o : $(DIRB)/%.c $(DIRB)/$(LIBB)
	$(CC) $(CFLAGS) -c $<

$(BONUS): $(MAK) $(ARML) $(ARL) $(OBJB)
	@echo "\033[1;37m\n~ **************************************** ~\n"
	@echo "\033[1;93m * Making so_long bonus -->\033[1;97m\n"
	@$(CC) $(ARML) $(ARL) $(OBJB) $(FML) -L mlx -l mlx -o $(BONUS)
	@echo "\033[1;35m\n~ **************************************** ~\n"
	@echo "  ~\t   So_Long Bonus is ready!\t ~\n"
	@echo "~ **************************************** ~\n"
#-------------------------------------------------------------#
# ******************************************************************************* #
# Debuging region:

debug: $(NAME)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) $(MAP)"
	@echo "\n~ **************************************** ~\n"
	@lldb $(NAME) $(MAP)

debug_bonus: $(BONUS)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(BONUS) $(MAP)"
	@echo "\n~ **************************************** ~\n"
	@lldb $(BONUS) $(MAP)

# ------------------

leaks: $(NAME)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) $(MAP)"
	@echo "\n~ **************************************** ~\n"
	@leaks -atExit -- ./$(NAME) $(MAP)

leaks_bonus: $(BONUS)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(BONUS) $(MAP)"
	@echo "\n~ **************************************** ~\n"
	@leaks -atExit -- ./$(BONUS) $(MAP)

# ------------------

val: $(NAME)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) $(MAP)"
	@echo "\n~ **************************************** ~\n"
	@valgrind ./$(NAME) $(MAP)

val_bonus: $(BONUS)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(BONUS) $(MAP)"
	@echo "\n~ **************************************** ~\n"
	@valgrind ./$(BONUS) $(MAP)

# ********************************************************************************* #
# Clean region

clean:
	@make -s clean -C $(MLX)
	@make -s clean -C $(LIBFT)
	@/bin/rm -f $(DIR)/*.o
	@/bin/rm -f $(DIRB)/*.o
	@find . -name ".DS_Store" -type f -delete
	@echo "\033[1;34m\n All obj removed\033[1;97m\n"


fclean: clean
	@make -s clean -C $(MLX)
	@make -s fclean -C $(LIBFT)
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(BONUS)
	@/bin/rm -frd so_long.dSYM
	@/bin/rm -frd so_long_bonus.dSYM
	@echo "\033[1;34m All cleaned succesfully\033[1;97m\n"

clear: fclean
	@clear

re: fclean all
re_bonus: fclean bonus
re_trueall: clear trueall
# -------------------- #
.PHONY: all bonus clean clear fclean debug leaks norm re run val trueall
.PHONY: debug_bonus leaks_bonus re_bonus re_trueall val_bonus
# ********************************************************************************** #
