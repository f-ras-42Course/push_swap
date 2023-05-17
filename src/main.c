/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 21:20:13 by fras          #+#    #+#                 */
/*   Updated: 2023/05/17 03:15:32 by ferryras      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	// t_data **stackA;
	// t_data **stackB;
	t_data *data;
	t_data *ptr;
	int i;

	i = 0;
	if (argc == 1)
		error_exit();
	validate_formatting(argv);
	data = collect_data(argv);
	validate_no_duplicates(data);

	// ptr = data;
	// printf("[%d] = %d, ", i++, ptr->input_value);
	// ptr = ptr->next;
	// while (ptr != data)
	// {
	// 	printf("[%d] = %d, ", i++, ptr->input_value);
	// 	ptr = ptr->next;
	// }
	// printf("[%d] = %d, ", i++, ptr->input_value);
	// Output:
	// ./push_swap 4463 24 544 344
	//[0] = 4463, [1] = 24, [2] = 544, [3] = 344, [4] = 4463, 
	return (0);
}
