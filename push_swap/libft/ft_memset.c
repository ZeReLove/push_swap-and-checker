/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:56:49 by mrolfe            #+#    #+#             */
/*   Updated: 2018/12/05 13:56:51 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_mod;
	size_t			i;

	b_mod = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		b_mod[i] = c;
		i++;
	}
	return (b);
}
