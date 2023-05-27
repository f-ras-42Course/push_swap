/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 21:53:14 by fras          #+#    #+#                 */
/*   Updated: 2023/05/28 01:51:44 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"
# include "ft_printf.h"
# include "libft-extended.h"

typedef struct s_data
{
	struct s_data	*prev;				
	int				input_value;
	int				normalized_value;
	struct s_data	*next;
}	t_data;

 typedef enum e_command {sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr}\
 	t_cmd;

void	validate_formatting(char *argv[]);
void	validate_no_duplicate_num(t_data *data);
void	error_exit(void);
int		int_only(long input);
bool	is_valid_num_format(char *ptr, int i);
t_data	*collect_data(char *argv[]);
t_data	*new_data_list(int input);
t_data	*add_data_node(t_data *prev, int input, t_data *next);
t_data	*split_nums_from_strings(t_data *ptr, char *str, t_data *head);
void	insert_normalized_values(t_data *head, size_t size);
void	push_swap(t_data *start_input);
void	print_ops(t_command operation);
t_cmd	swap_a(t_data **stackA);
t_cmd	swap_b(t_data **stackB);
t_cmd	swap_swap_ab(t_data **stackA, t_data **stackB);
t_cmd	push_a(t_data **stackA, t_data **stackB);
t_cmd	push_b(t_data **stackA, t_data **stackB);
t_cmd	rotate_a(t_data **stackA);
t_cmd	rotate_b(t_data **stackB);
t_cmd	rotate_rotate_ab(t_data **stackA, t_data **stackB);
t_cmd	rev_rotate_a(t_data **stackA);
t_cmd	rev_rotate_b(t_data **stackB);
t_cmd	rev_rotate_rotate_ab(t_data **stackA, t_data **stackB);
t_data	*remove_head_from_stack(t_data **stack);
void	initialize_stack_from_head(t_data **stack, t_data *head);
void	add_head_to_stack(t_data **stack, t_data **head);

#endif