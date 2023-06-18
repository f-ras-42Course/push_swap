/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithms.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 18:26:53 by fras          #+#    #+#                 */
/*   Updated: 2023/06/18 19:00:44 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

bool	is_sorted(t_data *stackA, size_t data_size)
{
	int		check;

	check = 0;
	while (data_size)
	{
		if (check != stackA->normalized_value)
			return (false);
		check++;
		data_size--;
		stackA = stackA->next;
	}
	return (true);
}

void	small_sort(t_data **stackA, size_t data_size, int lowest)
{
	int	second;

	second = (*stackA)->next->normalized_value;
	if (data_size == 2 && (*stackA)->normalized_value != lowest)
		print_ops(swap_a(stackA));
	if (data_size == 3)
	{
		if ((*stackA)->normalized_value == lowest && second == lowest + 2)
		{
			print_ops(swap_a(stackA));
			print_ops(rotate_a(stackA));
		}
		if ((*stackA)->normalized_value == lowest + 1 && second == lowest)
			print_ops(swap_a(stackA));
		if ((*stackA)->normalized_value == lowest + 1 && second == lowest + 2)
			print_ops(rev_rotate_a(stackA));
		if ((*stackA)->normalized_value == lowest + 2 && second == lowest)
			print_ops(rotate_a(stackA));
		if ((*stackA)->normalized_value == lowest + 2 && second == lowest + 1)
		{
			print_ops(swap_a(stackA));
			print_ops(rev_rotate_a(stackA));
		}
	}
}

void	ferry_sort(t_data **stackA, t_data **stackB, size_t data_size)
{
	int	lowest_num;

	lowest_num = 0;
	while (lowest_num < (int)data_size - 3)
	{
		if (locate_low_top_or_bottom(stackA, lowest_num))
			while ((*stackA)->normalized_value != lowest_num)
				print_ops(rotate_a(stackA));
		else
			while ((*stackA)->normalized_value != lowest_num)
				print_ops(rev_rotate_a(stackA));
		print_ops(push_b(stackA, stackB));
		lowest_num++;
	}
	small_sort(stackA, 3, lowest_num);
	push_all_to_stack_a(stackA, stackB);
}

void	radix_sort(t_data **stackA, t_data **stackB, size_t data_size)
{
	int		bit_length;
	int		bit_check;
	size_t	i;

	i = 0;
	bit_check = 1;
	bit_length = get_highest_bit_length(*stackA);
	while (bit_length)
	{
		if (((*stackA)->normalized_value & bit_check) == 0)
			print_ops(push_b(stackA, stackB));
		else
			print_ops(rotate_a(stackA));
		i++;
		if (i == data_size)
		{
			bit_check *= 2;
			push_all_to_stack_a(stackA, stackB);
			i = 0;
			bit_length--;
		}
	}
}
