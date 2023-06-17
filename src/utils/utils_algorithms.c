/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_algorithms.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 15:26:53 by fras          #+#    #+#                 */
/*   Updated: 2023/06/17 17:24:27 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_to_stack_a(t_data **stackA, t_data **stackB)
{
	t_cmd	command;

	command = print_ops(push_a(stackA, stackB));
	while (command != none)
		command = print_ops(push_a(stackA, stackB));
}

int	get_highest_bit_length(t_data *stack)
{
	t_data	*ptr;
	int		highest_value;
	int		bit_length;

	highest_value = stack->normalized_value;
	ptr = stack->next;
	while (ptr != stack)
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

int	locate_low_top_or_bottom(t_data **stackA, int num)
{
	t_data	*ptr;
	int		next_check;
	int		prev_check;

	next_check = 0;
	prev_check = 0;
	ptr = *stackA;
	while (ptr->normalized_value != num && ++next_check)
		ptr = ptr->next;
	ptr = (*stackA)->prev;
	while (ptr->normalized_value != num && ++prev_check)
		ptr = ptr->prev;
	if (next_check <= (prev_check + 1))
		return (1);
	return (0);
}
