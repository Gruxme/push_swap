/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:22:48 by abiari            #+#    #+#             */
/*   Updated: 2021/06/19 18:23:16 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	do_operation(char *op, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(op, "pb"))
		push(b, pop(a));
	else if (!ft_strcmp(op, "pa"))
		push(a, pop(b));
	else if (!ft_strcmp(op, "sa"))
		swap(a);
	else if (!ft_strcmp(op, "sb"))
		swap(b);
	else if (!ft_strcmp(op, "ra"))
		rotate(a);
	else if (!ft_strcmp(op, "rb"))
		rotate(b);
	else if (!ft_strcmp(op, "rra"))
		r_rotate(a);
	else if (!ft_strcmp(op, "rrb"))
		r_rotate(b);
	else if (!ft_strcmp(op, "rr"))
		rr(a, b);
	else if (!ft_strcmp(op, "rrr"))
		rrr(a, b);
	else if (!ft_strcmp(op, "ss"))
		ss(a, b);
}

int	ops_checker(t_stack **a)
{
	char	*line;
	t_stack	*b;

	b = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (check_valid_op(line))
		{
			free(line);
			line = NULL;
			ft_putstr_fd("error\n", 1);
			return (0);
		}
		else
			do_operation(line, a, &b);
		free(line);
		line = NULL;
	}
	free(line);
	if (b != NULL)
	{
		clear_stack(&b);
		return (2);
	}
	return (1);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
