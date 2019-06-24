/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:57:35 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/24 17:57:59 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort5(t_main *arr)
{
	ft_pa(arr);
	ft_sb(arr);
	ft_pb(arr);
}

void	sort6(t_main *arr)
{
	ft_pa(arr);
	ft_sb(arr);
	ft_pa(arr);
	ft_sa(arr);
	ft_pb(arr);
	ft_sb(arr);
	ft_pb(arr);
}

void	sort7(t_main *arr)
{
	ft_sb(arr);
	ft_rb(arr);
	ft_sb(arr);
	ft_rrb(arr);
}

void	sort8(t_main *arr)
{
	ft_pa(arr);
	ft_sb(arr);
	ft_pb(arr);
	ft_sb(arr);
}
