/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithms.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 18:26:53 by fras          #+#    #+#                 */
/*   Updated: 2023/06/07 08:02:54 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_data **stackA, size_t data_size)
{
	t_data *secondA;

	secondA = (*stackA)->next;
	if (data_size == 2 && (*stackA)->normalized_value == 1)
		print_ops(swap_a(stackA));
	if (data_size == 3)
	{
		if ((*stackA)->normalized_value == 0 && secondA->normalized_value == 2)
		{
			print_ops(rotate_a(stackA));
			print_ops(swap_a(stackA));
			print_ops(rev_rotate_a(stackA));
		}
		if ((*stackA)->normalized_value == 1 && secondA->normalized_value == 0)
			print_ops(swap_a(stackA));
		if ((*stackA)->normalized_value == 1 && secondA->normalized_value == 2)
			print_ops(rev_rotate_a(stackA));
		if ((*stackA)->normalized_value == 2 && secondA->normalized_value == 0)
			print_ops(rotate_a(stackA));
		if ((*stackA)->normalized_value == 2 && secondA->normalized_value == 1)
		{
			print_ops(swap_a(stackA));
			print_ops(rev_rotate_a(stackA));
		}
	}
}



void	small_sort_reverse(t_data **stack, size_t data_size)
{
	t_data *secondA;

	secondA = (*stackA)->next;
	if (data_size == 2 && (*stackA)->normalized_value == 1)
		print_ops(swap_a(stackA));
	if (data_size == 3)
	{
		if ((*stackA)->normalized_value == 0 && secondA->normalized_value == 2)
		{
			print_ops(rotate_a(stackA));
			print_ops(swap_a(stackA));
			print_ops(rev_rotate_a(stackA));
		}
		if ((*stackA)->normalized_value == 1 && secondA->normalized_value == 0)
			print_ops(swap_a(stackA));
		if ((*stackA)->normalized_value == 1 && secondA->normalized_value == 2)
			print_ops(rev_rotate_a(stackA));
		if ((*stackA)->normalized_value == 2 && secondA->normalized_value == 0)
			print_ops(rotate_a(stackA));
		if ((*stackA)->normalized_value == 2 && secondA->normalized_value == 1)
		{
			print_ops(swap_a(stackA));
			print_ops(rev_rotate_a(stackA));
		}
	}
}

void	ferry_sort(t_data **stackA, t_data **stackB, size_t data_size)
{

}

void	redix_sort(t_data **stackA, t_data **stackB, size_t data_size)
{
	int		bit_length;
	int		bit_check;
	size_t	i;
	
	i = 0;
	bit_check = 1;
	bit_length = get_highest_bit_length(*stackA);
	while (bit_length)
	{
		if (((*stackA)->normalized_value &bit_check) == 0)
			print_ops(push_b(stackA, stackB));
		else
			print_ops(rotate_a(stackA));
		i++;
		if (i == data_size)
		{
			bit_check *= 2;
			push_all_to_stackA(stackA, stackB);
			i = 0;
			bit_length--;
		}
	}
}
