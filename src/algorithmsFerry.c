/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithmsFerry.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 15:01:02 by fras          #+#    #+#                 */
/*   Updated: 2023/06/07 16:26:42 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ferry_sort(t_data **stackA, t_data **stackB, size_t data_size)
{
	if (data_size == 4)
		ferry_sort_sz4(stackA, stackB);
}

void	ferry_sort_sz4(t_data **stackA, t_data **stackB)
{
	int lowest_not_on_top;

	lowest_not_on_top = 0;
	if (locate_low_normal_or_rev(stackA, 0))
		while ((*stackA)->normalized_value != 0 && ++lowest_not_on_top)
			print_ops(rotate_a(stackA));
	else
		while ((*stackA)->normalized_value != 0 && ++lowest_not_on_top)
			print_ops(rev_rotate_a(stackA));
	if (lowest_not_on_top)
		print_ops(push_b(stackA, stackB));
	small_sort(stackA, 3, 1);
	if (lowest_not_on_top)
		print_ops(push_a(stackA, stackB));
}

int	locate_low_normal_or_rev(t_data **stackA, int num)
{
	t_data	*ptr;
	int		next_check;
	int		prev_check;
	
	next_check = 0;
	prev_check = 0;
	ptr = *stackA;
	while (ptr->normalized_value != num && ++next_check)
		ptr = ptr->next;
	ptr = (*stackA)->prev;
	while (ptr->normalized_value != num && ++prev_check)
	{
		printf("check prev\n");
		ptr = ptr->prev;
	}
	printf("\n\nnext value: %d || prev value: %d\n\n", next_check, prev_check);
	if (next_check <= (prev_check + 1))
		return (1);
	return (0);
}
