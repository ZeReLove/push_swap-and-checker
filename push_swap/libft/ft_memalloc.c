/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:40:13 by mrolfe            #+#    #+#             */
/*   Updated: 2018/12/10 17:40:17 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned int	i;
	char			*res;

	res = malloc(size);
	if (res)
	{
		i = 0;
		while (i < size)
		{
			res[i] = 0;
			i++;
		}
		return ((void*)res);
	}
	return (NULL);
}
