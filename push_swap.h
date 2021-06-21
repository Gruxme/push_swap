/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:59:20 by abiari            #+#    #+#             */
/*   Updated: 2021/06/21 16:01:27 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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

typedef struct s_data
{
	int	len;
	int	pos;
	int	middle;
}				t_data;

int		peek(const t_stack *stack);
void	clear_stack(t_stack **stack);
void	push(t_stack **stack, int num);
void	print_stack(const t_stack *stack, void display_num(int num));
int		pop(t_stack **stack);
void	stack_addback(t_stack **stack, int num);
t_stack	*new_node(int num);
int		swap(t_stack **stack);
void	sort_three(t_stack **a);
int		rotate(t_stack **stack);
void	r_rotate(t_stack **stack);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a);
int		find_min(t_stack **stack);
int		find_max(t_stack **stack);
int		stack_len(t_stack **stack);
int		find_pos(t_stack **stack, int num);
void	make_head(t_stack **stack, int new_head, int type);
t_stack	*stack_dup(t_stack **stack);
void	sort_five(t_stack **a);
void	sort_more(t_stack **a);
int		is_sorted(t_stack **stack);
#endif
