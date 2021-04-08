# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 08:02:11 by kbenlyaz          #+#    #+#              #
#    Updated: 2021/04/07 13:59:47 by kbenlyaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_1 = push_swap
NAME_2 = checker

SRC_CHECKER = checker_utils.c make_operations.c  push_swap_instructions.c push_swap_instructions_2.c sort.c\
		sort_2.c sort_big_2.c sort_big_range.c utils.c utils_2.c utils_3.c checker.c sort_100.c

SRC_PSH_SWAP = checker_utils.c make_operations.c  push_swap_instructions.c push_swap_instructions_2.c sort.c\
		sort_2.c sort_big_2.c sort_big_range.c utils.c utils_2.c utils_3.c push_swap.c sort_100.c




 
all : $(NAME_1) $(NAME_2)

$(NAME_1): $(SRC_PSH_SWAP)
	@gcc -o $(NAME_1) -Wall -Wextra -Werror $(SRC_PSH_SWAP)
$(NAME_2): $(SRC_CHECKER)
	@gcc -o $(NAME_2) -Wall -Wextra -Werror $(SRC_CHECKER)

clean:
	@rm -f ./a.out

fclean:
	@rm -f $(NAME_1)
	@rm -f $(NAME_2)

re: fclean all
.PHONY: clean re fclean san