/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 21:20:13 by fras          #+#    #+#                 */
/*   Updated: 2023/06/08 00:19:27 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	size_t	data_size;

	if (argc == 1)
		return(0);
	validate_formatting(argv);
	data = collect_data(argv);
	validate_no_duplicate_num(data);
	data_size = circular_list_size(data);
	insert_normalized_values(data, data_size);
	push_swap(data, data_size);
	return (0);
}
