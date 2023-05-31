/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 18:26:53 by fras          #+#    #+#                 */
/*   Updated: 2023/05/31 13:36:01 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	redix_sort(t_data **stackA, t_data **stackB)
{
	int	highest_value;

	*stackB = NULL;
	highest_value = get_highest_value(*stackA);
	printf("\n\n\n\n\nHIGHEST VALUE = %d\n\n\n\n\n\n", highest_value);
}

int	get_highest_value(t_data *stackA)
{
	t_data	*ptr;
	int		highest_value;

	highest_value = stackA->normalized_value;
	ptr = stackA->next;
	while (ptr != stackA)
	{
		if (highest_value <= ptr->normalized_value)
			highest_value = ptr->normalized_value;
		ptr = ptr->next;
	}
	return (highest_value);
}
