/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:12:51 by abiari            #+#    #+#             */
/*   Updated: 2021/06/17 17:41:44 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_stack **a)
{
	t_stack	*b;

	make_head(a, find_min(a), 0);
	push(&b, pop(a));
	ft_putstr("pb\n");
	sort_three(a);
	push(a, pop(&b));
	ft_putstr("pa\n");
}
