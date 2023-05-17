/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 10:10:25 by fras          #+#    #+#                 */
/*   Updated: 2023/05/17 17:52:13 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_data *start_input)
{
	t_data	*stackA;
	t_data	*stackB;
	size_t	list_size;

	stackA = start_input;
	list_size = circular_list_size(start_input);
	if (list_size <= 3)
		xx1sort;
	else if (list_size <= 5)
		xx2Sort;
	else
		RadixSort;
}