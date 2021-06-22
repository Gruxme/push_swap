/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:22:24 by abiari            #+#    #+#             */
/*   Updated: 2021/06/22 10:25:54 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	if (!(*b))
		return ;
	else
		push(a, pop(b));
}

void	push_b(t_stack **a, t_stack **b)
{
	if (!(*a))
		return ;
	else
		push(b, pop(a));
}
