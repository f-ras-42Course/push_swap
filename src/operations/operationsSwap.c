/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operationsSwap.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 10:14:58 by fras          #+#    #+#                 */
/*   Updated: 2023/06/18 18:55:46 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	swap_a(t_data **stackA)
{
	if (!*stackA || (*stackA)->next == *stackA)
		return (none);
	swap(stackA);
	return (sa);
}

t_cmd	swap_b(t_data **stackB)
{
	if (!*stackB || (*stackB)->next == *stackB)
		return (none);
	swap(stackB);
	return (sb);
}

t_cmd	swap_swap_ab(t_data **stackA, t_data **stackB)
{
	swap_a(stackA);
	swap_b(stackB);
	return (ss);
}

void	swap(t_data **stack)
{
	t_data	*first;
	t_data	*second;
	t_data	*third;
	t_data	*tail;

	first = *stack;
	second = first->next;
	third = second->next;
	tail = first->prev;
	if (third != first)
	{
		first->prev = second;
		first->next = third;
		second->prev = tail;
		second->next = first;
		tail->next = second;
		third->prev = first;
	}
	*stack = second;
}
