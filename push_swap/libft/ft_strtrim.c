/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:50:27 by mrolfe            #+#    #+#             */
/*   Updated: 2018/12/10 17:50:29 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_find(const char *s, int *start, int *end)
{
	int i;

	*start = -1;
	*end = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		{
			if (*start == -1)
				*start = i;
			else
				*end = i + 1;
		}
		i++;
	}
}

char			*ft_strtrim(char const *s)
{
	char	*res;
	int		start;
	int		end;

	res = NULL;
	if (s)
	{
		ft_find(s, &start, &end);
		res = ft_strnew(end - start);
		if (res)
			ft_strncpy(res, s + start, end - start);
	}
	return (res);
}
