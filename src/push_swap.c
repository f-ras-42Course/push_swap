/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 10:10:25 by fras          #+#    #+#                 */
/*   Updated: 2023/05/25 10:15:46 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(t_data *data);

void	push_swap(t_data *start_input)
{
	t_data	*stackA;
	t_data	*stackB;
	// size_t	list_size;

	stackA = start_input;
	stackB = NULL;
	// list_size = circular_list_size(start_input);
	test(stackA);
	test(stackB);
	printf("\n\nPUSHERDEPUSH B\n\n");
	push_b(&stackA, &stackB);
	printf("\n\nSTACK A:\n\n");
	test(stackA);
	printf("\n\nSTACK B:\n\n");
	test(stackB);
	printf("\n\nPUSHERDEPUSH B\n\n");
	push_b(&stackA, &stackB);
	printf("\n\nSTACK A:\n\n");
	test(stackA);
	printf("\n\nSTACK B:\n\n");
	test(stackB);
	printf("\n\nPUSHERDEPUSH B\n\n");
	push_b(&stackA, &stackB);
	printf("\n\nSTACK A:\n\n");
	test(stackA);
	printf("\n\nSTACK B:\n\n");
	test(stackB);
	printf("\n\n\n");
	printf("\n\nPUSHERDEPUSH A\n\n");
	push_a(&stackA, &stackB);
	printf("\n\nSTACK A:\n\n");
	test(stackA);
	printf("\n\nSTACK B:\n\n");
	test(stackB);
	printf("\n\nPUSHERDEPUSH A\n\n");
	push_a(&stackA, &stackB);
	printf("\n\nSTACK A:\n\n");
	test(stackA);
	printf("\n\nSTACK B:\n\n");
	test(stackB);
	printf("\n\nPUSHERDEPUSH A\n\n");
	push_a(&stackA, &stackB);
	printf("\n\nSTACK A:\n\n");
	test(stackA);
	printf("\n\nSTACK B:\n\n");
	test(stackB);
	// printf("\n\nPUSHERDEPUSH A\n\n");
	// push_a(&stackA, &stackB);
	// test(stackA);
	// test(stackB);
	// printf("\n\nPUSHERDEPUSH A\n\n");
	// push_a(&stackA, &stackB);
	// test(stackA);
	// test(stackB);
// 	if (list_size <= 3)
// 		xx1sort;
// 	else if (list_size <= 5)
// 		xx2Sort;
// 	else
// 		RadixSort;
// }
}