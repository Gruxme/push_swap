/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:08:10 by abiari            #+#    #+#             */
/*   Updated: 2021/06/17 14:33:41 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more(t_stack **a)
{
	t_stack	*b;
	t_stack	*tmp;
	int		min;
	int		range;

	tmp = NULL;
	b = NULL;
	min = find_min(a);
	if (stack_len(a) <= 100)
		range = (find_max(a) - min) / 6;
	else
		range = (find_max(a) - min) / 20;
	make_head(a, min, 0);
	push(&b, pop(a));
	ft_putstr("pb\n");
	while (*a)
	{
		tmp = stack_dup(a);
		min += range;
		while (tmp)
		{
			if (tmp->num <= min)
			{
				make_head(a, tmp->num, 0);
				push(&b, pop(a));
				ft_putstr("pb\n");
			}
			tmp = tmp->next;
		}
		clear_stack(&tmp);
	}
	while (b)
	{
		make_head(&b, find_max(&b), 1);
		push(a, pop(&b));
		ft_putstr("pa\n");
	}
}
