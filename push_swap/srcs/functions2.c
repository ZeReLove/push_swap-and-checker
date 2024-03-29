/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:29:49 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/25 17:26:22 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_main *arr)
{
	int i;
	int first_el;

	i = 0;
	if (arr->num_a != 0)
	{
		first_el = arr->stack_a[0];
		while (i + 1 < arr->num_a)
		{
			arr->stack_a[i] = arr->stack_a[i + 1];
			i++;
		}
		arr->stack_a[i] = first_el;
	}
	if (arr->index == 1)
		printf("ra\n");
}

void	ft_rb(t_main *arr)
{
	int i;
	int first_el;

	i = 0;
	if (arr->num_b != 0)
	{
		first_el = arr->stack_b[0];
		while (i + 1 < arr->num_b)
		{
			arr->stack_b[i] = arr->stack_b[i + 1];
			i++;
		}
		arr->stack_b[i] = first_el;
	}
	if (arr->index == 1)
		printf("rb\n");
}

void	ft_rr(t_main *arr)
{
	if (arr->num_a != 0 && arr->num_b != 0)
	{
		ft_ra(arr);
		ft_rb(arr);
	}
	if (arr->index == 1)
		printf("rr\n");
}
