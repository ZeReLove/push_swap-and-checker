/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:49:43 by mrolfe            #+#    #+#             */
/*   Updated: 2018/12/10 17:49:45 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	res = NULL;
	if (s1)
		s1_len = ft_strlen(s1);
	else
		s1_len = 0;
	if (s2)
		s2_len = ft_strlen(s2);
	else
		s2_len = 0;
	res = ft_strnew(s1_len + s2_len);
	if (res)
	{
		if (s1_len)
			ft_strcpy(res, s1);
		if (s2_len)
			ft_strcpy(res + s1_len, s2);
	}
	return (res);
}
