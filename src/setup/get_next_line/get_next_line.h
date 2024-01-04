/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 11:21:21 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/12/13 13:17:18 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// DEFINE
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// INCLUDES
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

// FUNCTIONS
int		string_lenght(char *str);
char	*string_join(char *file, char *buffer);
char	*readfile(int fd, char *line, char *buff);
char	*get_next_line(int fd);
int		string_search(char *s, char c);
int		search_index(char *buff, char c);
void	clean_buffer(char *buff);

#endif
