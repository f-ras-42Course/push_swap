/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collect.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/27 02:13:37 by fras          #+#    #+#                 */
/*   Updated: 2023/05/12 17:52:47 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*collect_input(int argc, char *argv[])
{
	t_list	*data;
	t_list	*ptr;
	int		i;
	int		j;

	i = 1;
	ptr = data;
	data = lst_add_new_value(int_only(fr_atol(argv[i])));
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
			{
				j++;
				ptr->next = lst_add_new_value(int_only(fr_atol(argv[i + j])));
				ptr = ptr->next;
			}
			j++;
		}
		ptr->next = lst_add_new_value(int_only(fr_atol(argv[i])));
		ptr = ptr->next;
		i++;
	}
	return (data);
}

t_list string_handler(t_list lst, char *str) // Decide more descriptive function name
{
	// While loop here
}

int	int_only(long input)
{
	if (input > INT_MAX | input < INT_MIN)
		error_exit();
	return ((int) input);
}

t_list *lst_add_new_value(int value)
{
	int		*insertion;
	t_list	*to_list;

	insertion = malloc(sizeof(int));
	if(!insertion)
		error_exit();
	*insertion = value;
	to_list = ft_lstnew(insertion);
	return (to_list);
}