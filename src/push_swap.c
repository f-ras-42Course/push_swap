/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 10:10:25 by fras          #+#    #+#                 */
/*   Updated: 2023/06/05 22:42:58 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(t_data *data);
void	test2(t_data *data);


void	push_swap(t_data *start_input)
{
	t_data	*stack_a;
	t_data	*stack_b;

	stack_a = start_input;
	stack_b = NULL;
	test(stack_a);
	test(stack_b);
	printf("\n\nREDIX_Sort\n\n");
	redix_sort(&stack_a, &stack_b);
	test(stack_a);
	test(stack_b);
// 	if (list_size <= 3)
// 		xx1sort;
// 	else if (list_size <= 5)
// 		xx2Sort;
// 	else
// 		RadixSort;
// }
}
