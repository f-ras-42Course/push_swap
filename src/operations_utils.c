/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_operations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 16:14:10 by fras          #+#    #+#                 */
/*   Updated: 2023/05/27 19:06:15 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*remove_head_from_stack(t_data **stack)
{
	t_data *head;

	head = *stack;
	*stack = (*stack)->next;
	if (head == *stack)
		*stack = NULL;
	else
	{
		(*stack)->prev = head->prev;
		(*stack)->prev->next = *stack;
	}
	return (head);
}

void	initialize_stack_from_head(t_data **stack, t_data *head)
{
	head->prev = head;
	head->next = head;
	*stack = head;
}

void	add_head_to_stack(t_data **stack, t_data **head)
{
	(*head)->prev = (*stack)->prev;
	(*head)->next = *stack;
	(*stack)->prev->next = *head;
	(*stack)->prev = *head;
	*stack = *head;
}
