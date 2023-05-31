/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 18:26:53 by fras          #+#    #+#                 */
/*   Updated: 2023/05/31 19:47:07 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	redix_sort(t_data **stackA, t_data **stackB)
{
	int		highest_bit_length;
	t_data	*ptr;
	ptr = (*stackA)->next;
	*stackB = NULL;
	highest_bit_length = get_highest_bit_length(*stackA);
	while (highest_bit_length)
	{
		while (*stackA != ptr)
		if ((*stackA)->normalized_value &1)
		//insert and check bit-wise operators.
	}
	printf("\n\n\n\n\nHIGHEST BIT-LENGTH = %d\n\n\n\n\n\n", highest_bit_length);
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
