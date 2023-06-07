/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithms_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 15:26:53 by fras          #+#    #+#                 */
/*   Updated: 2023/06/07 15:45:22 by fras          ########   odam.nl         */
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
