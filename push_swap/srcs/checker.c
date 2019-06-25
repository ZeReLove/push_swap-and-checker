/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:48:44 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/25 18:36:13 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_main	arr;
	char	**str;
	int		i;

	ft_bzero(&arr, sizeof(arr));
	fill_struct(&arr, &argc, argv);
	str = arr.res_str;
	if (check_all(&arr, argc, argv, str))
	{
		read_and_make_instructions(&arr);
		if (is_sorted(&arr) == 1)
			printf("OK\n");
		if (is_sorted(&arr) == 0)
			printf("KO\n");
	}
	free(arr.stack_a);
	free(arr.stack_b);
	i = -1;
	if (arr.ret)
	{
		while (str[++i])
			free((char *)str[i]);
		free((char **)str);
	}
}

void	read_and_make_instructions(t_main *arr)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_strequ(line, "sa"))
		{
			ft_sa(arr);
			free(line);
			line = NULL;
		}
		else
			make_operations(arr, line);
	}
}

void	make_operations(t_main *arr, char *line)
{
	if (ft_strequ(line, "sb"))
		ft_sb(arr);
	else if (ft_strequ(line, "ss"))
		ft_ss(arr);
	else if (ft_strequ(line, "ra"))
		ft_ra(arr);
	else if (ft_strequ(line, "rb"))
		ft_rb(arr);
	else if (ft_strequ(line, "rr"))
		ft_rr(arr);
	else if (ft_strequ(line, "rra"))
		ft_rra(arr);
	else if (ft_strequ(line, "rrb"))
		ft_rrb(arr);
	else if (ft_strequ(line, "rrr"))
		ft_rrr(arr);
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

int		is_sorted(t_main *arr)
{
	int i;
	int ret1;
	int ret2;

	i = 0;
	while (i < arr->num_a - 1)
	{
		if (arr->stack_a[i] < arr->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	ret1 = (i == arr->num_a - 1) ? 1 : 0;
	ret2 = (!arr->num_b) ? 1 : 0;
	if (ret1 && ret2)
		return (1);
	else
		return (0);
}
