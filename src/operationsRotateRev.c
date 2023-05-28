/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operationsRotateRev.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 10:33:16 by fras          #+#    #+#                 */
/*   Updated: 2023/05/28 02:28:01 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	rev_rotate_a (t_data **stackA)
{
	if (!*stackA || (*stackA)->next == *stackA)
		return (none);
	*stackA = (*stackA)->prev;
	return(rra);
}

t_cmd	rev_rotate_b (t_data **stackB)
{
	if (!*stackB || (*stackB)->next == *stackB)
		return (none);
	*stackB = (*stackB)->prev;
	return(rrb);
}

t_cmd	rev_rotate_rotate_ab(t_data **stackA, t_data **stackB)
{
	if ((!*stackB || (*stackB)->next == *stackB) 
		&& (!*stackA || (*stackA)->next == *stackA))
		return (none);
	return(rrr);
}
