/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validations.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 21:50:25 by fras          #+#    #+#                 */
/*   Updated: 2023/05/04 03:39:50 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		validate_formatting(int argc, char *argv[])
{
	int i;
	int j;

	i = 1;
	if (argc == 1)
		error_exit();
	while (i < argc)
	{
		j = 0;
		if (!argv[i][j])
			error_exit();
		if (!ft_isdigit(argv[i][j]) || (argv[i][j] != '-'))
			error_exit();
		while (argv[i][j])
		{
			j++;
			if (!ft_isdigit(argv[i][j]) \
				|| (argv[i][j] == ' '  && !ft_isdigit(argv[i][j - 1])) \
				|| (argv[i][j] == '-') && (argv[i][j - 1] != ' '))
				error_exit();
		}
		i++;
	}
}

// void	validate_no_duplicates(t_list *data)
// {
// 	int i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		data[i]
// 	}
// }

void	error_exit(void)
{
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}
