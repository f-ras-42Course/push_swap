/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithms.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 18:26:53 by fras          #+#    #+#                 */
/*   Updated: 2023/06/07 14:45:48 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_data **stackA, size_t data_size, int lowest)
{
	int second_value;

	second_value = (*stackA)->next->normalized_value;
	if (data_size == 2 && (*stackA)->normalized_value != lowest)
		print_ops(swap_a(stackA));
	if (data_size == 3)
	{
		if ((*stackA)->normalized_value == lowest && second_value == lowest+2)
		{
			print_ops(rotate_a(stackA));
			print_ops(swap_a(stackA));
			print_ops(rev_rotate_a(stackA));
		}
		if ((*stackA)->normalized_value == lowest+1 && second_value == lowest)
			print_ops(swap_a(stackA));
		if ((*stackA)->normalized_value == lowest+1 && second_value == lowest+2)
			print_ops(rev_rotate_a(stackA));
		if ((*stackA)->normalized_value == lowest+2 && second_value == lowest)
			print_ops(rotate_a(stackA));
		if ((*stackA)->normalized_value == lowest+2 && second_value == lowest+1)
		{
			print_ops(swap_a(stackA));
			print_ops(rev_rotate_a(stackA));
		}
	}
}

void	ferry_sort(t_data **stackA, t_data **stackB, size_t data_size)
{

}

void	small_sort_reverseA(t_data **stackA, size_t data_size, int highest)
{
	int	second_value;

	second_value = (*stackA)->next->normalized_value;
	if (data_size == 2 && (*stackA)->normalized_value != highest)
		print_ops(swap_a(stackA));
	if (data_size == 3)
	{
		if ((*stackA)->normalized_value == highest && second_value == highest-2)
		{
			print_ops(rotate_a(stackA));
			print_ops(swap_a(stackA));
			print_ops(rev_rotate_a(stackA));
		}
		if ((*stackA)->normalized_value == highest-1 && second_value == highest)
			print_ops(swap_a(stackA));
		if ((*stackA)->normalized_value == highest-1 && second_value==highest-2)
			print_ops(rev_rotate_a(stackA));
		if ((*stackA)->normalized_value == highest-2 && second_value == highest)
			print_ops(rotate_a(stackA));
		if ((*stackA)->normalized_value == highest-2 && second_value==highest-1)
		{
			print_ops(swap_a(stackA));
			print_ops(rev_rotate_a(stackA));
		}
	}
}

void	small_sort_reverseB(t_data **stackB, size_t data_size, int highest)
{
	int	second_value;

	second_value = (*stackB)->next->normalized_value;
	if (data_size == 2 && (*stackB)->normalized_value != highest)
		print_ops(swap_b(stackB));
	if (data_size == 3)
	{
		if ((*stackB)->normalized_value == highest && second_value == highest-2)
		{
			print_ops(rotate_b(stackB));
			print_ops(swap_b(stackB));
			print_ops(rev_rotate_b(stackB));
		}
		if ((*stackB)->normalized_value == highest-1 && second_value == highest)
			print_ops(swap_b(stackB));
		if ((*stackB)->normalized_value == highest-1 && second_value==highest-2)
			print_ops(rev_rotate_b(stackB));
		if ((*stackB)->normalized_value == highest-2 && second_value == highest)
			print_ops(rotate_b(stackB));
		if ((*stackB)->normalized_value == highest-2 && second_value==highest-1)
		{
			print_ops(swap_b(stackB));
			print_ops(rev_rotate_b(stackB));
		}
	}
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
