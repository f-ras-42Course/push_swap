/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithms.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 18:26:53 by fras          #+#    #+#                 */
/*   Updated: 2023/06/06 16:40:19 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_data **stackA, size_t data_nodes)
{
	t_data *secondA;

	secondA = (*stackA)->next;
	if (data_nodes == 2 && (*stackA)->normalized_value == 1)
		print_ops(swap_a(stackA));
	if (data_nodes == 3)
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

void	redix_sort(t_data **stackA, t_data **stackB)
{
	int		bit_length;
	size_t	stack_size;
	size_t	i;
	
	i = 0;
	bit_length = get_highest_bit_length(*stackA);
	stack_size = circular_list_size(*stackA);
	while (bit_length)
	{
		if (!((*stackA)->normalized_value &1))
		{
			(*stackA)->normalized_value = (*stackA)->normalized_value >> 1;
			print_ops(push_b(stackA, stackB));
		}
		else
		{
			(*stackA)->normalized_value = (*stackA)->normalized_value >> 1;
			print_ops(rotate_a(stackA));
		}
		i++;
		if (i == stack_size)
		{
			push_all_to_stackA(stackA, stackB);
			i = 0;
			bit_length--;
		}
	}
	printf("\n\n\n\n\nHIGHEST BIT-LENGTH = %d\n\n\n\n\n\n", bit_length);
}
