/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 15:08:08 by cter-maa      #+#    #+#                 */
/*   Updated: 2024/03/19 15:09:35 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static char	**create_map(t_cubed *cubed)
{
	int		y;
	char	**map;

	y = 0;
	map = ft_calloc((cubed->total_row + 1), sizeof(char *));
	if (!map)
		return (NULL);
	while (y < cubed->total_row)
	{
		map[y] = ft_calloc((cubed->max_column + 1), sizeof(char));
		if (!map[y])
		{
			free_2d_array(map);
			return (NULL);
		}
		map[y][cubed->max_column] = '\0';
		y++;
	}
	map[y] = NULL;
	return (map);
}

void	copy_map(t_cubed *cubed, char **map, int start, int end)
{
	int		index;

	index = 0;
	while (start < end)
	{
		ft_strlcpy(map[index], cubed->file[start], cubed->max_column + 1);
		start++;
		index++;
	}
}

int	parse_map(t_cubed *cubed)
{
	int	start;
	int	end;

	end = 0;
	start = find_start(cubed->file, 0);
	end = find_end(cubed, cubed->file, start + 1) + 1;
	cubed->total_row = end - start;
	if (find_max_width(cubed, start, end) == FAILURE)
		return (FAILURE);
	cubed->map = create_map(cubed);
	if (cubed->map == NULL)
	{
		free_2d_array(cubed->file);
		return (FAILURE);
	}
	cubed->map_val = create_map(cubed);
	if (cubed->map_val == NULL)
	{
		free_2d_array(cubed->map);
		free_2d_array(cubed->file);
		return (FAILURE);
	}
	copy_map(cubed, cubed->map, start, end);
	copy_map(cubed, cubed->map_val, start, end);
	return (SUCCESS);
}
