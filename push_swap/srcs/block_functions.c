/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:50:10 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/24 18:00:15 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_block_count_b(t_main *arr)
{
	int i;

	i = 1;
	while (i != arr->y)
	{
		arr->block_count_b[i - 1] = arr->block_count_b[i];
		i++;
	}
	arr->block_count_b[i] = 0;
}

void	move_block_count_a(t_main *arr)
{
	int i;

	i = 1;
	while (i != arr->z)
	{
		arr->block_count_a[i - 1] = arr->block_count_a[i];
		i++;
	}
	arr->block_count_a[i] = 0;
}

void	swipe_block_count_b(t_main *arr)
{
	int i;
	int tmp;

	i = arr->y;
	tmp = arr->block_count_b[arr->y - 1];
	while (i != -1)
	{
		arr->block_count_b[i + 1] = arr->block_count_b[i];
		i--;
	}
	arr->block_count_b[0] = tmp;
	i = 0;
	while (i < arr->y)
		i++;
	while (i < arr->y + 1)
		arr->block_count_b[i++] = 0;
}

void	swipe_block_count_a(t_main *arr)
{
	int i;
	int tmp;

	i = arr->block_count_a[arr->z - 1];
	tmp = arr->block_count_a[arr->z - 1];
	while (i != -1)
	{
		arr->block_count_a[i + 1] = arr->block_count_a[i];
		i--;
	}
	arr->block_count_a[0] = tmp;
	i = 0;
	while (i < arr->z)
		i++;
	while (i < arr->z + 1)
		arr->block_count_a[i++] = 0;
}
