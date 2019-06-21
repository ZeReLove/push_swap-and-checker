/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:49:18 by mrolfe            #+#    #+#             */
/*   Updated: 2018/12/10 17:49:20 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;

	res = NULL;
	if (s && (start + len) <= ft_strlen(s))
	{
		res = ft_strnew(len);
		if (res)
		{
			i = 0;
			while (i < len)
			{
				res[i] = s[start + i];
				i++;
			}
		}
	}
	return (res);
}
