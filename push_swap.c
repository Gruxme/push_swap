/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:50:07 by abiari            #+#    #+#             */
/*   Updated: 2021/06/17 20:42:51 by abiari           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		tmp;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (!check_digit(argv[i]))
		{
			ft_putstr("error: args not digit\n");
			return (3);
		}
		if (strlen(argv[i]) > 10)
		{
			printf("error number overflow\n");
			return (1);
		}
		else if (strlen(argv[i]) == 10)
		{
			tmp = ft_atoi(argv[i] + 1);
			if (tmp > 147483647)
			{
				printf("error number overflow\n");
				return (1);
			}
		}
		stack_addback(&a, ft_atoi(argv[i]));
		i++;
	}
	if (check_dups(a))
	{
		printf("dups found\n");
		return (2);
	}
	// print_stack(a, &ft_putnbr);
	// write(1, "\n", 1);
	sort_more(&a);
	// sort_five(&a);
	// print_stack(a, &ft_putnbr);
	// write(1, "\n", 1);
	// sort_three(&a);
	// print_stack(a, &ft_putnbr);
	// write(1, "\n", 1);
	return (0);
}
