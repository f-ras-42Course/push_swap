/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operationsPush.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 14:42:11 by fras          #+#    #+#                 */
/*   Updated: 2023/05/25 14:52:24 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_data **stackA,	t_data **stackB)
{
	t_data	*old_b_head;

	if (!*stackB)
		return ;
	old_b_head = *stackB;
	*stackB = (*stackB)->next;
	if (*stackB == old_b_head)
		*stackB = NULL;
	else
	{
		(*stackB)->prev = old_b_head->prev;
		(*stackB)->prev->next = *stackB;
	}
	if (!*stackA)
	{
		old_b_head->prev = old_b_head;
		old_b_head->next = old_b_head;
	}
	else
	{
		old_b_head->prev = (*stackA)->prev;
		old_b_head->next = *stackA;
		(*stackA)->prev->next = old_b_head;
		(*stackA)->prev = old_b_head;
	}
	*stackA = old_b_head;
	ft_printf("pa\n");
}

void	push_b(t_data **stackA,	t_data **stackB)
{
	t_data	*old_a_head;

	if (!*stackA)
		return ;
	old_a_head = *stackA;
	*stackA = (*stackA)->next;
	if (*stackA == old_a_head)
		*stackA = NULL;
	else
	{
		(*stackA)->prev = old_a_head->prev;
		(*stackA)->prev->next = *stackA;
	}
	if (!*stackB)
	{
		old_a_head->prev = old_a_head;
		old_a_head->next = old_a_head;
	}
	else
	{
		old_a_head->prev = (*stackB)->prev;
		old_a_head->next = *stackB;
		(*stackB)->prev->next = old_a_head;
		(*stackB)->prev = old_a_head;
	}
	*stackB = old_a_head;
	ft_printf("pb\n");
}
