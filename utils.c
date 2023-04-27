/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/27 02:13:37 by fras          #+#    #+#                 */
/*   Updated: 2023/04/27 03:13:52 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	collect_input(int argc, char *argv[])
{
	t_list	*data;
	t_list	*ptr;
	int		i;
	int		j;

	i = 1;
	j = 0;
	data = lst_add_new_value(ft_atoi(argv[i]));
	ptr = data;
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
				ptr->next = lst_add_new_value(ft_atoi(argv[i]));
				ptr = ptr->next;
			}
		}
		i++;
	}
	return (data);
}

t_list lst_add_new_value(int value)
{
	int		*insertion;
	t_list	to_list;

	insertion = malloc(sizeof(int));
	*insertion = value;
	to_list = ft_lstnew(insertion);
	return (to_list);
}
