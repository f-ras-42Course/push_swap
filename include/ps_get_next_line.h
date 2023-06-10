/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_get_next_line.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:46:02 by fras          #+#    #+#                 */
/*   Updated: 2023/06/10 13:24:58 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_GET_NEXT_LINE_H
# define PS_GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line_stdin(void);
size_t	retrieve_leftover(char **dest, char *leftover);
size_t	buffering(char **stored_read, size_t old_size);
char	*extract_line(char *source, char *leftover, size_t len);
size_t	find_newline(char *search, size_t size);
char	*save_alloc_string(char *source, size_t size);
char	*save_string_realloc(char *source, char *dest, size_t size);
size_t	sizeof_stringcopy(char *dest, char *source);
void	read_failure_exit(void);
void	malloc_failure_exit(void);

#endif