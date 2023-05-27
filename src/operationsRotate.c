/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operationsRotate.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 10:31:59 by fras          #+#    #+#                 */
/*   Updated: 2023/05/27 16:55:03 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a (t_data **stackA)
{
	t_data	*tail_a;

	tail_a = (*stackA)->prev;
	(*stackA)->prev = tail_a->prev;
	tail_a->next = (*stackA)->next;
	tail_a->prev = *stackA;
	(*stackA)->next = tail_a;
	*stackA = tail_a;
	ft_printf("ra\n");
}

void	rotate_b (t_data **stackB)
{
	t_data	*tail_b;

	tail_b = (*stackB)->prev;
	(*stackB)->prev = tail_b->prev;
	(*stackB)->next = tail_b;
	tail_b->next = (*stackB)->next;
	tail_b->prev = *stackB;
	*stackB = tail_b;
	ft_printf("rb\n");
}

// void	rotate_rotate_ab(t_data **stackA, t_data **stackB)
// {
// 	ft_printf("rr\n");
// }
