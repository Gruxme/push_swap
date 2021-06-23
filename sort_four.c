/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:12:51 by abiari            #+#    #+#             */
/*   Updated: 2021/06/23 16:22:53 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	make_head(a, find_min(a), 0);
	push_b(a, &b);
	ft_putstr("pb\n");
	sort_three(a);
	push_a(a, &b);
	ft_putstr("pa\n");
	clear_stack(&b);
}
