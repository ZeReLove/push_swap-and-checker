/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:51:43 by mrolfe            #+#    #+#             */
/*   Updated: 2018/12/10 17:51:45 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_zero_itoa(void)
{
	char *res;

	res = ft_strnew(1);
	if (res)
		res[0] = '0';
	return (res);
}

char			*ft_itoa(int n)
{
	unsigned int	unsig_n;
	int				discharges;
	char			*res;

	if (n == 0)
		return (ft_zero_itoa());
	discharges = (n < 0);
	unsig_n = ABS(n);
	while (n)
	{
		n /= 10;
		discharges++;
	}
	res = ft_strnew(discharges);
	if (res)
	{
		while (unsig_n)
		{
			res[--discharges] = (unsig_n % 10) + '0';
			unsig_n /= 10;
		}
		if (discharges)
			res[--discharges] = '-';
	}
	return (res);
}
