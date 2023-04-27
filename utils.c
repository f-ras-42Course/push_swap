/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/27 02:13:37 by fras          #+#    #+#                 */
/*   Updated: 2023/04/27 02:53:53 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

t_list lst_add_new_value(int value)
{
	int		*insertion;
	t_list	to_list;

	insertion = malloc(sizeof(int));
	*insertion = value;
	to_list = ft_lstnew(insertion);
	return (to_list);
}
