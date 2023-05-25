/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operationsPushSwap.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 10:14:58 by fras          #+#    #+#                 */
/*   Updated: 2023/05/25 12:58:19 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_data **stackA)
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
	ft_printf("sa\n");
}

void	swap_b(t_data **stackB)
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
	ft_printf("sa\n");
}

void	swap_swap_ab(t_data **stackA, t_data **stackB)
{
	swap_a(stackA);
	swap_b(stackB);
	ft_printf("ss\n");
}

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
