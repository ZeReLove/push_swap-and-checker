/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:07:03 by mrolfe            #+#    #+#             */
/*   Updated: 2018/12/17 16:07:05 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *res;

	res = ft_memalloc(sizeof(t_list));
	if (res)
	{
		if (content)
		{
			res->content = ft_memalloc(content_size);
			if (content_size)
			{
				ft_memcpy(res->content, content, content_size);
				res->content_size = content_size;
			}
			else
				res->content_size = 0;
		}
		else
		{
			res->content = NULL;
			res->content_size = 0;
		}
		res->next = NULL;
	}
	return (res);
}
