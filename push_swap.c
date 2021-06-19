/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:50:07 by abiari            #+#    #+#             */
/*   Updated: 2021/06/19 19:08:11 by abiari           ###   ########.fr       */
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
			if (arg[i] != '-' || (arg[i] == '-' && i != 0)
				|| ((arg[i] == '-' && i == 0
						&& arg[i + 1] == '\0')))
				return (0);
		i++;
	}
	return (1);
}

int	check_arg(char *arg)
{
	int	tmp;

	if (!check_digit(arg))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (strlen(arg) > 10)
	{
		printf("Error\n");
		return (0);
	}
	else if (strlen(arg) == 10)
	{
		tmp = ft_atoi(arg + 1);
		if (tmp > 147483647)
		{
			printf("Error\n");
			return (0);
		}
	}
	return (1);
}

void	sort(int argc, t_stack **a)
{
	if (argc == 4)
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
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (!check_arg(argv[i]))
			return (255);
		stack_addback(&a, ft_atoi(argv[i]));
		i++;
	}
	if (check_dups(a))
	{
		printf("dups found\n");
		return (2);
	}
	sort(argc, &a);
	clear_stack(&a);
	return (0);
}
