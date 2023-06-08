/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PS_get_next_line_errors.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 15:52:15 by fras          #+#    #+#                 */
/*   Updated: 2023/06/08 17:12:08 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	malloc_failure_exit(void)
{
	write(STDERR_FILENO, "PROGRAM ERROR: malloc failed.\n", 31);
	exit(EXIT_FAILURE);
}
