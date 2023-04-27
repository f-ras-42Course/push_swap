/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 21:53:14 by fras          #+#    #+#                 */
/*   Updated: 2023/04/27 03:18:44 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		validate_formatting(int argc, char *argv[]);
int		collect_input(int argc, char *argv[]);
void	validate_no_duplicates(t_list *data);
void	error_exit(void);
t_list	lst_add_new_value(int value);