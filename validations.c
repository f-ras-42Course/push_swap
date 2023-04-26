/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validations.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 21:50:25 by fras          #+#    #+#                 */
/*   Updated: 2023/04/27 01:45:27 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		check_correct_formatting(int argc, char *argv[])
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (!argv[i][j])
			error_exit;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) || !argv[i][j] == ' ')
				error_exit;
		}
	}
}

void	check_for_duplicates(t_list *data);
{
	int i;

	i = 0;
	while (i < size)
	{
		data[i]
	}
}

void	error_exit(void)
{
	write(2, "Error\n", 7);
	exit(0);
}
