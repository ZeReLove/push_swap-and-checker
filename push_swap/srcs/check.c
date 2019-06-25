/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:05:31 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/25 18:22:21 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_symbols(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while ((argv[i][j] >= '0' && argv[i][j] <= '9') || ((argv[i][j] == '+'
				|| argv[i][j] == '-') && (argv[i][j + 1] >= '0' &&
				argv[i][j + 1] <= '9')))
			j++;
		if (!argv[i][j])
		{
			i++;
			j = 0;
		}
		else
			break ;
	}
	if (argc == i)
		return (1);
	else
		return (0);
}

int		check_duplicates(t_main *arr)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (j < arr->num_a - 1)
	{
		i = j + 1;
		while (i < arr->num_a)
		{
			if (arr->stack_a[j] == arr->stack_a[i])
				return (0);
			else
				i++;
		}
		j++;
	}
	if (i == arr->num_a)
		return (1);
	else
		return (0);
}

int		check_all(t_main *arr, int argc, char **argv, char **str)
{
	int res1;
	int res2;

	arr->num_a = argc - 1;
	if (arr->ret == 1)
		res1 = check_symbols(arr->len, str);
	else
		res1 = check_symbols(argc, argv);
	res2 = check_duplicates(arr);
	if (res1 && res2)
		return (1);
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
}

void	common_for_fill_functions(t_main *arr, int argc)
{
	arr->stack_a = malloc(sizeof(int) * argc);
	arr->stack_b = malloc(sizeof(int) * argc);
	if (arr->index == 1)
	{
		arr->block_a = ft_memalloc(sizeof(int) * argc);
		arr->block_b = ft_memalloc(sizeof(int) * argc);
		arr->block_count_a = ft_memalloc(sizeof(int) * argc);
		arr->block_count_b = ft_memalloc(sizeof(int) * argc);
	}
}
