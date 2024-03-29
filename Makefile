# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 17:42:16 by asuc              #+#    #+#              #
#    Updated: 2024/02/10 20:24:42 by asuc             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BGreen	=	$(shell echo "\033[1;32m")
RESET	=	$(shell echo "\033[0m")
BRed	=	$(shell echo "\033[1;31m")
NAME 	=	push_swap
NAME_BONUS = checker
COMP 	=	cc
CFLAGS 	=	-Wall -Werror -Wextra
libft	=	Libft/
SRC		=	srcs/ft_push_swap.c\
			srcs/utils.c\
			srcs/input_check_and_create_tab.c\
			srcs/fill_stack.c\
			srcs/sort.c\
			srcs/push.c\
			srcs/reverse_rotate.c\
			srcs/rotate.c\
			srcs/swap.c\
			srcs/sort_three.c\
			srcs/lis.c\
			srcs/lis_utils.c\
			srcs/free.c\
			srcs/check_input.c\
			srcs/check_input_utils.c\
			srcs/input_check_and_create_tab_utils.c \
			srcs/sort_part1.c \
			srcs/sort_part1_utils.c \
			srcs/sort_part2.c \
			srcs/sort_part2_utils.c \
			srcs/sort_utils.c \
			srcs/sort_utils2.c \
			srcs/push_swap_utils.c


SRC_BONUS = bonus/ft_push_swap.c\
			bonus/utils.c\
			bonus/input_check_and_create_tab.c\
			bonus/fill_stack.c\
			bonus/push.c\
			bonus/reverse_rotate.c\
			bonus/rotate.c\
			bonus/swap.c\
			bonus/free.c\
			bonus/check_input.c\
			bonus/check_input_utils.c\
			bonus/input_check_and_create_tab_utils.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

%.o : %.c
	@$(COMP) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	@make --no-print-directory -C $(libft)
	@cp $(libft)libft.a libft.a
	@clang $(CFLAGS) -o $(NAME) $(OBJ) libft.a
	@echo "$(BGreen)Compilation OK$(RESET)"

bonus : $(OBJ_BONUS)
	@make --no-print-directory -C $(libft)
	@cp $(libft)libft.a libft.a
	@clang $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) libft.a
	@echo "$(BGreen)Compilation OK$(RESET)"

clean :
	@make clean --no-print-directory -C $(libft)
	@rm -f $(OBJ) $(OBJ_BONUS)
	@echo "$(BRed)Erase .o files$(RESET)"

fclean : clean
	@make fclean --no-print-directory -C $(libft)
	@rm -f $(NAME) $(NAME_BONUS) libft.a
	@echo "$(BRed)Erase $(NAME) and libft.a$(RESET)"

re : fclean all

.PHONY: all fclean clean re bonus


