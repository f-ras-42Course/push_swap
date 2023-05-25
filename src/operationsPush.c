/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operationsPush.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 14:42:11 by fras          #+#    #+#                 */
/*   Updated: 2023/05/25 16:17:43 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_data **stackA,	t_data **stackB)
{
	t_data	*old_b_head;

	if (!*stackB)
		return ;
	old_b_head = remove_head_from_stack(stackB);
	if (!*stackA)
		initialize_stack_from_head(stackA, old_b_head);
	else
		add_head_to_stack(stackA, &old_b_head);
	ft_printf("pa\n");
}

void	push_b(t_data **stackA,	t_data **stackB)
{
	t_data	*old_a_head;

	if (!*stackA)
		return ;
	old_a_head = remove_head_from_stack(stackA);
	if (!*stackB)
		initialize_stack_from_head(stackB, old_a_head);
	else
		add_head_to_stack(stackB, &old_a_head);
	ft_printf("pb\n");
}
