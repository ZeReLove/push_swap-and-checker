/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:48:44 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/21 17:52:50 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_main arr;
    char **str;
    
    ft_bzero(&arr, sizeof(arr));
    fill_struct(&arr, &argc, argv);
    str = arr.res_str;
    if (check_all(&arr, argc, argv, str))
    {
        read_and_make_instructions(&arr);
        if (is_sorted(&arr))
            printf("OK\n");
        else
            printf("KO\n");
    }
}

void read_and_make_instructions(t_main *arr)
{
    char *line;

    line = NULL;
    while (get_next_line(0, &line))
    {
        make_operations(arr, line);
  //    free(line);
        
    }

}

void make_operations(t_main *arr, char *line)
{
    if (ft_strequ(line, "sa"))
		ft_sa(arr);
	else if (ft_strequ(line, "sb"))
		ft_sb(arr);
	else if (ft_strequ(line, "ra"))
		ft_ra(arr);
	else if (ft_strequ(line, "rb"))
		ft_rb(arr);
	else if (ft_strequ(line, "rra"))
		ft_rra(arr);
	else if (ft_strequ(line, "rrb"))
		ft_rrb(arr);
	else if (ft_strequ(line, "pa"))
		ft_pa(arr);
	else if (ft_strequ(line, "pb"))
		ft_pb(arr);
	else
		put_error(line);
	free(line);
    line = NULL;
}

void	put_error(char *line)
{
	write(1, "Error\n", 6);
	free(line);
	exit(1);
}

int is_sorted(t_main *arr)
{
    int i;
    // int ret1;
    // int ret2;

    i = 0;
    while (i < arr->num_a - 1)
    {
        if (arr->stack_a[i] < arr->stack_a[i + 1])
            i++;
        else
            return (0);
    }
    if (!arr->num_b)
        return(1);
    return(0);
}