/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operationsPushSwap.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 10:14:58 by fras          #+#    #+#                 */
/*   Updated: 2023/05/25 10:14:52 by fras          ########   odam.nl         */
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

void	push_a(t_data **stackA,	t_data **stackB)
{
	t_data	*OLDheadB;

	if (!*stackB)
		return;
	OLDheadB = *stackB;
	*stackB = (*stackB)->next;
	if (*stackB == OLDheadB)
		*stackB = NULL;
	else
	{
		(*stackB)->prev = OLDheadB->prev;
		(*stackB)->prev->next = *stackB;
	}
	if (!*stackA)
	{
		OLDheadB->prev = OLDheadB;
		OLDheadB->next = OLDheadB;
	}
	else
	{
		OLDheadB->prev = (*stackA)->prev;
		OLDheadB->next = *stackA;
		(*stackA)->prev->next = OLDheadB;
		(*stackA)->prev = OLDheadB;
	}
	*stackA = OLDheadB;
	ft_printf("pa\n");
}


void	push_b(t_data **stackA,	t_data **stackB)
{
	t_data	*OLDheadA;

	if (!*stackA)
		return;
	OLDheadA = *stackA;
	*stackA = (*stackA)->next;
	if (*stackA == OLDheadA)
		*stackA = NULL;
	else
	{
		(*stackA)->prev = OLDheadA->prev;
		(*stackA)->prev->next = *stackA;
	}
	if (!*stackB)
	{
		OLDheadA->prev = OLDheadA;
		OLDheadA->next = OLDheadA;
	}
	else
	{
		OLDheadA->prev = (*stackB)->prev;
		OLDheadA->next = *stackB;
		(*stackB)->prev->next = OLDheadA;
		(*stackB)->prev = OLDheadA;
	}
	*stackB = OLDheadA;
	ft_printf("pb\n");
}
