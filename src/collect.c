/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collect.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/27 02:13:37 by fras          #+#    #+#                 */
/*   Updated: 2023/06/12 21:41:33 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*collect_data(char *argv[])
{
	t_data	*head;
	t_data	*ptr;
	int		i;

	i = 1;
	head = new_data_list(int_only(fr_atol(argv[i])));
	ptr = head;
	while (argv[i])
	{
		if (i != 1)
			ptr = add_data_node(ptr, int_only(fr_atol(argv[i])), head);
		ptr = split_nums_from_strings(ptr, argv[i], head);
		i++;
	}
	head->prev = ptr;
	return (head);
}

t_data	*split_nums_from_strings(t_data *ptr, char *str, t_data *head)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			ptr = add_data_node(ptr, int_only(fr_atol(str + i)), head);
		}
		i++;
	}
	return (ptr);
}

t_data	*new_data_list(int input)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		malloc_failure_exit(new);
	new->prev = NULL;
	new->input_value = input;
	new->normalized_value = -1;
	new->next = new;
	return (new);
}

t_data	*add_data_node(t_data *prev, int input, t_data *next)
{
	t_data	*node;

	node = malloc(sizeof(t_data));
	if (!node)
		malloc_failure_exit(node);
	prev->next = node;
	node->prev = prev;
	node->input_value = input;
	node->normalized_value = -1;
	node->next = next;
	return (node);
}
