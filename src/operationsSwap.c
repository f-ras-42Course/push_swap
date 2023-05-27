/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operationsSwap.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 10:14:58 by fras          #+#    #+#                 */
/*   Updated: 2023/05/28 01:45:09 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	swap_a(t_data **stackA)
{
	t_data	*first;
	t_data	*second;
	t_data	*third;
	t_data	*tail;

	if (!*stackA || (*stackA)->next == *stackA)
		return ;
	first = *stackA;
	second = first->next;
	third = second->next;
	tail = first->prev;
	first->prev = second;
	first->next = third;
	second->prev = tail;
	second->next = first;
	tail->next = second;
	third->prev = first;
	*stackA = second;
	return(sa);
}

t_cmd	swap_b(t_data **stackB)
{
	t_data	*first;
	t_data	*second;
	t_data	*third;
	t_data	*tail;

	if (!*stackB || (*stackB)->next == *stackB)
		return ;
	first = *stackB;
	second = first->next;
	third = second->next;
	tail = first->prev;
	first->prev = second;
	first->next = third;
	second->prev = tail;
	second->next = first;
	tail->next = second;
	third->prev = first;
	*stackB = second;
	return(sb);
}

t_cmd	swap_swap_ab(t_data **stackA, t_data **stackB)
{
	swap_a(stackA);
	swap_b(stackB);
	return(ss);
}
