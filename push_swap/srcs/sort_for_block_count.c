/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_block_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:55:23 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/25 16:32:54 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_for_block_count(t_main *arr)
{
	if (arr->block_count_a[0] == 3 && !(is_sorted_for_block_a(arr)))
		sort_for_block_count1(arr);
	if (arr->block_count_a[0] == 2 && !(is_sorted_for_block_a(arr)))
		ft_sa(arr);
	if (arr->block_count_b[0] == 3 && !(is_sorted_for_block_b(arr)))
		sort_for_block_count2(arr);
	if (arr->block_count_b[0] == 2 && !(is_sorted_for_block_b(arr)))
		ft_sb(arr);
}

void	sort_for_block_count1(t_main *arr)
{
	int i;

	i = 0;
	if (arr->stack_a[i] < arr->stack_a[i + 1] && arr->stack_a[i] <
		arr->stack_a[i + 2] && arr->stack_a[i + 1] > arr->stack_a[i + 2])
		sort1(arr);
	if (arr->stack_a[i] > arr->stack_a[i + 1] && arr->stack_a[i] >
		arr->stack_a[i + 2] && arr->stack_a[i + 1] > arr->stack_a[i + 2])
		sort2(arr);
	if (arr->stack_a[i] > arr->stack_a[i + 1] && arr->stack_a[i] >
		arr->stack_a[i + 2] && arr->stack_a[i + 1] < arr->stack_a[i + 2])
		sort3(arr);
	if (arr->stack_a[i] > arr->stack_a[i + 1] && arr->stack_a[i] <
		arr->stack_a[i + 2] && arr->stack_a[i + 1] < arr->stack_a[i + 2])
		ft_sa(arr);
	if (arr->stack_a[i] < arr->stack_a[i + 1] && arr->stack_a[i] >
		arr->stack_a[i + 2] && arr->stack_a[i + 1] > arr->stack_a[i + 2])
		sort4(arr);
}

void	sort_for_block_count2(t_main *arr)
{
	int i;

	i = 0;
	if (arr->stack_b[i] > arr->stack_b[i + 1] && arr->stack_b[i] >
		arr->stack_b[i + 2] && arr->stack_b[i + 1] < arr->stack_b[i + 2])
		sort5(arr);
	if (arr->stack_b[i] < arr->stack_b[i + 1] && arr->stack_b[i] <
		arr->stack_b[i + 2] && arr->stack_b[i + 1] < arr->stack_b[i + 2])
		sort6(arr);
	if (arr->stack_b[i] < arr->stack_b[i + 1] && arr->stack_b[i] <
		arr->stack_b[i + 2] && arr->stack_b[i + 1] > arr->stack_b[i + 2])
		sort7(arr);
	if (arr->stack_b[i] < arr->stack_b[i + 1] && arr->stack_b[i] >
		arr->stack_b[i + 2] && arr->stack_b[i + 1] > arr->stack_b[i + 2])
		ft_sb(arr);
	if (arr->stack_b[i] > arr->stack_b[i + 1] && arr->stack_b[i] <
		arr->stack_b[i + 2] && arr->stack_b[i + 1] < arr->stack_b[i + 2])
		sort8(arr);
}
