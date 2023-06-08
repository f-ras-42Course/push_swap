/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 01:21:18 by fras          #+#    #+#                 */
/*   Updated: 2023/06/08 21:50:45 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void test(t_data *data);
#include <stdio.h>

void	checker(t_data *data_input)
{
	t_data *stack_a;
	t_data *stack_b;

	stack_a = data_input;
	stack_b = NULL;
	printf("INITIAL DATA SETUP (STACK A):\n\n");
	test(stack_a);
	sort_from_stdin_commands(&stack_a, &stack_b);
	printf("EOF reached\n");
}

void	sort_from_stdin_commands(t_data **stackA, t_data **stackB)
{
	char *line;

	printf("Time to start sorting...\n\n");
	while (1)
	{
		line = get_next_line_stdin();
		make_operations(get_operations(line), stackA, stackB);
		printf("Used the following command: %s\n\n", line);
		printf("Result StackA:\n");
		test(*stackA);
		printf("Result StackB:\n");
		test(*stackB);
		if(!line)
			break;
		free(line);
	}
	free(line);
}

t_cmd	get_operations(char *str)
{
	if (!ft_strncmp("sa\n", str, 4))
		return(sa);
	if (!ft_strncmp("sb\n", str, 4))
		return(sb);
	if (!ft_strncmp("ss\n", str, 4))
		return(ss);
	if (!ft_strncmp("pa\n", str, 4))
		return(pa);
	if (!ft_strncmp("pb\n", str, 4))
		return(pb);
	if (!ft_strncmp("ra\n", str, 4))
		return(ra);
	if (!ft_strncmp("rb\n", str, 4))
		return(rb);
	if (!ft_strncmp("rr\n", str, 4))
		return(rr);
	if (!ft_strncmp("rra\n", str, 5))
		return(rra);
	if (!ft_strncmp("rrb\n", str, 5))
		return(rrb);
	if (!ft_strncmp("rrr\n", str, 5))
		return(rrr);
	return(none);
}

void	make_operations(t_cmd command, t_data **stackA, t_data **stackB)
{
	if (command == none)
		error_exit();
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
}
