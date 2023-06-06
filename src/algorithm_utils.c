//insert header

#include "push_swap.h"

void	push_all_to_stackA(t_data **stackA, t_data **stackB)
{
	t_cmd command;

	command = print_ops(push_a(stackA, stackB));
	while(command != none)
		command = print_ops(push_a(stackA, stackB));
}

int	get_highest_bit_length(t_data *stackA)
{
	t_data	*ptr;
	int		highest_value;
	int		bit_length;

	highest_value = stackA->normalized_value;
	ptr = stackA->next;
	while (ptr != stackA)
	{
		if (highest_value <= ptr->normalized_value)
			highest_value = ptr->normalized_value;
		ptr = ptr->next;
	}
	bit_length = 0;
	while (highest_value)
	{
		highest_value /= 2;
		bit_length++;
	}
	return (bit_length);
}
