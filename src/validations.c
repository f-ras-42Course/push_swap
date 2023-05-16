/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validations.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 21:50:25 by fras          #+#    #+#                 */
/*   Updated: 2023/05/16 23:56:00 by ferryras      ########   odam.nl         */
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
		while (argv[i][j])
		{
			digit_count += ft_isdigit(argv[i][j]);
			if (digit_count > 10)
				error_exit();
			if (!is_valid_num_format(argv[i], j))
				error_exit();
			if (argv[i][j] == ' ')
				digit_count = 0;
			j++;
		}
		i++;
	}
}

bool	is_valid_num_format(char *ptr, int i)
{
	if (i == 0)
		return (ft_isdigit(ptr[i]) || ((ptr[i] == '-') && ptr[i + 1]));
	return (ft_isdigit(ptr[i]) \
		|| ((ptr[i] == ' ') && ft_isdigit(ptr[i - 1]) && ptr[i + 1]) \
		|| ((ptr[i] == '-') && (ptr[i - 1] == ' ') && ptr[i + 1]));
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