/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 21:20:13 by fras          #+#    #+#                 */
/*   Updated: 2023/05/17 18:51:00 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(t_data *data);

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc == 1)
		error_exit();
	validate_formatting(argv);
	data = collect_data(argv);
	validate_no_duplicate_num(data);
	insert_normalized_values(data, circular_list_size(data));
	push_swap(data);
	
	// test(data); // - temp for development
	return (0);
}
