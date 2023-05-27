/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operationsRotate.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 10:31:59 by fras          #+#    #+#                 */
/*   Updated: 2023/05/27 19:00:26 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a (t_data **stackA)
{
	if (!*stackA || (*stackA)->next == *stackA)
		return ;
	*stackA = (*stackA)->next;
	ft_printf("ra\n");
}

void	rotate_b (t_data **stackB)
{
	if (!*stackB || (*stackB)->next == *stackB)
		return ;
	*stackB = (*stackB)->next;
	ft_printf("rb\n");
}

// void	rotate_rotate_ab(t_data **stackA, t_data **stackB)
// {
// 	ft_printf("rr\n");
// }
