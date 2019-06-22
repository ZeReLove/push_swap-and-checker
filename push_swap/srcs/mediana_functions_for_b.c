/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediana_functions_for_b.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:16:45 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/22 16:31:32 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort_for_b(t_main *arr)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 1;
	while (j != arr->n)
	{
		if (arr->array[i] > arr->array[j])
		{
			tmp = arr->array[j];
			arr->array[j] = arr->array[i];
			arr->array[i] = tmp;		
			i++;
			j++;
		}
		else
		{	
			i++;
			j++;
		}
	}
	if (!(is_bubble_sorted_for_b(arr)))
		bubble_sort_for_b(arr);
	else
		return ;
}

void	filling_array_for_b(t_main *arr, int l)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(arr->block_count_b[l]))
		arr->n = arr->num_b;
	else
		arr->n = arr->block_count_b[l];
	if (!(arr->array = malloc(sizeof(int) * (arr->n + 1))))
		return ;
	while (i < arr->n)
	{
		arr->array[i] = arr->stack_b[j];
		i++;
		j++;
	}
}

int		is_bubble_sorted_for_b(t_main *arr)
{
	int i;

	i = 0;
	while (i < arr->n - 1)
	{
		if (arr->array[i] < arr->array[i + 1])
			i++;
		else
			return (0);
	}
	if (i == arr->n - 1)
		return (1);
	else
		return (0);
}

void	mediana_finding_for_b(t_main *arr, int l)
{
	int i;
	int mediana;

	filling_array_for_b(arr, l);
	bubble_sort_for_b(arr);
	i = arr->n / 2;
	mediana = arr->array[i];
	arr->mediana = mediana;
	free(arr->array);
}
