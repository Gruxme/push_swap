/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:08:10 by abiari            #+#    #+#             */
/*   Updated: 2021/06/19 19:07:03 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_under_range_to_b(int *min, int range, t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp_head;

	tmp = NULL;
	while (*a)
	{
		tmp = stack_dup(a);
		tmp_head = tmp;
		*min += range;
		while (tmp)
		{
			if (tmp->num <= *min)
			{
				make_head(a, tmp->num, 0);
				push(b, pop(a));
				ft_putstr("pb\n");
			}
			tmp = tmp->next;
		}
	}
	clear_stack(&tmp_head);
}

void	sort_more(t_stack **a)
{
	t_stack	*b;
	int		min;
	int		range;

	b = NULL;
	min = find_min(a);
	if (stack_len(a) <= 100)
		range = (find_max(a) - min) / 6;
	else
		range = (find_max(a) - min) / 20;
	make_head(a, min, 0);
	push(&b, pop(a));
	ft_putstr("pb\n");
	push_under_range_to_b(&min, range, a, &b);
	while (b)
	{
		make_head(&b, find_max(&b), 1);
		push(a, pop(&b));
		ft_putstr("pa\n");
	}
	clear_stack(&b);
}
