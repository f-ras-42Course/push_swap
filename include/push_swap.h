/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 21:53:14 by fras          #+#    #+#                 */
/*   Updated: 2023/06/07 16:20:48 by fras          ########   odam.nl         */
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

 typedef enum e_command {none, sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr}\
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
 size_t	circular_list_size(t_data *head);
void	insert_normalized_values(t_data *head, size_t size);
int		get_lowest_value(t_data *head);
void	insert_lowest_norm_value(int lowest_value, int insertion, t_data *head);
void	push_swap(t_data *start_input, size_t data_size);
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
void	swap(t_data **stack);
t_data	*remove_head_from_stack(t_data **stack);
void	initialize_stack_from_head(t_data **stack, t_data *head);
void	add_head_to_stack(t_data **stack, t_data **head);
t_cmd	print_ops(t_cmd operation);
void	small_sort(t_data **stackA, size_t data_size, int lowest);
void	small_sort_reverse(t_data **stackB, size_t data_size, int highest);
void	ferry_sort(t_data **stackA, t_data **stackB, size_t data_size);
void	ferry_sort_sz4(t_data **stackA, t_data **stackB);
int		locate_low_normal_or_rev(t_data **stackA, int num);
void	redix_sort (t_data **stackA, t_data **stackB, size_t data_size);
int		get_highest_bit_length(t_data *stackA);
void	push_all_to_stackA(t_data **stackA, t_data **stackB);

#endif