/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 00:46:16 by fras          #+#    #+#                 */
/*   Updated: 2023/06/17 20:27:21 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	checker(t_data *data_input);
void	sort_stack_from_stdin(t_data **stackA, t_data **stackB);
char	*get_next_line_stdin(void);
t_cmd	get_operations(char *str);
void	make_operations(t_cmd command, t_data **stackA, t_data **stackB);
void	print_result(t_data **stackA, t_data **stackB);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	error_exit_invalid_operation(t_data **stackA, t_data **stackB);

#endif