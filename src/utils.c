/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 04:07:43 by fras          #+#    #+#                 */
/*   Updated: 2023/05/17 10:14:11 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	circular_list_size(t_data *head)
{
	size_t	size;
	t_data	*ptr;

	size = 0;
	ptr = head->next;
	while (ptr != head)
	{
		ptr = ptr->next;
		size++;
	}
	return (++size);
}
