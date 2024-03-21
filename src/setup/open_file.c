/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   open_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 14:17:57 by cter-maa      #+#    #+#                 */
/*   Updated: 2024/03/19 15:07:57 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static char	*concatenate_lines(int fd)
{
	char	*line;
	char	*new_line;
	char	*temp;

	new_line = ft_calloc(1, 1);
	if (new_line == NULL)
		return (NULL);
	line = get_next_line(fd);
	if (line == NULL)
	{
		free(new_line);
		return (NULL);
	}
	while (line != NULL)
	{
		temp = new_line;
		new_line = ft_strjoin(new_line, line);
		free(line);
		free(temp);
		if (new_line == NULL)
			break ;
		line = get_next_line(fd);
	}
	return (new_line);
}

static char	**split_lines(char *new_line)
{
	char	**file;

	file = ft_split(new_line, '\n');
	free(new_line);
	if (file == NULL)
		return (NULL);
	return (file);
}

char	**cub_to_double_array(int fd)
{
	char	*new_line;
	char	**file;

	new_line = concatenate_lines(fd);
	if (new_line == NULL)
		return (NULL);
	file = split_lines(new_line);
	if (file == NULL)
		return (NULL);
	return (file);
}
