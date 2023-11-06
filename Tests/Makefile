# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 17:07:32 by sadoming          #+#    #+#              #
#    Updated: 2023/11/06 19:08:59 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TLIB = test_libft.out
TFTP = test_printf.out
TGNL = test_gnl.out

# ------------------ #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I mlx 
FML = -framework OpenGL -framework AppKit
# ------------------ #
# Directories:

# Change this directories to yours->
DIR = ../
DSRC = $(DIR)src
DBNS = $(DIR)bonus
DLIB = $(DIR)Libft

NAME = $(DIR)so_long		#So_Long
BONUS = $(DIR)so_long_bonus #So_Long_Bonus

# ---------------------------------}
# ------------------- #

DMAPS = ./Error_Maps

# ---------------------------------------------- #
# Error maps -> #This maps should output "Error"

ERMAP0 = $(DMAPS)/no_format
ERMAP1 = $(DMAPS)/other_format.txt
ERMAP2 = $(DMAPS)/no_existent.txt
ERMAP3 = $(DMAPS)/no_existent.ber
ERMAP4 = $(DMAPS)/empty.ber
ERMAP5 = $(DMAPS)/other_symbol.ber
ERMAP6 = $(DMAPS)/diferent_size.ber
ERMAP7 = $(DMAPS)/no_closed.ber
ERMAP8 = $(DMAPS)/no_closed_first_first.ber
ERMAP9 = $(DMAPS)/no_closed_first_last.ber
ERMAP10 = $(DMAPS)/no_closed_first_med.ber
ERMAP11 = $(DMAPS)/no_closed_last_first.ber
ERMAP12 = $(DMAPS)/no_closed_last_last.ber
ERMAP13 = $(DMAPS)/no_closed_last_med.ber
ERMAP14 = $(DMAPS)/no_collectable.ber
ERMAP15 = $(DMAPS)/no_exit.ber
ERMAP16 = $(DMAPS)/no_player.ber
ERMAP17 = $(DMAPS)/two_exits.ber
ERMAP18 = $(DMAPS)/two_players.ber
ERMAP19 = $(DMAPS)/cant_rearch_exit.ber
ERMAP20 = $(DMAPS)/cant_rearch_anything.ber
ERMAP21 = $(DMAPS)/cant_rearch_collectable.ber
ERMAP22 = $(DMAPS)/folder.ber

# ---------------------------------------------- #
# ******************************************************************************* #

#-------------------------------------------------------------#
all:
	@make -s norm
	@echo "\033[0;37m\n~ **************************************** ~\n"
	@make -s $(NAME)
	@make -s $(BONUS)
#-------------------------------------------------------------#
help:
	@echo "\033[1;37m ~ Posible comands:\n"
	@echo "\t~ all  \t\t #-> Make so_long & so_long_bonus\n"
	@echo "\t~ test \t\t #-> Test so_long with error_maps\n"
	@echo "\t~ test_bonus \t #-> Test so_long_bonus with error_maps\n"
	@echo "\t~ leaks \t #-> Test so_long with LEAKS & error_maps\n"
	@echo "\t~ leaks_bonus \t #-> Test so_long_bonus with LEAKS & error_maps\n"
#-------------------------------------------------------------#
test: $(NAME)
	@make -s test_error_maps

test_bonus: $(BONUS)
	@make -s test_error_maps_bonus
#-------------------------------------------------------------#
norm:
	@echo "\n\033[1;93m~ Norminette:"
	@norminette $(DLIB)
	@norminette -R CheckForbiddenSourceHeader $(DLIB)
	@echo "\033[1;32m\n ~ Norminette:\t~ OK\033[1;93m\n"
	@norminette $(DSRC)
	@norminette -R CheckForbiddenSourceHeader $(DSRC)
	@echo "\033[1;32m\n ~ Norminette:\t~ OK"
	@norminette $(DBNS)
	@norminette -R CheckForbiddenSourceHeader $(DBNS)
	@echo "\033[1;32m\n ~ Norminette:\t~ OK"

#-------------------------------------------------------------#
test_error_maps:
	@echo "\033[1;33m\n~ **************************************** ~\n"
	@echo "~ Testing Errors\n"
	@echo "\t~ This will call your so_long\n"
	@echo "\t~ Your so_long should output: \"Error\"\n"
	@echo "\n~ **************************************** ~\n"
	@echo "\033[1;34m ~ Testing: $(NAME)\n"
	@./$(NAME)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP1) $(ERMAP1)\n"
	@./$(NAME) $(ERMAP1) $(ERMAP1)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP0)\n"
	@./$(NAME) $(ERMAP0)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP1)\n"
	@./$(NAME) $(ERMAP1)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP2)\n"
	@./$(NAME) $(ERMAP2)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP3)\n"
	@./$(NAME) $(ERMAP3)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP4)\n"
	@./$(NAME) $(ERMAP4)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP5)\n"
	@./$(NAME) $(ERMAP5)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP6)\n"
	@./$(NAME) $(ERMAP6)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP7)\n"
	@./$(NAME) $(ERMAP7)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP8)\n"
	@./$(NAME) $(ERMAP8)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP9)\n"
	@./$(NAME) $(ERMAP9)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP10)\n"
	@./$(NAME) $(ERMAP10)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP11)\n"
	@./$(NAME) $(ERMAP11)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP12)\n"
	@./$(NAME) $(ERMAP12)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP13)\n"
	@./$(NAME) $(ERMAP13)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP14)\n"
	@./$(NAME) $(ERMAP14)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP15)\n"
	@./$(NAME) $(ERMAP15)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP16)\n"
	@./$(NAME) $(ERMAP16)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP17)\n"
	@./$(NAME) $(ERMAP17)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP18)\n"
	@./$(NAME) $(ERMAP18)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP19)\n"
	@./$(NAME) $(ERMAP19)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP20)\n"
	@./$(NAME) $(ERMAP20)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP21)\n"
	@./$(NAME) $(ERMAP21)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP22)\n"
	@./$(NAME) $(ERMAP22)
	@echo "\033[1;37m\n~ **************************************** ~\n"
	@echo "   If all your outputs have the \"Error\"\n"
	@echo "\033[1;32m   Then your control errors is ok!\n"
	@echo "\033[1;37m\n~ **************************************** ~\n"
#-------------------------------------------------------------#

test_error_maps_bonus:
	@echo "\033[1;33m\n~ **************************************** ~\n"
	@echo "~ Testing Errors\n"
	@echo "\t~ This will call your so_long_bonus\n"
	@echo "\t~ Your so_long_bonus should output: \"Error\"\n"
	@echo "\n~ **************************************** ~\n"
	@echo "\033[1;34m ~ Testing: $(BONUS)\n"
	@./$(BONUS)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP1) $(ERMAP1)\n"
	@./$(BONUS) $(ERMAP1) $(ERMAP1)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP0)\n"
	@./$(BONUS) $(ERMAP0)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP1)\n"
	@./$(BONUS) $(ERMAP1)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP2)\n"
	@./$(BONUS) $(ERMAP2)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP3)\n"
	@./$(BONUS) $(ERMAP3)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP4)\n"
	@./$(BONUS) $(ERMAP4)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP5)\n"
	@./$(BONUS) $(ERMAP5)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP6)\n"
	@./$(BONUS) $(ERMAP6)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP7)\n"
	@./$(BONUS) $(ERMAP7)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP8)\n"
	@./$(BONUS) $(ERMAP8)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP9)\n"
	@./$(BONUS) $(ERMAP9)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP10)\n"
	@./$(BONUS) $(ERMAP10)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP11)\n"
	@./$(BONUS) $(ERMAP11)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP12)\n"
	@./$(BONUS) $(ERMAP12)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP13)\n"
	@./$(BONUS) $(ERMAP13)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP14)\n"
	@./$(BONUS) $(ERMAP14)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP15)\n"
	@./$(BONUS) $(ERMAP15)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP16)\n"
	@./$(BONUS) $(ERMAP16)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP17)\n"
	@./$(BONUS) $(ERMAP17)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP18)\n"
	@./$(BONUS) $(ERMAP18)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP19)\n"
	@./$(BONUS) $(ERMAP19)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP20)\n"
	@./$(BONUS) $(ERMAP20)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP21)\n"
	@./$(BONUS) $(ERMAP21)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP22)\n"
	@./$(BONUS) $(ERMAP22)
	@echo "\033[1;37m\n~ **************************************** ~\n"
	@echo "   If all your outputs have the \"Error\"\n"
	@echo "\033[1;32m   Then your control errors is ok!\n"
	@echo "\033[1;37m\n~ **************************************** ~\n"
#-------------------------------------------------------------#

# ------------------

leaks: $(NAME)
	@echo "\033[1;33m\n~ **************************************** ~\n"
	@echo "~ Testing Leaks\n"
	@echo "\t~ This will call your so_long\n"
	@echo "\t~ Your so_long should output: \"Error\" and don't generate LEAKS!\n"
	@echo "\n~ **************************************** ~\n"
	@echo "\033[1;34m ~ Testing: $(NAME)\n"
	@leaks -atExit -- ./$(NAME)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP1) $(ERMAP1)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP1) $(ERMAP1)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP0)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP0)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP1)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP1)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP2)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP2)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP3)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP3)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP4)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP4)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP5)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP5)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP6)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP6)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP7)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP7)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP8)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP8)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP9)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP9)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP10)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP10)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP11)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP11)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP12)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP12)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP13)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP13)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP14)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP14)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP15)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP15)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP16)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP16)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP17)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP17)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP18)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP18)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP19)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP19)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP20)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP20)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP21)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP21)
	@echo "\033[1;34m\n ~ Testing: $(NAME) $(ERMAP22)\n"
	@leaks -atExit -- ./$(NAME) $(ERMAP22)
	@echo "\033[1;37m\n~ **************************************** ~\n"
	@echo "\033[1;32m If all you arrived here, then you should don't have leaks 😀"
	@echo "\033[1;37m\n~ **************************************** ~\n"

leaks_bonus: $(BONUS)
	@echo "\033[1;33m\n~ **************************************** ~\n"
	@echo "~ Testing Leaks\n"
	@echo "\t~ This will call your so_long_bonus\n"
	@echo "\t~ Your so_long_bonus should output: \"Error\" and don't generate LEAKS!\n"
	@echo "\n~ **************************************** ~\n"
	@echo "\033[1;34m ~ Testing: $(BONUS)\n"
	@leaks -atExit -- ./$(BONUS)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP1) $(ERMAP1)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP1) $(ERMAP1)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP0)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP0)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP1)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP1)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP2)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP2)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP3)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP3)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP4)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP4)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP5)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP5)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP6)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP6)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP7)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP7)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP8)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP8)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP9)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP9)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP10)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP10)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP11)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP11)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP12)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP12)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP13)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP13)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP14)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP14)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP15)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP15)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP16)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP16)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP17)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP17)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP18)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP18)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP19)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP19)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP20)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP20)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP21)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP21)
	@echo "\033[1;34m\n ~ Testing: $(BONUS) $(ERMAP22)\n"
	@leaks -atExit -- ./$(BONUS) $(ERMAP22)
	@echo "\033[1;37m\n~ **************************************** ~\n"
	@echo "\033[1;32m If all you arrived here, then you should don't have leaks 😀"
	@echo "\033[1;37m\n~ **************************************** ~\n"

# ------------------

# ******************************************************************************* #
# Compiling Region:

$(NAME):
	@make -s all -C $(DIR)

$(BONUS):
	@make -s bonus -C $(DIR)

# ******************************************************************************* #
# Clean region
clean:
	@make -s clean -C $(DIR)
	@find ../ -name "*.o" -type f -delete
	@find ../ -name ".DS_Store" -type f -delete
	@echo "\033[1;34m All obj removed\033[1;97m\n"


fclean: clean
	@find ../ -name "*.a" -type f -delete
	@make -s fclean -C $(DIR)
	@echo "\033[1;34m All cleaned succesfully\033[1;97m\n"

clear: fclean
	@clear

re: fclean all
# -------------------- #
.PHONY: all clean clear fclean norm re test test_error_maps leaks
.PHONY: test_bonus test_error_maps_bonus leaks_bonus
# ********************************************************************************** #
