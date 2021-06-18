/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:15:44 by abiari            #+#    #+#             */
/*   Updated: 2021/06/18 17:18:27 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	do_operation(char *op, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(op, "pb"))
		push(b, pop(a));
	else if (!ft_strcmp(op, "pa"))
		push(a, pop(b));
	else if (!ft_strcmp(op, "sa"))
		swap(a);
	else if (!ft_strcmp(op, "sb"))
		swap(b);
	else if (!ft_strcmp(op, "ra"))
		rotate(a);
	else if (!ft_strcmp(op, "rb"))
		rotate(b);
	else if (!ft_strcmp(op, "rra"))
		r_rotate(a);
	else if (!ft_strcmp(op, "rrb"))
		r_rotate(b);
	else if (!ft_strcmp(op, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strcmp(op, "rrr"))
	{
		r_rotate(a);
		r_rotate(b);
	}
	else if (!ft_strcmp(op, "ss"))
	{
		swap(a);
		swap(b);
	}
}

int	ops_checker(t_stack **a)
{
	char	*line;
	t_stack	*b;

	b = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, "sa") && ft_strcmp(line, "sb")
			&& ft_strcmp(line, "pa") && ft_strcmp(line, "pb")
			&& ft_strcmp(line, "ra") && ft_strcmp(line, "rb")
			&& ft_strcmp(line, "rrb") && ft_strcmp(line, "rra")
			&& ft_strcmp(line, "rr") && ft_strcmp(line, "rrr")
			&& ft_strcmp(line, "ss"))
		{
			free(line);
			line = NULL;
			ft_putstr_fd("error\n", 1);
			return (0);
		}
		else
			do_operation(line, a, &b);
		free(line);
		line = NULL;
	}
	free(line);
	if (b != NULL)
	{
		clear_stack(&b);
		return (2);
	}
	return (1);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		tmp;
	int		ret;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (255);
	}
	i = 1;
	while (i < argc)
	{
		if (!check_digit(argv[i]))
		{
			printf("Error\n");
			return (255);
		}
		if (strlen(argv[i]) > 10)
		{
			printf("Error\n");
			return (255);
		}
		else if (strlen(argv[i]) == 10)
		{
			tmp = ft_atoi(argv[i] + 1);
			if (tmp > 147483647)
			{
				printf("Error\n");
				return (255);
			}
		}
		stack_addback(&a, ft_atoi(argv[i]));
		i++;
	}
	if (check_dups(a))
	{
		printf("Error\n");
		return (255);
	}
	ret = ops_checker(&a);
	if (!ret)
	{
		ft_putstr_fd("Error\n", 1);
		return (255);
	}
	if (!is_sorted(&a) || ret == 2)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	clear_stack(&a);
	while (1);
	return (0);
}
