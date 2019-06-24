/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediana_rotating_for_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:53:16 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/24 18:42:00 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mediana_rotating_for_a(t_main *arr)
{
	int n;

	arr->count_for_ra = 0;
	arr->block_count_for_b1 = 0;
	arr->block_count_for_a1 = arr->block_count_a[0];
	n = arr->block_count_a[0];
	if (arr->block_count_a[0] == 0)
		n = arr->num_a;
	mediana_finding_for_a(arr);
	mediana_rotating_for_a2(arr, n);
	mediana_rotating_for_a1(arr);
}

void	mediana_rotating_for_a1(t_main *arr)
{
	int i;

	if (arr->block_count_b[arr->y] != 0)
		arr->block_count_b[arr->y] += arr->block_count_for_b1;
	if (arr->block_count_for_b1 > 1)
	{
		if (arr->block_count_b[arr->y] != 0)
			arr->y++;
		arr->block_count_b[arr->y] = arr->block_count_for_b1;
	}
	i = 0;
	if (arr->num_b > 3)
		while (i++ < arr->count_for_ra)
			ft_rra(arr);
}

void	mediana_rotating_for_a2(t_main *arr, int n)
{
	int j;

	j = 0;
	arr->block_count_for_b1 = 0;
	while (j < n)
	{
		if (arr->stack_a[0] >= arr->mediana)
		{
			ft_ra(arr);
			j++;
			arr->count_for_ra++;
		}
		else
		{
			ft_pb(arr);
			arr->block_count_for_b1++;
			if (arr->block_count_a[0])
				arr->block_count_for_a1--;
			arr->block_count_for_a1--;
			if (arr->block_count_a[0])
				arr->block_count_a[0]--;
			j++;
		}
	}
}
