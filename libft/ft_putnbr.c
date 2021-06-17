/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:02:55 by abiari            #+#    #+#             */
/*   Updated: 2021/06/17 20:38:50 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr_fd("-2147483648", 1);
			return ;
		}
		n = -n;
		write(1, "-", 1);
	}
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
	else
	{
		ft_putnbr(n / 10);
		ft_putchar_fd((n % 10) + '0', 1);
	}
}
