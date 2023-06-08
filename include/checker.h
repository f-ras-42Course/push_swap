/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 00:46:16 by fras          #+#    #+#                 */
/*   Updated: 2023/06/08 18:08:02 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

typedef struct s_stdin_commands
{
	t_cmd			command;
	struct s_stdin_commands *next;
}	s_stdin_commands;

void	checker(t_data *data_input, size_t data_size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif