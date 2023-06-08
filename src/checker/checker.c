/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 01:21:18 by fras          #+#    #+#                 */
/*   Updated: 2023/06/08 16:00:18 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker(t_data *data_input, size_t data_size)
{
	t_stdin_commands	*commands;

	
}

(void)
{

}

void	sort_data(t_cmd operation, t_data **stackA, t_data **stackB)
{
	if (operation == sa)
		swap_a(*stackA);
	if (operation == sb)
		swap_b(*stackB);
	if (operation == ss)
		swap_swap_ab(*stackA, *stackB);
	if (operation == pa)
		push_a(*stackA, *stackB);
	if (operation == pb)
		push_b(*stackA, *stackB);
	if (operation == ra)
		rotate_a(*stackA);
	if (operation == rb)
		rotate_b(*stackB);
	if (operation == rr)
		rotate_rotate_ab(*stackA, *stackB);
	if (operation == rra)
		rev_rotate_a(*stackA);
	if (operation == rrb)
		rev_rotate_b(*stackB);
	if (operation == rrr)
		rev_rotate_rotate_ab(*stackA, *stackB);
	return(operation);
}