/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:32:02 by mrolfe            #+#    #+#             */
/*   Updated: 2018/12/04 15:32:05 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int d;

	while (*s1 || *s2)
	{
		d = (unsigned char)*s1 - (unsigned char)*s2;
		if (d)
			return (d);
		s1++;
		s2++;
	}
	return (0);
}
