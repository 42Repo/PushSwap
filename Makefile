# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 17:42:16 by asuc              #+#    #+#              #
#    Updated: 2023/08/12 17:42:16 by asuc             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BGreen	=	$(shell echo "\033[1;32m")
RESET	=	$(shell echo "\033[0m")
BRed	=	$(shell echo "\033[1;31m")
NAME 	=	push_swap
COMP 	=	clang
CFLAGS 	=	-Wall -Werror -Wextra
libft	=	Libft/
SRC		=	main.c\
			ft_push_swap.c\
			ft_push_swap_utils.c\
			ft_push_swap_input_check_and_create_tab.c\
			ft_push_swap_fill_stack.c\
			ft_push_swap_sort.c\
			ft_push_swap_push.c\
			ft_push_swap_reverse_rotate.c\
			ft_push_swap_rotate.c\
			ft_push_swap_swap.c\
			ft_push_swap_sort_three.c\
			ft_push_swap_lis.c\
			ft_push_swap_lis_utils.c\


OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	@$(COMP) -gdwarf-4 -fPIE -O3 -march=native $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	@make --no-print-directory -C $(libft)
	@cp $(libft)libft.a libft.a
	@clang -gdwarf-4 -fPIE -O3 $(CFLAGS) -o $(NAME) $(OBJ) libft.a
	@echo "$(BGreen)Compilation OK$(RESET)"

clean :
	@make clean --no-print-directory -C $(libft)
	@rm -f $(OBJ)
	@echo "$(BRed)Erase .o files$(RESET)"

fclean : clean
	@make fclean --no-print-directory -C $(libft)
	@rm -f $(NAME) libft.a
	@echo "$(BRed)Erase $(NAME) and libft.a$(RESET)"

re : fclean all

test : all
	clear && make && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -s ./push_swap "367 47 128 400 256 485 296 376 492 439 13 201 386 177 369 430 15 66 465 46 6 4 45"

.PHONY: all fclean clean re


