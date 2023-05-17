/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operationsPushSwap.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 10:14:58 by fras          #+#    #+#                 */
/*   Updated: 2023/05/17 17:51:57 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a (t_data **stackA)
{
	t_data *temp_ptr;

	temp_ptr = *stackA->next;
	temp_ptr->prev = *stackA->prev;
	*stackA->prev = temp_ptr;
	*stackA->next = temp_ptr->next;

	// temp_ptr = *stackA;
	// *stackA = stackA->next;
	// stackA->next = temp_ptr;
	ft_printf("sa\n");
}

void	swap_b (t_data **stackB)
{
	ft_printf("sb\n");
}

void	swap_swap_ab(t_data **stackA, t_data **stackB)
{
	ft_printf("ss\n");
}

void	push_a (t_data **stackA, t_data **stackB)
{
	ft_printf("pa\n");
}

void	push_b (t_data **stackA, t_data **stackB)
{
	ft_printf("pb\n");
}
