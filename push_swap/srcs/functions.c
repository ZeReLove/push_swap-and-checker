/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:26:19 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/15 16:43:59 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sa(t_main *arr)
{
    int i;
    int j;
    int tmp;
    
    i = arr->stack_a[0];
    j = arr->stack_a[1];
    tmp = i;
    arr->stack_a[0] = j;
    arr->stack_a[1] = tmp;
    printf("sa\n");
}

void ft_sb(t_main *arr)
{
    int i;
    int j;
    int tmp;
    
    i = arr->stack_b[0];
    j = arr->stack_b[1];
    tmp = i;
    arr->stack_b[0] = j;
    arr->stack_b[1] = tmp;
    printf("sb\n");
}

void ft_ss(t_main *arr)
{
    ft_sa(arr);
    ft_sb(arr);
}

void ft_pa(t_main *arr)
{
    int i;
    int tmp;

    i = arr->num_a - 1;
    arr->num_a++;
    tmp = arr->stack_b[0];
     while (i != -1)
    {
        arr->stack_a[i + 1] = arr->stack_a[i];
        i--;
    }
    arr->stack_a[0] = tmp;
    i = 0;
    while (i + 1 < arr->num_b)
    {
        arr->stack_b[i] = arr->stack_b[i + 1];
        i++;
    }
    arr->num_b--;
    printf("pa\n");
}

void ft_pb(t_main *arr)
{
    int i;
    int tmp;

    i = arr->num_b - 1;
    arr->num_b++;
    tmp = arr->stack_a[0];
    while (i != -1)
    {
        arr->stack_b[i + 1] = arr->stack_b[i];
        i--;
    }
    arr->stack_b[0] = tmp;
    i = 0;
    while (i + 1 < arr->num_a)
    {
        arr->stack_a[i] = arr->stack_a[i + 1];
        i++;
    }
    arr->num_a--;
    printf("pb\n");
}

// CHANGED PB, NEDEED TO CHANGE PA  

