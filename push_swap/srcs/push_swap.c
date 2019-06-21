/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:03:01 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/21 17:57:37 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_main arr;
    int i;
    char **str;

    if (argc > 1)
    {
        fill_struct(&arr, &argc, argv);
        str = arr.res_str;
        if (check_all(&arr, argc, argv, str))
        {
            main_algorithm(&arr);
            //printf("-----------\n");
            //i = 0;
            i = 0;
            while (i < arr.num)
                printf("%d\n",  arr.stack_a[i++]);
            i = -1;
//            if (arr.ret)
//            {
//                while (str[++i])
//                    free((char *)str[i]);
//                free((char **)str);
//            }
            free(arr.stack_a);
            free(arr.stack_b);
            free(arr.block_a);
            free(arr.block_b);
            free(arr.block_count_a);
            free(arr.block_count_b);
        }   
    }
    return (0);
}