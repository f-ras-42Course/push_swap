/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 18:26:53 by fras          #+#    #+#                 */
/*   Updated: 2023/06/01 16:24:45 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	redix_sort(t_data **stackA, t_data **stackB)
{
	int		bit_length;
	t_data	*ptr;
	ptr = (*stackA)->next;
	*stackB = NULL;
	bit_length = get_highest_bit_length(*stackA) - 1;
	push_b(stackA, stackB);
	while (bit_length)
	{
		while (*stackA != ptr)
		{
			if (!ptr->normalized_value &1)
			{
				push_b(ptr, stackB);
				(*stackB)->normalized_value >> 1;
			}
			else
				ptr->normalized_value >> 1;
			ptr = ptr->next;
		}
		
		bit_length--;
	}
	printf("\n\n\n\n\nHIGHEST BIT-LENGTH = %d\n\n\n\n\n\n", bit_length);
}

t_data	*all_of_stackB_push_to_stackA(t_data **stackA, t_data **stackB)
{
	t_data *tailB;

	tailB = *stackB->prev;
	while()
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
