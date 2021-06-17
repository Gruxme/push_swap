/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:20:14 by abiari            #+#    #+#             */
/*   Updated: 2021/06/17 20:22:12 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *haystack, char *needle)
{
	int	i;
	int	j;

	i = 0;
	if (haystack[i] == '\0')
		return (needle);
	while (needle[i] != '\0')
	{
		j = 0;
		while (needle[i + j] != '\0' && haystack[j] == needle[i + j])
		{
			if (haystack[j + 1] == '\0')
				return (&needle[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
