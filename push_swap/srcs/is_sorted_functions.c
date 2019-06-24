/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:51:42 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/24 17:54:26 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted_for_block_a(t_main *arr)
{
	int i;

	i = 0;
	while (i < arr->block_count_a[0] - 1)
	{
		if (arr->stack_a[i] < arr->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	if (i == arr->block_count_a[0] - 1)
		return (1);
	else
		return (0);
}

int		is_sorted_for_block_b(t_main *arr)
{
	int i;

	i = 0;
	while (i < arr->block_count_b[0] - 1)
	{
		if (arr->stack_b[i] > arr->stack_b[i + 1])
			i++;
		else
			return (0);
	}
	if (i == arr->block_count_b[0] - 1)
		return (1);
	else
		return (0);
}

int		is_sorted_for_a(t_main *arr)
{
	int i;

	i = 0;
	while (i < arr->num_a - 1)
	{
		if (arr->stack_a[i] < arr->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	if (i == arr->num_a - 1)
		return (1);
	else
		return (0);
}

int		is_sorted_for_b(t_main *arr)
{
	int i;

	i = 0;
	while (i < arr->num_b - 1)
	{
		if (arr->stack_b[i] > arr->stack_b[i + 1])
			i++;
		else
			return (0);
	}
	if (i == arr->num_b - 1)
		return (1);
	else
		return (0);
}
