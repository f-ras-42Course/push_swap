/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operationsRotate.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 10:31:59 by fras          #+#    #+#                 */
/*   Updated: 2023/05/28 02:00:36 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	rotate_a (t_data **stackA)
{
	if (!*stackA || (*stackA)->next == *stackA)
		return (none);
	*stackA = (*stackA)->next;
	return(ra);
}

t_cmd	rotate_b (t_data **stackB)
{
	if (!*stackB || (*stackB)->next == *stackB)
		return (none);
	*stackB = (*stackB)->next;
	return(rb);
}

// void	rotate_rotate_ab(t_data **stackA, t_data **stackB)
// {
// 	ft_printf("rr\n");
// }
