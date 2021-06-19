/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:15:38 by abiari            #+#    #+#             */
/*   Updated: 2021/06/19 18:32:53 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack **a)
{
	t_stack	*b;

	make_head(a, find_min(a), 0);
	push(&b, pop(a));
	ft_putstr("pb\n");
	make_head(a, find_min(a), 0);
	push(&b, pop(a));
	ft_putstr("pb\n");
	sort_three(a);
	if (b->num < b->next->num)
	{
		swap(&b);
		ft_putstr("sb");
	}
	push(a, pop(&b));
	ft_putstr("pa\n");
	push(a, pop(&b));
	ft_putstr("pa\n");
	clear_stack(&b);
}
