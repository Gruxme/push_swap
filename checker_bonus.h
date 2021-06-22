/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:15:53 by abiari            #+#    #+#             */
/*   Updated: 2021/06/22 10:27:00 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# define BUFFER_SIZE 512
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}				t_stack;

int		peek(const t_stack *stack);
void	clear_stack(t_stack **stack);
void	push(t_stack **stack, int num);
void	print_stack(const t_stack *stack, void display_num(int num));
int		pop(t_stack **stack);
void	stack_addback(t_stack **stack, int num);
t_stack	*new_node(int num);
int		swap(t_stack **stack);
int		rotate(t_stack **stack);
void	r_rotate(t_stack **stack);
int		find_min(t_stack **stack);
int		find_max(t_stack **stack);
int		stack_len(t_stack **stack);
int		find_pos(t_stack **stack, int num);
void	make_head(t_stack **stack, int new_head, int type);
t_stack	*stack_dup(t_stack **stack);
void	do_operation(char *op, t_stack **a, t_stack **b);
int		ops_checker(t_stack **a);
int		is_sorted(t_stack **stack);
void	rrr(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
int		check_valid_op(char *line);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
#endif
