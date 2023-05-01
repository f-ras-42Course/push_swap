/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/27 02:13:37 by fras          #+#    #+#                 */
/*   Updated: 2023/04/27 11:33:41 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	collect_input(int argc, char *argv[])
{
	t_list	*data;
	t_list	*ptr;
	int		i;
	int		j;

	i = 1;
	j = 0;
	data = lst_add_new_value(ft_atoi(argv[i]), data);
	ptr = data;
	while (i <= argc)
	{
		while (argv[i][j])
		{
			while (ft_isdigit(argv[i][j]) || argv[i][j] == '-')
				j++;
			if (argv[i][j] == ' ')
			{
				while (argv[i][j] == ' ')
					j++;
				ptr->next = lst_add_new_value(ft_atoi(argv[i]), data);
				ptr = ptr->next;
			}
		}
		i++;
	}
	return (data);
}

t_list *lst_add_new_value(int value, t_list *first_node)
{
	int		*insertion;
	t_list	*to_list;

	insertion = malloc(sizeof(int));
	if(!insertion)
		lst_malloc_protect(first_node);
	*insertion = value;
	to_list = ft_lstnew(insertion);
	return (to_list);
}

void	lst_malloc_protect(t_list *first_node)
{
	ft_lstclear(&first_node, &free);
	error_exit();
}