/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/27 19:05:43 by fras          #+#    #+#                 */
/*   Updated: 2023/06/08 13:42:58 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	print_ops(t_cmd operation)
{
	if (operation == sa)
		write(STDOUT_FILENO, "sa\n", 3);
	if (operation == sb)
		write(STDOUT_FILENO, "sb\n", 3);
	if (operation == ss)
		write(STDOUT_FILENO, "ss\n", 3);
	if (operation == pa)
		write(STDOUT_FILENO, "pa\n", 3);
	if (operation == pb)
		write(STDOUT_FILENO, "pb\n", 3);
	if (operation == ra)
		write(STDOUT_FILENO, "ra\n", 3);
	if (operation == rb)
		write(STDOUT_FILENO, "rb\n", 3);
	if (operation == rr)
		write(STDOUT_FILENO, "rr\n", 3);
	if (operation == rra)
		write(STDOUT_FILENO, "rra\n", 4);
	if (operation == rrb)
		write(STDOUT_FILENO, "rrb\n", 4);
	if (operation == rrr)
		write(STDOUT_FILENO, "rrr\n", 4);
	return(operation);
}
