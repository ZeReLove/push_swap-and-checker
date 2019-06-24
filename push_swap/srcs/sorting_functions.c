/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:56:46 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/24 18:42:46 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort1(t_main *arr)
{
	ft_pb(arr);
	ft_sa(arr);
	ft_pa(arr);
}

void	sort2(t_main *arr)
{
	ft_pb(arr);
	ft_pb(arr);
	ft_ra(arr);
	ft_sb(arr);
	ft_pa(arr);
	ft_pa(arr);
	ft_rra(arr);
}

void	sort3(t_main *arr)
{
	ft_sa(arr);
	ft_ra(arr);
	ft_sa(arr);
	ft_rra(arr);
}

void	sort4(t_main *arr)
{
	ft_pb(arr);
	ft_sa(arr);
	ft_ra(arr);
	ft_pa(arr);
	ft_rra(arr);
}
