/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 21:53:14 by fras          #+#    #+#                 */
/*   Updated: 2023/07/05 21:20:44 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TOTAL_DIGITS_MAX_INT 10

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_data
{
	struct s_data	*prev;				
	int				input_value;
	int				normalized_value;
	struct s_data	*next;
}	t_data;

typedef enum e_command {none, sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr,\
	invalid}	t_cmd;

void	validate_formatting(char *argv[]);
void	validate_no_duplicate_num(t_data *data);
int		int_only(long input, t_data *data);
bool	is_valid_num_format(char *ptr, int i);
t_data	*collect_data(char *argv[]);
t_data	*new_data_list(int input);
t_data	*add_data_node(t_data *prev, int input, t_data *head);
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
bool	is_sorted(t_data *stackA, size_t data_size);
void	small_sort(t_data **stackA, size_t data_size, int lowest);
void	ferry_sort(t_data **stackA, t_data **stackB, size_t data_size);
void	radix_sort(t_data **stackA, t_data **stackB, size_t data_size);
int		locate_low_top_or_bottom(t_data **stackA, int num);
int		get_highest_bit_length(t_data *stackA);
void	push_all_to_stack_a(t_data **stackA, t_data **stackB);
bool	ft_isdigit(int c);
long	ft_atol(const char *str);
void	error_exit(void);
void	malloc_failure_exit(t_data *data);
void	freeing_data(t_data *data);

#endif