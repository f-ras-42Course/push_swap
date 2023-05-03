/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 21:53:14 by fras          #+#    #+#                 */
/*   Updated: 2023/05/04 01:58:00 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

void	validate_formatting(int argc, char *argv[]);
t_list	*collect_input(int argc, char *argv[]);
void	validate_no_duplicates(t_list *data);
void	error_exit(void);
t_list	*lst_add_new_value(int value);
void	lst_malloc_protect(t_list *first_node);
int		int_only(long input);