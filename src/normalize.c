/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normalize.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 23:08:23 by fras          #+#    #+#                 */
/*   Updated: 2023/06/10 13:44:44 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_normalized_values(t_data *head, size_t list_size)
{
	int		lowest_value;
	int		normalize_value;

	normalize_value = 0;
	while (normalize_value < (int)list_size)
	{
		lowest_value = get_lowest_value(head);
		insert_lowest_norm_value(lowest_value, normalize_value, head);
		normalize_value++;
	}
}

int	get_lowest_value(t_data *head)
{
	int		lowest_value;
	t_data	*ptr;

	ptr = head;
	lowest_value = INT_MAX;
	if (ptr->normalized_value == -1)
			lowest_value = ptr->input_value;
	ptr = ptr->next;
	while (ptr != head)
	{
		if (ptr->input_value < lowest_value && ptr->normalized_value == -1)
			lowest_value = ptr->input_value;
		ptr = ptr->next;
	}
	return (lowest_value);
}

void	insert_lowest_norm_value(int lowest_value, int insertion, t_data *head)
{
	while (head->input_value != lowest_value)
		head = head->next;
	head->normalized_value = insertion;
}
