/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 10:10:25 by fras          #+#    #+#                 */
/*   Updated: 2023/05/27 18:58:41 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(t_data *data);

void	push_swap(t_data *start_input)
{
	t_data	*stack_a;
	t_data	*stack_b;
	// size_t	list_size;

	stack_a = start_input;
	stack_b = NULL;
	// list_size = circular_list_size(start_input);
	test(stack_a);
	test(stack_b);
	printf("\n\nPUSHERDEPUSH B\n\n");
	push_b(&stack_a, &stack_b);
	printf("\n\nSTACK A:\n\n");
	test(stack_a);
	printf("\n\nSTACK B:\n\n");
	test(stack_b);
	printf("\n\nPUSHERDEPUSH B\n\n");
	push_b(&stack_a, &stack_b);
	printf("\n\nSTACK A:\n\n");
	test(stack_a);
	printf("\n\nSTACK B:\n\n");
	test(stack_b);
	printf("\n\nPUSHERDEPUSH B\n\n");
	push_b(&stack_a, &stack_b);
	printf("\n\nSTACK A:\n\n");
	test(stack_a);
	printf("\n\nSTACK B:\n\n");
	test(stack_b);
	printf("\n\n\n");
	printf("\n\nPUSHERDEPUSH A\n\n");
	push_a(&stack_a, &stack_b);
	printf("\n\nSTACK A:\n\n");
	test(stack_a);
	printf("\n\nSTACK B:\n\n");
	test(stack_b);
	printf("\n\nPUSHERDEPUSH A\n\n");
	push_a(&stack_a, &stack_b);
	printf("\n\nSTACK A:\n\n");
	test(stack_a);
	printf("\n\nSTACK B:\n\n");
	test(stack_b);
	printf("\n\nPUSHERDEPUSH A\n\n");
	push_a(&stack_a, &stack_b);
	printf("\n\nSTACK A:\n\n");
	test(stack_a);
	printf("\n\nSTACK B:\n\n");
	test(stack_b);
	printf("\n\nSWAPPERDESWAP B\n\n");
	swap_b(&stack_b);
	printf("\n\nRotate A\n\n");
	rotate_a(&stack_a);
	printf("\n\nSTACK A:\n\n");
	test(stack_a);
	printf("\n\nSTACK B:\n\n");
	test(stack_b);
// 	if (list_size <= 3)
// 		xx1sort;
// 	else if (list_size <= 5)
// 		xx2Sort;
// 	else
// 		RadixSort;
// }
}