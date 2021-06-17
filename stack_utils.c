/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:41:52 by abiari            #+#    #+#             */
/*   Updated: 2021/06/17 20:19:16 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack **stack)
{
	t_stack	*a_tmp;
	int		min;

	a_tmp = *stack;
	min = a_tmp->num;
	while (a_tmp)
	{
		if (a_tmp->num < min)
			min = a_tmp->num;
		a_tmp = a_tmp->next;
	}
	return (min);
}

int	find_max(t_stack **stack)
{
	t_stack	*a_tmp;
	int		max;

	a_tmp = *stack;
	max = a_tmp->num;
	while (a_tmp)
	{
		if (a_tmp->num > max)
			max = a_tmp->num;
		a_tmp = a_tmp->next;
	}
	return (max);
}

void	make_head(t_stack **stack, int new_head, int type)
{
	int	len;
	int	pos;

	len = stack_len(stack);
	pos = find_pos(stack, new_head);
	if (pos == 1)
		return ;
	if (pos == 2)
	{
		swap(stack);
		if (type == 0)
			ft_putstr_fd("sa\n", 1);
		else
			ft_putstr_fd("sb\n", 1);
		return ;
	}
	if (len % 2 == 0)
	{
		if (pos > len / 2)
		{
			while (pos < len + 1)
			{
				r_rotate(stack);
				if (type == 0)
					ft_putstr_fd("rra\n", 1);
				else
					ft_putstr_fd("rrb\n", 1);
				pos++;
			}
		}
		else
		{
			while (pos > 1)
			{
				rotate(stack);
				if (type == 0)
					ft_putstr_fd("ra\n", 1);
				else
					ft_putstr_fd("rb\n", 1);
				pos--;
			}
		}
	}
	else
	{
		if (pos > (len / 2) + 1)
		{
			while (pos < len + 1)
			{
				r_rotate(stack);
				if (type == 0)
					ft_putstr_fd("rra\n", 1);
				else
					ft_putstr_fd("rrb\n", 1);
				pos++;
			}
		}
		else
		{
			while (pos > 1)
			{
				rotate(stack);
				if (type == 0)
					ft_putstr_fd("ra\n", 1);
				else
					ft_putstr_fd("rb\n", 1);
				pos--;
			}
		}
	}
}
