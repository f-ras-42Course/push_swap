/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 21:53:14 by fras          #+#    #+#                 */
/*   Updated: 2023/05/17 03:32:51 by ferryras      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"
#include "libft-extended.h"

typedef struct s_data
{
	struct s_data	*prev;				
	int				input_value;
	int				normalized_value;
	struct s_data	*next;
}	t_data;

void	validate_formatting(char *argv[]);
void	validate_no_duplicate_num(t_data *data);
void	error_exit(void);
int		int_only(long input);
bool	is_valid_num_format(char *ptr, int i);
t_data	*collect_data(char *argv[]);
t_data	*new_data_list(int input);
t_data	*add_data_node(t_data *prev, int input, t_data *next);
t_data	*split_num_from_strings(t_data *ptr, char *str, t_data *head);
void	push_swap(t_data *head);