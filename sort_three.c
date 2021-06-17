/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:03:31 by abiari            #+#    #+#             */
/*   Updated: 2021/06/12 12:42:51 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	if ((*a)->num > (*a)->next->num)
	{
		if ((*a)->next->num > (*a)->next->next->num)
		{
			swap(a);
			ft_putstr("sa\n");
			r_rotate(a);
			ft_putstr("rra\n");
		}
		else
		{
			if ((*a)->num > (*a)->next->next->num)
			{
				rotate(a);
				ft_putstr("ra\n");
			}
			else
			{
				swap(a);
				ft_putstr("sa\n");
			}
		}
	}
	else
	{
		if ((*a)->num > (*a)->next->next->num)
		{
			r_rotate(a);
			ft_putstr("rra\n");
		}
		else
		{
			if ((*a)->next->num > (*a)->next->next->num)
			{
				swap(a);
				ft_putstr("sa\n");
				rotate(a);
				ft_putstr("ra\n");
			}
		}
	}
}
