/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_color_code.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 14:57:29 by cter-maa      #+#    #+#                 */
/*   Updated: 2024/03/13 14:57:31 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static int	cd_isnum(char a)
{
	if (a >= '0' && a <= '9')
		return (FOUND);
	return (NOT_FOUND);
}

static int	cd_atoi(const char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (cd_isnum(str[i]) == FOUND && str[i] && (i < 3))
	{
		result = result * 10;
		result = (result + (str[i] - '0'));
		i++;
	}
	if (result > 255)
		return (FAILURE);
	return (result);
}

static int	get_color(t_cubed *cubed, char *line, char idf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (line[i] == idf)
	{
		while (line[i])
		{
			while (cd_isnum(line[i]) == NOT_FOUND)
				i++;
			if (idf == 'C')
				cubed->ceiling[j] = cd_atoi(&line[i]);
			else if (idf == 'F')
				cubed->floor[j] = cd_atoi(&line[i]);
			if (cubed->ceiling[j] == FAILURE || cubed->floor[j] == FAILURE)
				return (FAILURE);
			if (j == 2)
				return (FOUND);
			j++;
			while (cd_isnum(line[i]) == FOUND)
				i++;
		}
	}
	return (NOT_FOUND);
}

int	parse_color_code(t_cubed *cubed)
{
	int	i;
	int	total_found;
	int	j;

	i = 0;
	total_found = 0;
	while (cubed->file[i])
	{
		j = 0;
		while (cb_isspace(cubed->file[i][j]) == FOUND)
			j++;
		if (get_color(cubed, &cubed->file[i][j], 'C') == FOUND)
			total_found++;
		else if (get_color(cubed, &cubed->file[i][j], 'F') == FOUND)
			total_found++;
		i++;
	}
	if (total_found != 2)
	{
		ft_printf("Error:\nColor code(s) incorrect\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
