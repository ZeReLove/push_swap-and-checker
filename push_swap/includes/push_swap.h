/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:44:05 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/23 17:24:50 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_main
{
    int *stack_a;
    int *stack_b;
    int num_a;
    int num_b;
    int *block_a;
    int *block_b;
    int num;
    int *array;
    int mediana;
    int *block_count_a;
    int *block_count_b;
    int n;
    int len;
    int ret;
    char **res_str;
    int index;
    //int l;
    //nt m;
}              t_main;


int check_symbols(int argc, char **argv);
int check_duplicates(t_main *arr);
int check_all(t_main *arr, int argc, char **argv, char **str);
int ft_atoi_push_swap(char *str);
void fill_struct(t_main *arr, int *argc, char **argv);
void fill_struct_for_brakets(t_main *arr, int *argc, char **argv);
void fill_struct_without_brakets(t_main *arr, int argc, char **argv);
void ft_sa(t_main *arr);
void ft_sb(t_main *arr);
void ft_ss(t_main *arr);
void ft_pa(t_main *arr);
void ft_pb(t_main *arr);
void ft_ra(t_main *arr);
void ft_rb(t_main *arr);
void ft_rr(t_main *arr);
void ft_rra(t_main *arr);
void ft_rrb(t_main *arr);
void ft_rrr(t_main *arr);
//int main(int argc, char **argv);
void main_algorithm(t_main *arr);
void sorting_three(t_main *arr);
int is_sorted_for_a(t_main *arr);
int is_sorted_for_b(t_main *arr);
void mediana_rotating_for_a(t_main *arr, int *z);
void mediana_rotating_for_b(t_main *arr, int *y);
void bubble_sort(t_main *arr);
int is_bubble_sorted(t_main *arr);
void mediana_finding_for_a(t_main *arr);
void filling_array(t_main *arr);
void mediana_finding_for_b(t_main *arr);
int is_bubble_sorted_for_b(t_main *arr);
void filling_array_for_b(t_main *arr);
void bubble_sort_for_b(t_main *arr);
void sorting_three(t_main *arr);
void sort_for_block_count(t_main *arr);
int is_sorted_for_block_a(t_main *arr);
int is_sorted_for_block_b(t_main *arr);
void swipe_block_count_b(t_main *arr, int y);
void swipe_block_count_a(t_main *arr, int z);
void move_block_count_b(t_main *arr, int y);
void move_block_count_a(t_main *arr, int z);
void read_and_make_instructions(t_main *arr);
void make_operations(t_main *arr, char *line);
int is_sorted(t_main *arr);
void	put_error(char *line);
void case_one(t_main *arr, int *y, int z);
void case_two(t_main *arr, int y, int *z);
void case_three(t_main *arr, int y);
//void algorithm(t_main *arr, int *z, int *y);

#endif