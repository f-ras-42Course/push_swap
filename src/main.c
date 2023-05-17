/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 21:20:13 by fras          #+#    #+#                 */
/*   Updated: 2023/05/17 04:52:10 by ferryras      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void test (t_data *data);

int	main(int argc, char *argv[])
{
	t_data *data;

	if (argc == 1)
		error_exit();
	validate_formatting(argv);
	data = collect_data(argv);
	validate_no_duplicate_num(data);
	complete_normalized_values(data, circular_list_size(data));
	// push_swap(data);
	
	test(data); // - temp for development
	return (0);
}


// temporary tester:
#include <stdio.h>
void test (t_data *data)
{
	t_data *ptr;
	int i;

	printf("\nINPUT VALUES:\n");
 	i = 0;
	ptr = data;
 	printf("[HEAD %d] = %d, ", i++, ptr->input_value);
 	ptr = ptr->next;
 	while (ptr != data)
 	{
 		printf("[%d] = %d, ", i++, ptr->input_value);
 		ptr = ptr->next;
 	}
 	printf("\n[HEAD check] = %d\n", ptr->input_value);
	
	printf("\nNORMALIZED VALUES:\n");
	i = 0;
	ptr = data;
 	printf("[HEAD %d] = %d, ", i++, ptr->normalized_value);
 	ptr = ptr->next;
 	while (ptr != data)
 	{
 		printf("[%d] = %d, ", i++, ptr->normalized_value);
 		ptr = ptr->next;
 	}
	printf("\n\n");
 	// Output:
 	// ./push_swap 4463 24 544 344
 	// [0] = 4463, [1] = 24, [2] = 544, [3] = 344, [4] = 4463, 
	// push_swap(data);
}