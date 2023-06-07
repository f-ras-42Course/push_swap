/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithms_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 15:26:53 by fras          #+#    #+#                 */
/*   Updated: 2023/06/07 08:06:03 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_to_stackA(t_data **stackA, t_data **stackB)
{
	t_cmd command;

	command = print_ops(push_a(stackA, stackB));
	while(command != none)
		command = print_ops(push_a(stackA, stackB));
}

int	get_highest_bit_length(t_data *stackA)
{
	t_data	*ptr;
	int		highest_value;
	int		bit_length;

	highest_value = stackA->normalized_value;
	ptr = stackA->next;
	while (ptr != stackA)
	{
		if (highest_value <= ptr->normalized_value)
			highest_value = ptr->normalized_value;
		ptr = ptr->next;
	}
	bit_length = 0;
	while (highest_value)
	{
		highest_value /= 2;
		bit_length++;
	}
	return (bit_length);
}

void	small_sort_reverse(t_data **stack, size_t data_size)
{
	t_data *secondA;

	secondA = (*stackA)->next;
	if (data_size == 2 && (*stackA)->normalized_value == 1)
		print_ops(swap_a(stackA));
	if (data_size == 3)
	{
		if ((*stackA)->normalized_value == 0 && secondA->normalized_value == 2)
		{
			print_ops(rotate_a(stackA));
			print_ops(swap_a(stackA));
			print_ops(rev_rotate_a(stackA));
		}
		if ((*stackA)->normalized_value == 1 && secondA->normalized_value == 0)
			print_ops(swap_a(stackA));
		if ((*stackA)->normalized_value == 1 && secondA->normalized_value == 2)
			print_ops(rev_rotate_a(stackA));
		if ((*stackA)->normalized_value == 2 && secondA->normalized_value == 0)
			print_ops(rotate_a(stackA));
		if ((*stackA)->normalized_value == 2 && secondA->normalized_value == 1)
		{
			print_ops(swap_a(stackA));
			print_ops(rev_rotate_a(stackA));
		}
	}
}
