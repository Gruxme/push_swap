/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:55:17 by abiari            #+#    #+#             */
/*   Updated: 2021/06/29 10:48:12 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stack(t_stack **stack)
{
	if (*stack)
	{
		clear_stack(&(*stack)->next);
		free(*stack);
		*stack = NULL;
	}
}

t_stack	*new_node(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->num = num;
	new->next = NULL;
	return (new);
}

int	stack_len(t_stack **stack)
{
	t_stack	*tmp;
	int		len;

	len = 0;
	if (!(*stack))
		return (0);
	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int	find_pos(t_stack **stack, int num)
{
	int		pos;
	t_stack	*tmp;

	if (!(*stack))
		return (-1);
	tmp = *stack;
	pos = 1;
	while (tmp)
	{
		if (tmp->num == num)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

t_stack	*stack_dup(t_stack **stack)
{
	t_stack	*dup;
	t_stack	*tmp;

	if (!(*stack))
		return (NULL);
	tmp = *stack;
	dup = NULL;
	while (tmp)
	{
		stack_addback(&dup, tmp->num);
		tmp = tmp->next;
	}
	return (dup);
}
