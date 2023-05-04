/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validations.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 21:50:25 by fras          #+#    #+#                 */
/*   Updated: 2023/05/04 05:47:32 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}

void	validate_formatting(int argc, char *argv[])
{
	int	i;
	int	j;
	int	digit_count;

	i = 1;
	while (i < argc)
	{
		j = 0;
		digit_count = 0;
		if (!ft_isdigit(argv[i][0]) || (argv[i][0] != '-'))
			error_exit();
		while (argv[i][j])
		{
			digit_count += ft_isdigit(argv[i][j]);
			if (digit_count > 10)
				error_exit();
			j++;
			if (!is_singlenum)
				error_exit();
			if (argv[i][j] == ' ')
				digit_count = 0;
		}
		i++;
	}
}

int	is_singlenum(char *ptr, int i)
{
	return (ft_isdigit(ptr[i]) \
		|| ((ptr[i] == ' ') && ft_isdigit(ptr[i - 1])) \
		|| ((ptr[i] == '-') && (ptr[i - 1] == ' ')));
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