/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/27 19:05:43 by fras          #+#    #+#                 */
/*   Updated: 2023/05/27 20:44:39 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation_call(t_command command)
{
	if (command == sa)
		swap_a(stackA);
	if (command == sb)
		swap_b(stackB);
	if (command == ss)
		swap_swap_ab(stackA, stackB);
	if (command == pa)
		push_a(stackA, stackB);
	if (command == pb)
		push_b(stackA, stackB);
	if (command == ra)
		rotate_a(stackA);
	if (command == rb)
		rotate_b(stackB);
	if (command == rr)
		rotate_rotate_ab(stackA, stackB);
	if (command == rra)
		rev_rotate_a(stackA);
	if (command == rrb)
		rev_rotate_b(stackB);
	if (command == rrr)
		rev_rotate_rotate_ab(stackA, stackB);
	return (write_operation_to_stdout(command));
}

void	write_operation_to_stdout(t_command command)
{
	if (command == sa)
		ft_printf("sa\n");
	if (command == sb)
		ft_printf("sb\n");
	if (command == ss)
		ft_printf("ss\n");
	if (command == pa)
		ft_printf("pa\n");
	if (command == pb)
		ft_printf("pb\n");
	if (command == ra)
		ft_printf("ra\n");
	if (command == rb)
		ft_printf("rb\n");
	if (command == rr)
		ft_printf("rr\n");
	if (command == rra)
		ft_printf("rra\n");
	if (command == rrb)
		ft_printf("rrb\n");
	if (command == rrr)
		ft_printf("rrr\n");
}
