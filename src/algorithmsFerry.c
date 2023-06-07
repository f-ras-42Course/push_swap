/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithmsFerry.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 15:01:02 by fras          #+#    #+#                 */
/*   Updated: 2023/06/07 19:51:31 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ferry_sort(t_data **stackA, t_data **stackB, size_t data_size)
{
	while (data_size - 3)
	{
		if (locate_low_normal_or_rev(stackA, data_size - 4))
			while ((*stackA)->normalized_value != i)
				print_ops(rotate_a(stackA));
		else
			while ((*stackA)->normalized_value != i)
				rint_ops(rev_rotate_a(stackA));
		data_size--;
	}
	push_all_to_stackA(stackA, stackB);
	small_sort(stackA, 3, 1);
	push_all_to_stackA(stackA, stackB);
}
