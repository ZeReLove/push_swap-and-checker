/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:21:47 by mrolfe            #+#    #+#             */
/*   Updated: 2018/12/05 14:21:48 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;
	size_t			j;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	j = 0;
	while (i < n)
	{
		dest[i] = source[j];
		i++;
		j++;
	}
	return (dst);
}
