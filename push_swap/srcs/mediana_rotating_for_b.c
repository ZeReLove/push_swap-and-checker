/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediana_rotating_for_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:53:54 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/24 17:54:20 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mediana_rotating_for_b(t_main *arr)
{
	int n;

	arr->count_for_rb = 0;
	arr->block_count_for_a1 = 0;
	arr->block_count_for_b1 = arr->block_count_b[0];
	n = arr->block_count_b[0];
	if (arr->block_count_b[0] == 0)
		n = arr->num_b;
	mediana_finding_for_b(arr);
	mediana_rotating_for_b1(arr, n);
	mediana_rotating_for_b2(arr);
}

void	mediana_rotating_for_b1(t_main *arr, int n)
{
	int j;

	j = 0;
	arr->block_count_for_a1 = 0;
	while (j < n)
	{
		if (arr->stack_b[0] <= arr->mediana)
		{
			ft_rb(arr);
			j++;
			arr->count_for_rb++;
		}
		else
		{
			ft_pa(arr);
			arr->block_count_for_a1++;
			if (arr->block_count_b[0])
				arr->block_count_for_b1--;
			arr->block_count_for_b1--;
			if (arr->block_count_b[0])
				arr->block_count_b[0]--;
			j++;
		}
	}
}

void	mediana_rotating_for_b2(t_main *arr)
{
	int i;

	if (arr->block_count_a[arr->z] != 0)
		arr->block_count_a[arr->z] += arr->block_count_for_a1;
	if (arr->block_count_for_a1 > 1)
	{
		if (arr->block_count_a[arr->z] != 0)
			arr->z++;
		arr->block_count_a[arr->z] = arr->block_count_for_a1;
	}
	i = 0;
	while (i++ < arr->count_for_rb)
		ft_rrb(arr);
}
