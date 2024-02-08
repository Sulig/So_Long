# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 16:14:42 by sadoming          #+#    #+#              #
#    Updated: 2024/02/08 19:56:05 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -g
# ---------------- #
# Directories:
STR = ft_str/
LST = ft_lst/
# ---------------- #
MAK = Makefile
LIB = libft.h

SRC = ft_atoi.c ft_calloc.c ft_itoa.c ft_printf.c ft_switch_cast.c get_next_line.c

SRC += $(STR)ft_split.c $(STR)ft_strchr.c $(STR)ft_strcpy.c $(STR)ft_strjoin.c\
	   $(STR)ft_strcut.c $(STR)ft_strlen.c $(STR)ft_strstr.c $(STR)ft_strtrim.c\
	   $(STR)ft_substr.c $(STR)ft_strinter.c
	
OBJ = $(SRC:%.c=%.o)
# ********************************************* #
#----------------------#
all: $(NAME)
#----------------------#
%.o : %.c $(LIB) $(MAK)
	@gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[1;32m Libft Compiled Successfully\033[1;97m\n"

#-------------------------------------------------------------#
norm:
	@echo "\n\033[1;93m~ Norminette:"
	@norminette $(SRC)
	@norminette -R CheckForbiddenSourceHeader $(SRC)
	@echo "\033[1;32m \nLibft norminette:\t~ OK\n"
#-------------------------------------------------------------#
clean:
	@/bin/rm -f $(OBJ)

fclean : clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f .DS_Store

re: fclean all

.PHONY: all bonus clean fclean re
# ******************************************* #
