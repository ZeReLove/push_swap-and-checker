/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:19:03 by mrolfe            #+#    #+#             */
/*   Updated: 2018/12/05 15:19:06 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_mod;
	unsigned char	ch;
	unsigned int	i;

	s_mod = (unsigned char*)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s_mod[i] == ch)
		{
			return (&s_mod[i]);
		}
		i++;
	}
	return (NULL);
}
