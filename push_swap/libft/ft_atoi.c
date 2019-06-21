/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:38:46 by mrolfe            #+#    #+#             */
/*   Updated: 2018/12/06 16:38:47 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_invisible_char(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\r' || c == '\f');
}

int			ft_atoi(const char *str)
{
	char		negative;
	long long	result;
	int			i;

	i = 0;
	while (ft_is_invisible_char(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		negative = 1 - (2 * (str[i] == '-'));
		i++;
	}
	else
		negative = 1;
	result = 0;
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		if (result < 0)
			return (-((negative + 1) / 2));
		i++;
	}
	return ((int)result * negative);
}
