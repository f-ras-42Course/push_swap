/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PS_get_next_line.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:45:53 by fras          #+#    #+#                 */
/*   Updated: 2023/06/08 20:07:35 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ps_get_next_line.h"

char	*get_next_line_stdin(void)
{
	static char	leftover[BUFFER_SIZE];
	char		*storage;
	size_t		len;
	size_t		newline_pos;

	len = retrieve_leftover(&storage, leftover);
	newline_pos = find_newline(storage, len);
	if (newline_pos)
		return (extract_line(storage, leftover, newline_pos));
	len = buffering(&storage, len);
	newline_pos = find_newline(storage, len);
	if (newline_pos)
		return (extract_line(storage, leftover, newline_pos));
	if (*storage == '\0')
	{
		free(storage);
		return (NULL);
	}
	return (storage);
}

size_t	retrieve_leftover(char **dest, char *leftover)
{
	size_t	leftover_size;

	leftover_size = 0;
	while (leftover[leftover_size])
		leftover_size++;
	*dest = save_alloc_string(leftover, leftover_size);
	*leftover = '\0';
	return (leftover_size);
}

size_t	buffering(char **stored_read, size_t old_size)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	size_t	size;
	size_t	newline;

	size = old_size;
	newline = 0;
	bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	while (!newline && bytes_read > 0)
	{
		size += bytes_read;
		newline = find_newline(buffer, BUFFER_SIZE);
		*stored_read = save_string_realloc(buffer, *stored_read, size);
		if (!newline)
			bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
		read_failure_exit();
	return (size);
}

char	*extract_line(char *source, char *leftover, size_t len)
{
	char	*line;

	sizeof_stringcopy(leftover, &source[len]);
	line = save_alloc_string(source, len);
	free(source);
	return (line);
}
