/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:03:01 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/25 16:47:40 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_main	arr;
	char	**str;

	ft_bzero(&arr, sizeof(arr));
	if (argc > 1)
	{
		arr.index = 1;
		fill_struct(&arr, &argc, argv);
		str = arr.res_str;
		if (check_all(&arr, argc, argv, str))
		{
			main_algorithm(&arr);
			free_for_main(&arr);
		}
	}
	return (0);
}

void	free_for_main(t_main *arr)
{
	int		i;
	char	**str;

	i = -1;
	str = arr->res_str;
	if (arr->ret)
	{
		while (str[++i])
			free((char *)str[i]);
		free((char **)str);
	}
	free(arr->stack_a);
	free(arr->stack_b);
	free(arr->block_a);
	free(arr->block_b);
	free(arr->block_count_a);
	free(arr->block_count_b);
}
