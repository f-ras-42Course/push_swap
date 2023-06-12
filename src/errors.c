/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 18:05:20 by fras          #+#    #+#                 */
/*   Updated: 2023/06/12 21:49:44 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(STDERR_FILENO, "Error\n", 7);
	exit(EXIT_FAILURE);
}

void	malloc_failure_exit(t_data *data)
{
	freeing_data(data);
	write(STDERR_FILENO, "PROGRAM ERROR: malloc failed.\n", 31);
	exit(EXIT_FAILURE);
}

void	read_failure_exit(void)
{
	write(STDERR_FILENO, "PROGRAM ERROR: read function failed.\n", 38);
	exit(EXIT_FAILURE);
}
