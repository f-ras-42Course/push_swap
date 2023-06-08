/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PS_get_next_line_errors.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 15:52:15 by fras          #+#    #+#                 */
/*   Updated: 2023/06/08 16:03:42 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	EXIT_MALLOC_FAILURE(void)
{
	write(STDERR_FILENO, "PROGRAM ERROR: malloc failed.\n", 7);
	exit(EXIT_FAILURE);
}

