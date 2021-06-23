/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:15:38 by abiari            #+#    #+#             */
/*   Updated: 2021/06/23 16:23:27 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	make_head(a, find_min(a), 0);
	push_b(a, &b);
	ft_putstr("pb\n");
	make_head(a, find_min(a), 0);
	push_b(a, &b);
	ft_putstr("pb\n");
	sort_three(a);
	if (b->num < b->next->num)
	{
		swap(&b);
		ft_putstr("sb");
	}
	push_a(a, &b);
	ft_putstr("pa\n");
	push_a(a, &b);
	ft_putstr("pa\n");
	clear_stack(&b);
}
