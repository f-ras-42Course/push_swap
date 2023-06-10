/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 01:21:18 by fras          #+#    #+#                 */
/*   Updated: 2023/06/10 13:15:34 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker(t_data *data_input)
{
	t_data *stack_a;
	t_data *stack_b;

	stack_a = data_input;
	stack_b = NULL;
	sort_stack_from_stdin(&stack_a, &stack_b);
	print_result(&stack_a, &stack_b);
}

void	print_result(t_data **stackA, t_data **stackB)
{
	int	check;

	check = 0;
	while ((*stackA)->normalized_value == check && ++check)
		*stackA = (*stackA)->next;
	if((*stackA)->normalized_value == 0 && !*stackB)
		write(STDOUT_FILENO, "OK\n", 4);
	else
		write(STDOUT_FILENO, "KO\n", 4);
}

void	sort_stack_from_stdin(t_data **stackA, t_data **stackB)
{
	char *line;

	while (1)
	{
		line = get_next_line_stdin();
		make_operations(get_operations(line), stackA, stackB);
		if(!line)
			break;
		free(line);
	}
	free(line);
}

t_cmd	get_operations(char *str)
{
	if (!str)
		return (none);
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
	return(invalid);
}

void	make_operations(t_cmd command, t_data **stackA, t_data **stackB)
{
	if (command == invalid)
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
