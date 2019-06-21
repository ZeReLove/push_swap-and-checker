/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:46:31 by mrolfe            #+#    #+#             */
/*   Updated: 2018/12/10 17:46:34 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				res[i] = f(s[i]);
				i++;
			}
		}
	}
	return (res);
}
