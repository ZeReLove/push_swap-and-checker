/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:55:45 by mrolfe            #+#    #+#             */
/*   Updated: 2018/12/04 17:55:46 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				d;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		d = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (d)
			return (d);
		i++;
	}
	return (0);
}
