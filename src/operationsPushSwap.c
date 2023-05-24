/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operationsPushSwap.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 10:14:58 by fras          #+#    #+#                 */
/*   Updated: 2023/05/24 20:25:13 by fras          ########   odam.nl         */
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
		return;
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
		return;
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

void	push_a (t_data **stackA, t_data **stackB)
{
	t_data	*headB;

	if (!*stackB)
		return;
	headB = *stackB;
	if (headB->next != headB)
	{
		headB->next->prev = headB->prev;
		if (headB->next->next == headB)
			headB->next->next = headB->next;
		*stackB = headB->next;
	}
	else
		*stackB = NULL;
	if (*stackA)
	{
		headB->prev = (*stackA)->prev;
		headB->next = *stackA;
		(*stackA)->prev->next = headB;
		(*stackA)->prev = headB;
	}
	else
	{
		headB->prev = headB;
		headB->next = headB;
	}
	*stackA = headB;
	ft_printf("pa\n");
}

void	push_b (t_data **stackA, t_data **stackB)
{
	t_data	*headA;

	if (!*stackA)
		return;
	headA = *stackA;
	if (headA->next == headA)
		*stackA = NULL;
	else
	{
		headA->next->prev = headA->prev;
		headA->prev->next = headA->next;
		*stackA = headA->next;
	}
	if (!*stackB)
	{
		headA->prev = headA;
		headA->next = headA;
	}
	else
	{
		headA->prev = (*stackB)->prev;
		headA->next = *stackB;
		(*stackB)->prev->next = headA;
		(*stackB)->prev = headA;
	}
	*stackB = headA;
	ft_printf("pb\n");
}
