/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:47:00 by mrolfe            #+#    #+#             */
/*   Updated: 2018/12/10 17:47:02 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	res = NULL;
	if (s && f)
	{
		res = ft_strnew(ft_strlen(s));
		if (res)
		{
			i = 0;
			while (s[i])
			{
				res[i] = f(i, s[i]);
				i++;
			}
		}
	}
	return (res);
}
