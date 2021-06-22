/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:50:07 by abiari            #+#    #+#             */
/*   Updated: 2021/06/22 10:12:43 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dups(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;

	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (j->num == i->num)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	check_digit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			if ((arg[i] != '-' || (arg[i] == '-' && i != 0)
					|| (arg[i] == '-' && i == 0 && arg[i + 1] == '\0'))
				&& (arg[i] != '+' || (arg[i] == '+' && i != 0)
					|| (arg[i] == '+' && i == 0 && arg[i + 1] == '\0')))
				return (0);
		i++;
	}
	return (1);
}

int	check_arg(char *arg)
{
	int		tmp;
	char	*num;

	if (!check_digit(arg))
	{
		ft_putstr("Error\n");
		return (0);
	}
	tmp = ft_atoi(arg);
	num = ft_itoa(tmp);
	if (arg[0] == '+')
		arg++;
	if (ft_strcmp(arg, num))
	{
		ft_putstr_fd("Error", 1);
		free(num);
		return (0);
	}
	free(num);
	return (1);
}

void	sort(int argc, t_stack **a)
{
	if (argc == 3)
	{
		if ((*a)->num > (*a)->next->num)
		{
			swap(a);
			ft_putstr_fd("sa\n", 1);
		}
	}
	else if (argc == 4)
		sort_three(a);
	else if (argc == 5)
		sort_four(a);
	else if (argc == 6)
		sort_five(a);
	else
		sort_more(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	if (argc < 2)
		return (0);
	i = 0;
	while (++i < argc)
	{
		if (!check_arg(argv[i]))
			return (255);
		stack_addback(&a, ft_atoi(argv[i]));
	}
	if (check_dups(a))
	{
		printf("Error\n");
		return (255);
	}
	if (is_sorted(&a))
		return (0);
	sort(argc, &a);
	clear_stack(&a);
	return (0);
}
