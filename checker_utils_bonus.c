/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:21:22 by abiari            #+#    #+#             */
/*   Updated: 2021/06/19 18:22:02 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rrr(t_stack **a, t_stack **b)
{
	r_rotate(a);
	r_rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}

int	check_valid_op(char *line)
{
	return (ft_strcmp(line, "sa") && ft_strcmp(line, "sb")
		&& ft_strcmp(line, "pa") && ft_strcmp(line, "pb")
		&& ft_strcmp(line, "ra") && ft_strcmp(line, "rb")
		&& ft_strcmp(line, "rrb") && ft_strcmp(line, "rra")
		&& ft_strcmp(line, "rr") && ft_strcmp(line, "rrr")
		&& ft_strcmp(line, "ss"));
}
