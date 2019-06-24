/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:58:59 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/24 17:59:13 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_three(t_main *arr)
{
	if (arr->num_a <= 3 && arr->num_a > 1)
		sorting_three_for_a(arr);
	if (arr->num_b <= 3 && arr->num_b > 1)
		sorting_three_for_b(arr);
}

void	sorting_three_for_a(t_main *arr)
{
	int i;

	i = 0;
	while (!(is_sorted_for_a(arr)))
	{
		if (arr->stack_a[i] > arr->stack_a[i + 1])
			ft_sa(arr);
		if (!(is_sorted_for_a(arr)))
			ft_rra(arr);
		else
			return ;
	}
}

void	sorting_three_for_b(t_main *arr)
{
	int i;

	i = 0;
	while (!(is_sorted_for_b(arr)))
	{
		if (arr->stack_b[i] < arr->stack_b[i + 1])
			ft_sb(arr);
		if (!(is_sorted_for_b(arr)))
			ft_rrb(arr);
		else
			return ;
	}
}
