/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:10:56 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/24 18:43:09 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_algorithm(t_main *arr)
{
	arr->z = 0;
	arr->y = 0;
	if (!(is_sorted_for_a(arr)))
	{
		while (arr->num_a > 3)
		{
			mediana_rotating_for_a(arr);
			arr->y++;
			if (arr->y > 1)
				swipe_block_count_b(arr);
		}
		while (arr->num_b != 0)
			algorithm(arr);
		if (arr->num_a == 3)
			sorting_three(arr);
	}
}

void	algorithm(t_main *arr)
{
	if (arr->num_a <= 3 || arr->num_b <= 3)
		sorting_three(arr);
	if (arr->block_count_a[0] <= 3 || arr->block_count_b[0] <= 3)
		sort_for_block_count(arr);
	if (arr->block_count_b[0] > 3 && arr->block_count_a[0] > 3)
	{
		while (arr->block_count_a[0] > 3)
			case_one(arr);
	}
	if (arr->block_count_a[0] > 3 && !(is_sorted_for_block_a(arr)) &&
		arr->num_a > 3)
		case_one(arr);
	if (arr->block_count_b[0] > 3)
		case_two(arr);
	if (arr->block_count_a[0] <= 3 || arr->block_count_b[0] <= 3)
		sort_for_block_count(arr);
	if ((is_sorted_for_block_b(arr) || (is_sorted_for_b(arr))) &&
		is_sorted_for_a(arr))
		case_three(arr);
}

void	case_one(t_main *arr)
{
	mediana_rotating_for_a(arr);
	if (arr->block_count_a[0] == 0 && arr->z > 1)
		move_block_count_a(arr);
	arr->y++;
	if (arr->y > 1)
		swipe_block_count_b(arr);
}

void	case_two(t_main *arr)
{
	mediana_rotating_for_b(arr);
	if (arr->block_count_b[0] == 0 && arr->y > 1)
		move_block_count_b(arr);
	arr->z++;
	if (arr->z > 1)
		swipe_block_count_a(arr);
}

void	case_three(t_main *arr)
{
	int i;
	int j;

	i = 0;
	if (arr->num_b <= 3)
		j = arr->num_b;
	else
		j = arr->block_count_b[0];
	while (i++ < j)
	{
		ft_pa(arr);
		arr->block_count_b[0]--;
	}
	if (arr->block_count_b[0] == 0 && arr->y > 1)
		move_block_count_b(arr);
}
