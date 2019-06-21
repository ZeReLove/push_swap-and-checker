/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:17:41 by mrolfe            #+#    #+#             */
/*   Updated: 2018/12/04 17:17:42 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	i = 0;
	res = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			res = (char*)(s + i);
		i++;
	}
	if (s[i] == (char)c)
		res = (char*)(s + i);
	return (res);
}
