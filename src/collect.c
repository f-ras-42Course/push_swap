/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collect.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/27 02:13:37 by fras          #+#    #+#                 */
/*   Updated: 2023/05/17 00:10:11 by ferryras      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*collect_data(int argc, char *argv[])
{
	t_data	*head;
	t_data	*ptr;
	int		i;
	int		j;

	i = 1;
	head = new_data_node(int_only(fr_atol(argv[i])));
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
			{
				j++;
				ptr->next = int_only(fr_atol(argv[i + j]));
				ptr = ptr->next;
			}
			j++;
		}
		ptr->next = int_only(fr_atol(argv[i]));
		ptr = ptr->next;
		i++;
	}
	return (data);
}

t_data	lst_string_split_num(t_data lst, char *str) // Decide more descriptive function name
{
	// While loop here
}

int		int_only(long input)
{
	if (input > INT_MAX | input < INT_MIN)
		error_exit();
	return ((int) input);
}

t_data	*new_data_node(int value)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		error_exit();
	new->prev = new;
	new->value_input = value;
	new->index = -1;
	new->next = new;
	return (new);
}