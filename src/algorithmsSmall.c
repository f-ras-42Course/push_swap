/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithmsSmall.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 15:00:58 by fras          #+#    #+#                 */
/*   Updated: 2023/06/07 19:48:34 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_data **stackA, size_t data_size, int lowest)
{
	int second_value;

	second_value = (*stackA)->next->normalized_value;
	if (data_size == 2 && (*stackA)->normalized_value != lowest)
		print_ops(swap_a(stackA));
	if (data_size == 3)
	{
		if ((*stackA)->normalized_value == lowest && second_value == lowest+2)
		{
			print_ops(rotate_a(stackA));
			print_ops(swap_a(stackA));
			print_ops(rev_rotate_a(stackA));
		}
		if ((*stackA)->normalized_value == lowest+1 && second_value == lowest)
			print_ops(swap_a(stackA));
		if ((*stackA)->normalized_value == lowest+1 && second_value == lowest+2)
			print_ops(rev_rotate_a(stackA));
		if ((*stackA)->normalized_value == lowest+2 && second_value == lowest)
			print_ops(rotate_a(stackA));
		if ((*stackA)->normalized_value == lowest+2 && second_value == lowest+1)
		{
			print_ops(swap_a(stackA));
			print_ops(rev_rotate_a(stackA));
		}
	}
}
