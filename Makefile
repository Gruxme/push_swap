# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiari <abiari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 17:19:26 by abiari            #+#    #+#              #
#    Updated: 2021/06/19 18:31:37 by abiari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

SRC = push_swap.c stack_funcs.c stack_funcs2.c\
swap_ops.c ft_putstr.c sort_three.c sort_four.c sort_five.c\
sort_more.c stack_utils.c

SRC_BONUS = checker_bonus.c stack_funcs.c stack_funcs2.c swap_ops.c\
stack_utils.c checker_utils_bonus.c operations_bonus.c

all: $(NAME)

$(NAME):
	make fclean -C libft/ && make -C libft/ && make clean -C libft/
	$(CC) $(CFLAGS) $(SRC) libft/libft.a -o push_swap

bonus:
	make fclean -C libft/ && make -C libft/ && make clean -C libft/
	$(CC) $(CFLAGS) $(SRC_BONUS) libft/libft.a -o checker

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY: clean fclean all re
