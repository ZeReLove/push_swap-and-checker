/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:10:56 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/22 16:12:17 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void main_algorithm(t_main *arr)
{
    int i;
    int j;
    int l;
    int m;
    int z;
    int y;

    l = 0;
    m = 0;
    z = 0;
    y = 0;
    arr->index = 1;
    if (!(is_sorted_for_a(arr)))
    {
        while (arr->num_a > 3)
        {
            mediana_rotating_for_a(arr, m, &y);
            y++;
            if (y > 1)
                swipe_block_count_b(arr, y);

        }
        l = 0;
        while (arr->num_b != 0)
        {
            if (arr->num_a <= 3 || arr->num_b <= 3)
                sorting_three(arr);
            if (arr->block_count_a[m] <= 3 || arr->block_count_b[l] <= 3)
                sort_for_block_count(arr, l, m);
            if (arr->block_count_b[l] > 3 && arr->block_count_a[m] > 3)
            {
                while (arr->block_count_a[m] > 3)
                {
                    mediana_rotating_for_a(arr, m, &y);
                    if (arr->block_count_a[m] == 0 && z > 1)
                        move_block_count_a(arr, z);
                    y++;
                    if (y > 1)
                        swipe_block_count_b(arr, y);
                }
            }
            if (arr->block_count_a[m] > 3 && !(is_sorted_for_block_a(arr, m)) && arr->num_a > 3)
            {
                mediana_rotating_for_a(arr, m, &y);
                if (arr->block_count_a[m] == 0 && z > 1)
                    move_block_count_a(arr, z);
                y++;
                if (y > 1)
                    swipe_block_count_b(arr, y);
            }
            if (arr->block_count_b[l] > 3)
            {
                mediana_rotating_for_b(arr, l, &z);
                if (arr->block_count_b[l] == 0 && y > 1)
                    move_block_count_b(arr, y);
                z++;
                if (z > 1)
                    swipe_block_count_a(arr, z);
            }
            if (arr->block_count_a[m] <= 3 || arr->block_count_b[l] <= 3)
                sort_for_block_count(arr, l, m);
            if (is_sorted_for_block_b(arr, l) || (is_sorted_for_b(arr))) 
            {
                i = 0;
                if (arr->num_b <= 3)
                    j = arr->num_b;
                else
                    j = arr->block_count_b[l];
                while (i++ < j) {
                    ft_pa(arr);
                    arr->block_count_b[l]--;
                }
                if (arr->block_count_b[l] == 0 && y > 1)
                    move_block_count_b(arr, y);
            }
        }
        if (arr->num_a == 3)
            sorting_three(arr);
    }
}

void move_block_count_b(t_main *arr, int y)
{
    int i;

    i = 1;
    while (i != y)
    {
        arr->block_count_b[i - 1] = arr->block_count_b[i];
        i++;
    }
    arr->block_count_b[i] = 0;
}

void move_block_count_a(t_main *arr, int z)
{
    int i;

    i = 1;
    while (i != z)
    {
        arr->block_count_a[i - 1] = arr->block_count_a[i];
        i++;
    }
    arr->block_count_a[i] = 0;
}


void swipe_block_count_b(t_main *arr, int y)
{
    int i;
    int tmp;

    i =  y;
    tmp = arr->block_count_b[y - 1];
    while (i != -1)
    {
        arr->block_count_b[i + 1] = arr->block_count_b[i];
        i--;
    }
    arr->block_count_b[0] = tmp;
    i = 0;
    while (i < y)
        i++;
    while (i < y + 1)
        arr->block_count_b[i++] = 0;
}

void swipe_block_count_a(t_main *arr, int z)
{
    int i;
    int tmp;

    i = arr->block_count_a[z - 1];
    tmp = arr->block_count_a[z - 1];
    while (i != -1)
    {
        arr->block_count_a[i + 1] = arr->block_count_a[i];
        i--;
    }
    arr->block_count_a[0] = tmp;
    i = 0;
    while (i < z)
        i++;
    while (i < z + 1)
        arr->block_count_a[i++] = 0;
}


void sorting_three(t_main *arr)
{
    int i;

    i = 0;
    if (arr->num_a <= 3 && arr->num_a > 1)
    {
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
    i = 0;
    if (arr->num_b <= 3 && arr->num_b > 1)
    {
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
}


void sort_for_block_count(t_main *arr, int l, int m)
{
    int i;

    i = 0;
    if (arr->block_count_a[m] == 3 && !(is_sorted_for_block_a(arr, m)))
    {
        if (arr->stack_a[i] < arr->stack_a[i + 1] && arr->stack_a[i] < arr->stack_a[i + 2] && arr->stack_a[i + 1] > arr->stack_a[i + 2])
        {
            ft_pb(arr);
            ft_sa(arr);
            ft_pa(arr);
        }
        if (arr->stack_a[i] > arr->stack_a[i + 1] && arr->stack_a[i] > arr->stack_a[i + 2] && arr->stack_a[i + 1] > arr->stack_a[i + 2])
        {
            ft_pb(arr);
            ft_pb(arr);
            ft_ra(arr);
            ft_sb(arr);
            ft_pa(arr);
            ft_pa(arr);
            ft_rra(arr);
        }
        if (arr->stack_a[i] > arr->stack_a[i + 1] && arr->stack_a[i] > arr->stack_a[i + 2] && arr->stack_a[i + 1] < arr->stack_a[i + 2])
        {
            ft_sa(arr);
            ft_ra(arr);
            ft_sa(arr);
            ft_rra(arr);
        }
        if (arr->stack_a[i] > arr->stack_a[i + 1] && arr->stack_a[i] < arr->stack_a[i + 2] && arr->stack_a[i + 1] < arr->stack_a[i + 2])
            ft_sa(arr);
        if (arr->stack_a[i] < arr->stack_a[i + 1] && arr->stack_a[i] > arr->stack_a[i + 2] && arr->stack_a[i + 1] > arr->stack_a[i + 2])
        {
            ft_pb(arr);
            ft_sa(arr);
            ft_ra(arr);
            ft_pa(arr);
            ft_rra(arr);
        }
    }
    if (arr->block_count_a[m] == 2 && !(is_sorted_for_block_a(arr, m)))
        ft_sa(arr);
    i = 0;
    if (arr->block_count_b[l] == 3 && !(is_sorted_for_block_b(arr, l)))
    {
        if (arr->stack_b[i] > arr->stack_b[i + 1] && arr->stack_b[i] > arr->stack_b[i + 2] && arr->stack_b[i + 1] < arr->stack_b[i + 2])
        {
            ft_pa(arr);
            ft_sb(arr);
            ft_pb(arr);
        }
        if (arr->stack_b[i] < arr->stack_b[i + 1] && arr->stack_b[i] < arr->stack_b[i + 2] && arr->stack_b[i + 1] < arr->stack_b[i + 2])
        {
            ft_pa(arr);
            ft_sb(arr);
            ft_pa(arr);
            ft_sa(arr);
            ft_pb(arr);
            ft_sb(arr);
            ft_pb(arr);
        }
        if (arr->stack_b[i] < arr->stack_b[i + 1] && arr->stack_b[i] < arr->stack_b[i + 2] && arr->stack_b[i + 1] > arr->stack_b[i + 2])
        {
            ft_sb(arr);
            ft_rb(arr);
            ft_sb(arr);
            ft_rrb(arr);
        }
        if (arr->stack_b[i] < arr->stack_b[i + 1] && arr->stack_b[i] > arr->stack_b[i + 2] && arr->stack_b[i + 1] > arr->stack_b[i + 2])
            ft_sb(arr);
        if (arr->stack_b[i] > arr->stack_b[i + 1] && arr->stack_b[i] < arr->stack_b[i + 2] && arr->stack_b[i + 1] < arr->stack_b[i + 2])
        {
            ft_pa(arr);
            ft_sb(arr);
            ft_pb(arr);
            ft_sb(arr);
        }
    }
    if (arr->block_count_b[l] == 2 && !(is_sorted_for_block_b(arr, l)))
        ft_sb(arr);

}

int is_sorted_for_block_a(t_main *arr, int m)
{
    int i;

    i = 0;
    while (i < arr->block_count_a[m] - 1)
    {
        if (arr->stack_a[i] < arr->stack_a[i + 1])
            i++;
        else
            return (0);
    }
    if (i == arr->block_count_a[m] - 1)
        return (1);
    else
        return (0);
}

int is_sorted_for_block_b(t_main *arr, int l)
{
    int i;

    i = 0;
    while (i < arr->block_count_b[l] - 1)
    {
        if (arr->stack_b[i] > arr->stack_b[i + 1])
            i++;
        else
            return (0);
    }
    if (i == arr->block_count_b[l] - 1)
        return (1);
    else
        return (0);
}

int is_sorted_for_a(t_main *arr)
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

int is_sorted_for_b(t_main *arr)
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



void mediana_rotating_for_a(t_main *arr, int m, int *y)
{
    int i;
    int j;
    int n;
    int block_count_for_b;
    int block_count_for_a;
    int count_for_ra;

    i = 0;
    count_for_ra = 0;
    block_count_for_b = 0;
    block_count_for_a = arr->block_count_a[m];
    n = arr->block_count_a[m];
    if (arr->block_count_a[m] == 0)
        n = arr->num_a;
    mediana_finding_for_a(arr, m);
    j = i;
    while (j < n)
    {
        if (arr->stack_a[i] >= arr->mediana)
        {
            ft_ra(arr);
            j++;
            count_for_ra++;
        }
        else
        {
            
            ft_pb(arr);
            block_count_for_b++;
            if (arr->block_count_a[m])
                block_count_for_a--;
            block_count_for_a--;
            if (arr->block_count_a[m])
                arr->block_count_a[m]--;
            j++;
        }
    }
    if (arr->block_count_b[*y] != 0)
        arr->block_count_b[*y] += block_count_for_b;
    else
    if (block_count_for_b > 1)
    {
        if (arr->block_count_b[*y] != 0)
            (*y)++;
        arr->block_count_b[*y] = block_count_for_b;
    }
    i = 0;
    if (arr->num_b > 3)
    {
        while (i++ < count_for_ra)
            ft_rra(arr);
    }
}


void mediana_rotating_for_b(t_main *arr, int l, int *z)
{
    int i;
    int j;
    int n;
    int block_count_for_a;
    int block_count_for_b;
    int count_for_rb;

    i = 0;
    count_for_rb = 0;
    block_count_for_a = 0;
    block_count_for_b = arr->block_count_b[l];
    n = arr->block_count_b[l];
    if (arr->block_count_b[l] == 0)
        n = arr->num_b;
    mediana_finding_for_b(arr, l);
    j = i;
    while (j < n)
    {
        if (arr->stack_b[i] <= arr->mediana)
        {
            ft_rb(arr);
            j++;
            count_for_rb++;
        }
        else
        {
            
            ft_pa(arr);
            block_count_for_a++;
            if (arr->block_count_b[l])
                block_count_for_b--;
            block_count_for_b--;
            if (arr->block_count_b[l])
                arr->block_count_b[l]--;
            j++;
        }
    }
    if (arr->block_count_a[*z] != 0)
        arr->block_count_a[*z] += block_count_for_a;
    else
    if (block_count_for_a > 1)
    {
        if (arr->block_count_a[*z] != 0)
            (*z)++;
        arr->block_count_a[*z] = block_count_for_a;
    }
    i = 0;
        while (i++ < count_for_rb)
            ft_rrb(arr);
}

