/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 15:09:18 by cter-maa      #+#    #+#                 */
/*   Updated: 2024/03/19 15:14:25 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

int	find_start(char **file, int i)
{
	int	j;
	int	start;

	j = 0;
	start = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j] == '1' || file[i][j] == ' ' || file[i][j] == '	')
			j++;
		if (file[i][j] == '\0')
		{
			start = i;
			break ;
		}
		i++;
	}
	return (start);
}

int	find_end(t_cubed *cubed, char **file, int i)
{
	int	j;
	int	end;

	j = 0;
	end = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j] == '1' || file[i][j] == ' ' || file[i][j] == '	')
			j++;
		if (file[i][j] == '\0')
		{
			end = i;
			break ;
		}
		i++;
	}
	if (file[i + 1] && file[i + 1] != NULL)
	{
		close(cubed->fd);
		error_exit("Error:\nIncorrect map\n");
	}
	return (end);
}

int	find_max_width(t_cubed *cubed, int start, int end)
{
	int	i;
	int	max_i;

	i = 0;
	max_i = 0;
	while (start < end)
	{
		i = 0;
		while (cubed->file[start][i])
			i++;
		if (i >= max_i)
			max_i = i;
		start++;
	}
	cubed->max_column = max_i;
	if (cubed->max_column == 0)
	{
		free_2d_array(cubed->file);
		close(cubed->fd);
		error_exit("Error:\nIncorrect map\n");
	}
	return (SUCCESS);
}
