/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:22:27 by mrolfe            #+#    #+#             */
/*   Updated: 2018/12/05 13:22:29 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t j;
	size_t len_dst;
	size_t len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	j = 0;
	if (size < len_dst)
	{
		return (size + len_src);
	}
	if (size > 0)
	{
		while (src[j] != '\0' && len_dst + j < size - 1)
		{
			dst[len_dst + j] = src[j];
			j++;
		}
	}
	dst[len_dst + j] = '\0';
	return (len_src + len_dst);
}
