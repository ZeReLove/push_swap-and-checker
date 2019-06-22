/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 17:09:22 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/22 16:48:45 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi_push_swap(char *str)
{
    int i;
    int j;
    int sign;
    long long int nbr;

    i = 0;
    j = 0;
    sign = 1;
    nbr = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r' 
            || str[i] == '\n' || str[i] == '\f')
        i++;
    if (str[i] == '-' || str[i] == '+')
        if (str[i++] == '-')
            sign = -1;
    while (str[i] >= '0' && str[i] <= '9')
    {
        nbr = (nbr * 10) + (str[i++] - '0');
        j++;
    }
    if (j > 11 || nbr > 2147483647 || nbr < -2147483648)
        return (0);                                        //!!!!!!!!!!!!
    return (nbr * sign);
}

void fill_struct(t_main *arr, int *argc, char **argv)
{
    if (*argc == 2)
    {
        fill_struct_for_brakets(arr, argc, argv);
        argv = arr->res_str;
        arr->ret = 1;
    }
    else
        fill_struct_without_brakets(arr, *argc, argv);
    arr->num_b = 0;
    arr->num = arr->num_a;
}

void fill_struct_for_brakets(t_main *arr, int *argc, char **argv)
{
    int i;
    int j;
    char **s;
    char **str;

    i = 0;
    j = 0;
    s = ft_strsplit(argv[1], ' ');
    while (s[arr->len])
        arr->len++;
    str = (char **)malloc(sizeof(char *) * (arr->len + 2));
    str[0] = ft_strdup(argv[0]);
    i = 1;
    while (s[i])
    {
        str[i] = ft_strdup(s[i - 1]);
        i++;
    }
    str[arr->len + 1] = NULL;
    *argc = arr->len + 1;
    arr->stack_a = malloc(sizeof(int) * *argc);
    arr->stack_b = malloc(sizeof(int) * *argc);
    arr->block_a = malloc(sizeof(int) * *argc);
    arr->block_b = malloc(sizeof(int) * *argc);
    arr->block_count_a = malloc(sizeof(int) * *argc);
    arr->block_count_b = malloc(sizeof(int) * *argc);
    i = 0;
    while (i < arr->len)
    {
        arr->stack_a[j] = ft_atoi_push_swap(s[i]);
        i++;
        j++;
    }
    i = 0;
    while (i++ < arr->len)
    {
        arr->block_count_a[i] = 0;
        arr->block_count_b[i] = 0;
    }
    i = -1;
    //while (s[++i])
        //free(s[i]);
    //free((char **)s);
    arr->num_a = arr->len;
    arr->res_str = str;
}

void fill_struct_without_brakets(t_main *arr, int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;
    arr->stack_a = malloc(sizeof(int) * argc);
    arr->stack_b = malloc(sizeof(int) * argc);
    arr->block_a = malloc(sizeof(int) * argc);
    arr->block_b = malloc(sizeof(int) * argc);
    arr->block_count_a = malloc(sizeof(int) * argc);
    arr->block_count_b = malloc(sizeof(int) * argc);
    while (i < argc)
    {
        arr->stack_a[j] = ft_atoi_push_swap(argv[i]);
        i++;
        j++;
    }
    arr->num_a = argc - 1;
    i = 0;
    while (i++ < argc)
    {
        arr->block_count_a[i] = 0;
        arr->block_count_b[i] = 0;
    }

}

//// To add the case when memory is not allocated

// Work correctly 