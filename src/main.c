/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 21:20:13 by fras          #+#    #+#                 */
/*   Updated: 2023/06/13 16:05:14 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"
#include <stdio.h>

void	leaks_check(void)
{
	system("leaks push_swap");
}

int	main(int argc, char *argv[])
{
	t_data	*data;
	// size_t	data_size;

	atexit(leaks_check);
	if (argc == 1)
		return (0);
	validate_formatting(argv);
	data = collect_data(argv);
	// validate_no_duplicate_num(data);
	// data_size = circular_list_size(data);
	// insert_normalized_values(data, data_size);
	// if (!ft_strncmp("./checker", argv[0], 10))
	// 	checker(data);
	// else
		// push_swap(data, data_size);
	freeing_data(data);
	return (0);
}
