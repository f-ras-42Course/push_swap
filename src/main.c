/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 21:20:13 by fras          #+#    #+#                 */
/*   Updated: 2023/05/04 05:40:22 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list *data;

	if (argc == 1)
		error_exit();
	validate_formatting(argc, argv);
	data = collect_input(argc, argv);
}
