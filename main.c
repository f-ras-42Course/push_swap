/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 21:20:13 by fras          #+#    #+#                 */
/*   Updated: 2023/04/27 02:55:32 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list *data;
	validate_formatting(argc, argv);
	data = collect_input(argc, argv);
	//check_for_duplicates(data);
	//14 12 12 "15 05 84" 1542 45
}

int	collect_input(int argc, char *argv[])
{
	t_list	*data;
	t_list	*ptr;
	int		i;
	int		j;

	i = 1;
	j = 0;
	data = lst_add_new_value(ft_atoi(argv[i]));
	while (i < argc)
	{
		while (argv[i][j])
		{
			while (ft_isdigit(argv[i][j]) || argv[i][j] == '-')
				j++;
			if (argv[i][j] == ' ')
			{
				while (argv[i][j] == ' ')
					j++;
				ptr = data->next;
				ptr = lst_add_new_value(ft_atoi(argv[i]));
			}
		}
		i++;
	}
}