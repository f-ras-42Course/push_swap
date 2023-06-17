/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 10:10:25 by fras          #+#    #+#                 */
/*   Updated: 2023/06/17 17:33:28 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_data *start_input, size_t data_size)
{
	t_data	*stack_a;
	t_data	*stack_b;

	stack_a = start_input;
	stack_b = NULL;
	if (is_sorted(stack_a, data_size))
		return ;
	if (data_size <= 3)
		small_sort(&stack_a, data_size, 0);
	else if (data_size <= 73)
		ferry_sort (&stack_a, &stack_b, data_size);
	else
		redix_sort(&stack_a, &stack_b, data_size);
}
