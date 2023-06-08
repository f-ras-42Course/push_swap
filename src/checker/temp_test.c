/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   temp_test.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 19:45:11 by fras          #+#    #+#                 */
/*   Updated: 2023/06/08 20:14:37 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void test(t_data *data)
{
	t_data *ptr;
	int i;

	if(!data)
	{
		printf("\n---TEST: NO DATA FOUND---\n");
		return;
	}
 	i = 0;
	ptr = data;
 	printf("[HEAD %d] = %d\n", i++, ptr->normalized_value);
 	ptr = ptr->next;
 	while (ptr != data)
 	{
 		printf("[%d] = %d\n", i++, ptr->normalized_value);
 		ptr = ptr->next;
 	}
	printf("\n\n");
}