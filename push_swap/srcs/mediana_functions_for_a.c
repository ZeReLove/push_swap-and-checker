/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediana_functions_for_a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:12:36 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/11 18:05:08 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bubble_sort(t_main *arr)
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
    if (!(is_bubble_sorted(arr)))
        bubble_sort(arr);
    else
        return ;
}

void filling_array(t_main *arr, int m)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (!(arr->block_count_a[m]))
        arr->n = arr->num_a;
    else
        arr->n = arr->block_count_a[m];
    if (!(arr->array = malloc(sizeof(int) * (arr->n + 1))))
        return ;
    while(i < arr->n)
    {
        arr->array[i] = arr->stack_a[j];
        i++;
        j++;
    }
}

int is_bubble_sorted(t_main *arr)
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

void mediana_finding_for_a(t_main *arr, int m)
{
    int i;
    int mediana;

    filling_array(arr, m);
    bubble_sort(arr);
    i = arr->n / 2;
    mediana = arr->array[i];
    arr->mediana = mediana;
    free(arr->array);
}


