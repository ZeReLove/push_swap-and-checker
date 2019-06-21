/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:30:53 by mrolfe            #+#    #+#             */
/*   Updated: 2018/12/05 14:30:57 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	unsigned char	ch;
	size_t			i;

	dest = dst;
	source = (unsigned char *)src;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		if (source[i] == ch)
		{
			return (&dst[i] + 1);
		}
		i++;
	}
	return (NULL);
}
