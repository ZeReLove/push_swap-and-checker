/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:58:10 by mrolfe            #+#    #+#             */
/*   Updated: 2018/12/10 17:58:12 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int us_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		us_n = -n;
	}
	else
		us_n = n;
	if (us_n / 10)
		ft_putnbr_fd((int)(us_n / 10), fd);
	ft_putchar_fd((us_n % 10) + '0', fd);
}
