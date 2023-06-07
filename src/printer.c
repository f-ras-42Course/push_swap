/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/27 19:05:43 by fras          #+#    #+#                 */
/*   Updated: 2023/06/07 23:37:20 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	print_ops(t_cmd operation)
{
	if (operation == sa)
		write(1, "sa\n", 3);
	if (operation == sb)
		write(1, "sb\n", 3);
	if (operation == ss)
		write(1, "ss\n", 3);
	if (operation == pa)
		write(1, "pa\n", 3);
	if (operation == pb)
		write(1, "pb\n", 3);
	if (operation == ra)
		write(1, "ra\n", 3);
	if (operation == rb)
		write(1, "rb\n", 3);
	if (operation == rr)
		write(1, "rr\n", 3);
	if (operation == rra)
		write(1, "rra\n", 4);
	if (operation == rrb)
		write(1, "rrb\n", 4);
	if (operation == rrr)
		write(1, "rrr\n", 4);
	return(operation);
}
