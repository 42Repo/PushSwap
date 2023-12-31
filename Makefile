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
SRC		=	ft_push_swap.c\
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
			ft_push_swap_free.c\
			ft_push_swap_check_input_.c\
			ft_push_swap_check_input_utils.c\
			ft_push_swap_input_check_and_create_tab_utils.c

SRC_BONUS = ft_push_swap_bonus.c\
			ft_push_swap_utils.c\
			ft_push_swap_input_check_and_create_tab.c\
			ft_push_swap_fill_stack.c\
			ft_push_swap_push_bonus.c\
			ft_push_swap_reverse_rotate_bonus.c\
			ft_push_swap_rotate_bonus.c\
			ft_push_swap_swap_bonus.c\
			ft_push_swap_free_bonus.c\
			ft_push_swap_check_input_bonus.c\
			ft_push_swap_check_input_utils_bonus.c\
			ft_push_swap_utils_bonus.c\
			ft_push_swap_input_check_and_create_tab_utils.c


OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

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
	@rm -f $(OBJ_BONUS)
	@echo "$(BRed)Erase .o files$(RESET)"

fclean : clean
	@make fclean --no-print-directory -C $(libft)
	@rm -f $(NAME) libft.a
	@rm -f checker
	@rm -f push_swap
	@echo "$(BRed)Erase $(NAME) and libft.a$(RESET)"

re : fclean all

bonus : $(OBJ_BONUS)
	@make --no-print-directory -C $(libft)
	@cp $(libft)libft.a libft.a
	@clang -gdwarf-4 -fPIE -O3 $(CFLAGS) -o checker $(OBJ_BONUS) libft.a
	@echo "$(BGreen)Compilation OK$(RESET)"

test : all
	clear && make && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -s ./push_swap "65430 13680 99941 59807 67691 96703 27419 74229 21633 97644 97918 8169 61331 98634 69250 56084 80062 69585 2275 79339 10022 12571 3394 24284 18698 89375 49412 83052 81429 72005 44268 10723 93289 54909 15849 56340 90332 98272 13734 89881 23641 467 15886 99353 57202 95951 28196 12885 69054 61992 38840 17126 60936 67110 70444 10551 53572 83057 94814 50222 75119 23628 48072 53128 97512 80219 82166 51002 10247 82385 90724 10817 44672 50867 23309 34775 77221 20641 80154 75286 23693 90407 34742 76780 64280 64283 22633 65414 50109 25100 44147 69723 89273 60923 16045 91249 94603 81847 6236 70575 92284 35261 15367 25003 31517 10783 61716 89047 94922 24088 89442 87976 39860 52904 73773 57452 54119 14001 8539 12186 44271 99788 75882 75486 41953 6449 4979 97157 59906 62833 97826 25380 8203 62461 15813 66861 99229 2465 57876 99742 10549 87537 21344 41493 78983 35508 85890 75643 19341 6428 52160 70946 70194 54378 52566 65645 63226 74818 113 86708 24913 41491 46017 64083 66254 63857 95146 83179 38551 8864 90917 51079 48112 35832 16197 94946 27126 99406 65473 14586 33517 82850 7323 53769 14511 3492 62789 53944 470 32526 11881 58358 41786 88351 71378 18908 90208 34933 93838 91056 22134 1280 17191 55784 96169 3073 40482 49288 77930 92293 86530 14302 84419 49093 69342 8159 31149 90728 23335 85811 83568 43220 96416 29578 99716 37436 40469 3771 61738 8301 49026 12104 2350 75135 14908 66992 58426 27847 67620 38830 4657 6808 41545 3472 11374 84145 73212 98060 14366 24810 96793 41319 30936 67801 17317 27564 449 94713 57635 44448 79098 39764 82965 54734 23112 11237 83590 61011 1196 30249 50592 97335 52627 42202 30965 10744 9491 2101 74467 41112 50502 98305 10204 89645 54956 93360 65720 79800 97514 70591 61405 63191 82794 42397 59854 27552 96004 38209 20405 43507 8733 78554 60319 46342 14278 78515 56953 70707 43949 90393 8440 33586 78234 10269 94337 29973 49079 66823 37107 3048 38785 22244 9426 78732 18322 75556 19274 45449 95456 42002 38223 34346 23738 9123 68966 16145 27165 88926 79006 74549 31357 59173 98187 98220 1089 53686 74548 20441 48285 29610 41123 88798 97226 8459 38920 16956 72148 94029 77446 45499 38148 17553 33338 833 8170 54902 52700 36247 93287 15204 53261 73765 3862 48685 33029 75906 4287 69798 86623 45903 76412 63601 99841 48637 43272 85413 55740 38296 64651 24382 89212 19836 5099 65814 60962 248 96140 67517 12458 4386 2183 77487 12129 95110 6910 79503 2444 96965 49524 88751 78630 30791 44019 5164 47583 41146 26845 11751 66160 64611 77467 35022 48293 99379 22084 39475 59239 19785 50273 16792 17110 8961 2887 42464 74626 44406 65228 73929 32746 39648 55725 40640 57382 34121 75597 64689 67365 13604 43370 45421 43375 46640 40341 45154 66510 79391 62887 89857 6566 54613 46566 35460 91657 92058 6789 95316 75023 85359 91334 92036 87507 25599 94904 49755 22115 63453 95897 19453 92708 81007 40483 38174 50587 57136 92414 43360 78193 85353 39757 24733 91428 22577 58328 6801 75879 54870 90232 15668 3223 80378" | wc -l

.PHONY: all fclean clean re test


