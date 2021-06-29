/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:33:57 by abiari            #+#    #+#             */
/*   Updated: 2021/06/29 12:03:31 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	int	a;
	int	b;

	if (!(*stack))
		return (0);
	a = pop(stack);
	if (!(*stack))
		return (0);
	b = pop(stack);
	push(stack, a);
	push(stack, b);
	return (1);
}

int	rotate(t_stack **stack)
{
	int	head;

	if (!(*stack))
		return (0);
	head = pop(stack);
	stack_addback(stack, head);
	return (1);
}

void	r_rotate(t_stack **stack)
{
	int		tail;
	t_stack	*new_tail;

	if (!(*stack))
		return ;
	if (stack_len(stack) < 2)
		return ;
	new_tail = *stack;
	while (new_tail->next->next)
		new_tail = new_tail->next;
	tail = new_tail->next->num;
	free(new_tail->next);
	new_tail->next = NULL;
	push(stack, tail);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack))
		return (0);
	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
