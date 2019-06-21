/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:10:56 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/21 18:01:18 by mrolfe           ###   ########.fr       */
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
    
//    int ret1;
//    int ret2;
//    int ret3;
//    int ret4;

    l = 0;
    m = 0;
    z = 0;
    y = 0;
//    ret1 = 0;
//    ret2 = 0;
//    ret3 = 0;
//    ret4 = 0;
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
        while (!(is_sorted_for_a(arr)) && arr->num_b != 0)
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
                    //l++;
                    y++;
                    if (y > 1)
                        swipe_block_count_b(arr, y);
                    //l--;
                }
            }
            if (arr->block_count_a[m] > 3 && !(is_sorted_for_block_a(arr, m)) && arr->num_a > 3)
            {
                mediana_rotating_for_a(arr, m, &y);
                if (arr->block_count_a[m] == 0 && z > 1)
                    move_block_count_a(arr, z);
                //l++;
                y++;
                if (y > 1)
                    swipe_block_count_b(arr, y);
                //l--;
            }
            if (arr->block_count_b[l] > 3)
            {
                mediana_rotating_for_b(arr, l, &z);
                if (arr->block_count_b[l] == 0 && y > 1)
                    move_block_count_b(arr, y);
                //m++;
                z++;
                if (z > 1)
                    swipe_block_count_a(arr, z);
                //m--;
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
                //ret3 = 1;
            }
//            if (ret1 || ret2 || ret3)
//                l--;
//            if (ret4)
//                m--;
//            ret1 = 0;
//            ret2 = 0;
//            ret3 = 0;
//            ret4 = 0;
        }
        if (arr->num_a == 3)
            sorting_three(arr);
    }
    // if (arr->num_b == 0)
    //     arr->b_is_empty = 1;
    // else
    //     arr->b_is_empty = 0;
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

void ft_sa_for_block_a(t_main *arr)
{
    int i;
    int j;
    int tmp;
    
    i = arr->block_a[0];
    j = arr->block_a[1];
    tmp = i;
    arr->block_a[0] = j;
    arr->block_a[1] = tmp;
}

void ft_sb_for_block_b(t_main *arr)
{
    int i;
    int j;
    int tmp;
    
    i = arr->block_b[0];
    j = arr->block_b[1];
    tmp = i;
    arr->block_b[0] = j;
    arr->block_b[1] = tmp;
}

void ft_rra_for_block_a(t_main *arr, int m)
{
    int i;
    int last_el;

    i = arr->block_count_a[m] - 2;
    last_el = arr->block_a[arr->block_count_a[m] - 1];
    while (i != -1)
    {
        arr->block_a[i + 1] = arr->block_a[i];
        i--;
    }
    arr->block_a[0] = last_el;
}

void ft_rrb_for_block_b(t_main *arr, int l)
{
    int i;
    int last_el;

    i = 0;
    if (arr->block_count_b != 0) // ???
        i = arr->block_count_b[l] - 2;
    last_el = arr->block_b[arr->block_count_b[l] - 1];
    while (i != -1)
    {
        arr->block_b[i + 1] = arr->block_b[i];
        i--;
    }
    arr->block_b[0] = last_el;
}

//functions rra ans sa work correctly

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
    //int r;

    i = 0;
    count_for_ra = 0;
    block_count_for_b = 0;
    block_count_for_a = arr->block_count_a[m];
    n = arr->block_count_a[m];
    if (arr->block_count_a[m] == 0)
        n = arr->num_a;
    mediana_finding_for_a(arr, m);
    //arr->block_count_a = 0;
    //arr->block_count_b = 0;
    j = i;
    while (j < n)
    {
        if (arr->stack_a[i] >= arr->mediana)
        {
            ft_ra(arr);
            //i++;
            j++;
            count_for_ra++;
            //arr->block_count_a++;
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
            //arr->block_b[*k] = arr->stack_b[i];
            //arr->num_a--;
            //arr->num_b++;
            j++;
            //(*k)++;
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
//
//    if (block_count_for_a == -1)
//        (*m)++;
    i = 0;
    while (i++ < count_for_ra)
        ft_rra(arr);
}


void mediana_rotating_for_b(t_main *arr, int l, int *z)
{
    int i;
    int j;
    int n;
    int block_count_for_a;
    int block_count_for_b;
    int count_for_rb;
    //int r;

    i = 0;
    count_for_rb = 0;
    block_count_for_a = 0;
    block_count_for_b = arr->block_count_b[l];
    n = arr->block_count_b[l];
    if (arr->block_count_b[l] == 0)
        n = arr->num_b;
    mediana_finding_for_b(arr, l);
    //arr->block_count_b = 0;
    //arr->block_count_a = 0;
    j = i;
    while (j < n)
    {
        if (arr->stack_b[i] <= arr->mediana)
        {
            ft_rb(arr);
            j++;
            //i++;
            count_for_rb++;
            //arr->block_count_b++;
        }
        else
        {
            
            ft_pa(arr);
            //k = 0;
            //arr->block_count_a++;
            block_count_for_a++;
            if (arr->block_count_b[l])
                block_count_for_b--;
            block_count_for_b--;
            if (arr->block_count_b[l])
                arr->block_count_b[l]--;
            //arr->block_a[k++] = arr->stack_a[i];
            //arr->num_a--;
            //arr->num_b++;
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
//    if (block_count_for_b == -1)
//        (*l)++;
    i = 0;
    while (i++ < count_for_rb)
        ft_rrb(arr);
}

// DOESN'T WORK CORRECTLY

// void mediana_rotating_for_b(t_main *arr)
// {
//     int i;
//     int sum;

//     i = 0;
//     sum = 0;
//     mediana_finding(arr);
//     while(arr->block_count_b < arr->num_b)
//     {
//         if (arr->stack_b[i++] >= arr->mediana)
//         {
//             ft_rb(arr);
//             arr->num_b++;            
//         }
//         else
//         {
//             ft_pa(arr);
//             arr->block_count_a++;
//             arr->num_a++;            
//         }
//     }
// }

// DOESN'T WORK CORRECTLY


// void main_algorithm(t_main *arr)
// {
//     int k;
//     int i;

//     printf("------------------------------------------\n");
//     while (!(is_sorted_for_a(arr)))
//     {
//         while (arr->num_a > 3)
//             mediana_rotating_for_a(arr);
//         printf ("mediana_rotating_for_a\n");
//         printf ("stack_a\n");
//         while (k < arr->num_a)
//             printf("%d\n",  arr->stack_a[k++]);
//         printf("-----\n");
//         if (arr->num_a <= 3 || arr->num_b <= 3)
//             sorting_three(arr);
//         printf("sorting_three\n");
//         k = 0;
//         printf ("stack_a\n");
//         while (k < arr->num_a)
//             printf("%d\n",  arr->stack_a[k++]);
//         printf("-----\n");
//         k = 0;
//         printf ("stack_b\n");
//         while (k < arr->num_b)
//             printf("%d\n",  arr->stack_b[k++]);
//         printf("-----------\n");
//         while (arr->num_b > 3)
//             mediana_rotating_for_b(arr);
//         printf ("mediana_rotating_for_b\n");
//         printf ("stack_a\n");
//         k = 0;
//         while (k < arr->num_a)
//             printf("%d\n",  arr->stack_a[k++]);
//         printf("-----\n");
//         if (arr->num_a <= 3 || arr->num_b <= 3)
//             sorting_three(arr);
//         printf("sorting_three\n");
//         k = 0;
//         printf ("stack_a\n");
//         while (k < arr->num_a)
//             printf("%d\n",  arr->stack_a[k++]);
//         printf("-----\n");
//         k = 0;
//         printf ("stack_b\n");
//         while (k < arr->num_b)
//             printf("%d\n",  arr->stack_b[k++]);
//         printf("-----------\n");
//         if ((is_sorted_for_a(arr)) && arr->num_b != 0)
//         {
//             i = 0;
//             while (i++ < arr->num_b + 2)
//             {
//                 ft_rrb(arr);
//                 ft_pa(arr);
//             }
//             arr->num_b = 0;
//         }
//         arr->num = arr->num_a + arr->num_b;
//     }
//     k = 0;
//     while (k < arr->num_a)
//         printf("%d\n",  arr->stack_a[k++]);
//     k = 0;
//     while (k < arr->num_b)
//         printf("%d\n",  arr->stack_b[k++]);
// }

// Changed mediana finding in mediana_rotating_for_b
// Saved mediana finding in mediana_rotating_for_a
// Needed to test what variant is correct


// void main_algorithm(t_main *arr)
// {
//     int k;
//     int i;
    
//     if (!(is_sorted_for_a(arr)))
//     {
//         if (arr->num_a > 3)
//             mediana_rotating_for_a(arr);
//         k = 0;
//         printf ("mediana_rotating_for_a\n");
//         printf ("stack_a\n");
//         while (k < arr->num_a)
//             printf("%d\n",  arr->stack_a[k++]);
//         printf("-----\n");
//         k = 0;
//         printf ("stack_b\n");
//         while (k < arr->num_b)
//             printf("%d\n",  arr->stack_b[k++]);
//         printf("-----------\n");
//         if (arr->num_b > 3)
//             mediana_rotating_for_b(arr);
//         printf ("mediana_rotating_for_b\n");
//          printf ("stack_a\n");
//         k = 0;
//         while (k < arr->num_a)
//             printf("%d\n",  arr->stack_a[k++]);
//         printf("-----\n");
//         k = 0;
//          printf ("stack_b\n");
//         while (k < arr->num_b)
//             printf("%d\n",  arr->stack_b[k++]);
//         printf("-----------\n");
//         if (arr->num_a <= 3 || arr->num_b <= 3)
//             sorting_three(arr);
//         printf("sorting_three\n");
//         k = 0;
//         printf ("stack_a\n");
//         while (k < arr->num_a)
//             printf("%d\n",  arr->stack_a[k++]);
//         printf("-----\n");
//         k = 0;
//         printf ("stack_b\n");
//         while (k < arr->num_b)
//             printf("%d\n",  arr->stack_b[k++]);
//         printf("-----------\n");
//         if ((is_sorted_for_a(arr)) && arr->num_b != 0)
//         {
//             i = 0;
//             while (i++ < arr->num_b)
//             {
//                 ft_rrb(arr);
//                 printf("Making rrb\n");
//                 printf ("stack_a\n");
//                 while (k < arr->num_a)
//                     printf("%d\n",  arr->stack_a[k++]);
//                 printf("-----\n");
//                 k = 0;
//                 printf ("stack_b\n");
//                 while (k < arr->num_b)
//                     printf("%d\n",  arr->stack_b[k++]);
//                 printf("-----------\n");
//                 arr->num_a++;
//                 ft_pa(arr);
//                 printf("Making pa\n");
//                 printf ("stack_a\n");
//                 while (k < arr->num_a)
//                     printf("%d\n",  arr->stack_a[k++]);
//                 printf("-----\n");
//                 k = 0;
//                 printf ("stack_b\n");
//                 while (k < arr->num_b)
//                     printf("%d\n",  arr->stack_b[k++]);
//                 printf("-----------\n");
//                 k = 0;
//                 printf("Making adding\n");
//                 printf ("stack_a\n");
//                 while (k < arr->num_a)
//                     printf("%d\n",  arr->stack_a[k++]);
//                 printf("-----\n");
//                 k = 0;
//                 printf ("stack_b\n");
//                 while (k < arr->num_b)
//                     printf("%d\n",  arr->stack_b[k++]);
//                 printf("-----------\n");
//                 arr->num_b++;
//             }
//             arr->num_b = 0;        
//         }
//         arr->num = arr->num_a + arr->num_b;         
//     }
//     k = 0;
//     while (k < arr->num_a)
//         printf("%d\n",  arr->stack_a[k++]);
//     k = 0;
//     while (k < arr->num_b)
//         printf("%d\n",  arr->stack_b[k++]);
// }

// void mediana_rotating_for_a(t_main *arr)
// {
//     int i;

//     i = 0;
//     mediana_finding(arr);
//     if (!arr->block_count_a)
//         arr->block_count_a = 0; 
//     while (i < arr->num_a)
//     {
//         if (arr->stack_a[i] >= arr->mediana)
//         {
//             ft_ra(arr);
//             arr->block_count_a++;
//         }
//         else
//         {
//             ft_pb(arr);
//             arr->block_count_b++;
//             arr->num_a--;
//             arr->num_b++;
//         }
//         i++;
//     }
// }

// void main_algorithm(t_main *arr)
// {
//     int k;
//     int i;
//     int j;
//     int l;
//     int m;

//     l = 0;
//     m = 0;
//     while (!(is_sorted_for_a(arr)))
//     {
//         while (arr->num_a > 3 && arr->block_count_a[m] == 0)
//         {
//             mediana_rotating_for_a(arr, l, m);
//             l++;
//         }
//         if (arr->num_a <= 3 || arr->num_b <= 3)
//             sorting_three(arr);
//         if (arr->block_count_a[m] <= 3 || arr->block_count_b[l] <=3)
//             sort_for_block_count(arr, l, m);
//         if (!(is_sorted_for_b(arr)))
//         {
//             while (arr->num_b > 3)
//             {
//                 mediana_rotating_for_b(arr, l, m);
//                 m++;
//             }
//         }
//         if (arr->num_a <= 3 || arr->num_b <= 3)
//             sorting_three(arr);
//         i = 0;
//         if (is_sorted_for_block_b(arr, m))
//         {
//             while (i++ < arr->block_count_b[l])
//                 ft_pa(arr);
//         }
//         if ((is_sorted_for_a(arr)) && !(is_sorted_for_b(arr)) && arr->num_b > 3)
//         {
//             while (!(is_sorted_for_b(arr)))
//             {
//                 if (arr->num_b > 3)
//                     mediana_rotating_for_b(arr, l, m);
//                 if (arr->block_count_a[m] <= 3 || arr->block_count_b[l] <=3)
//                     sort_for_block_count(arr, l, m);
//                 if (arr->num_a <= 3 || arr->num_b <= 3)
//                     sorting_three(arr);
//             }
//         }

//         if ((is_sorted_for_a(arr)) && arr->num_b <= 3)
//         {
//             i = 0;
//             j = arr->num - arr->num_a;
//             while (i++ < j)
//             {
//                 ft_rrb(arr);
//                 ft_pa(arr);
//             }
//             arr->num_b = 0;
//         }
//     }
//     k = 0;
//     while (k < arr->num_a)
//         printf("%d\n",  arr->stack_a[k++]);
//     k = 0;
//     while (k < arr->num_b)
//         printf("%d\n",  arr->stack_b[k++]);
// }