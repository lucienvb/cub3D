/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 11:04:17 by chavertterm   #+#    #+#                 */
/*   Updated: 2024/03/21 10:43:33 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"
#include "./get_next_line/get_next_line.h"
#include <fcntl.h>

static int	parsing(t_cubed *cubed)
{
	if (parse_map(cubed) == FAILURE)
	{
		close(cubed->fd);
		ft_printf("Error:\nInvalid file\n");
		exit(EXIT_FAILURE);
	}
	if (parse_color_code(cubed) == FAILURE)
		return (FAILURE);
	if (parse_texture(cubed) == FAILURE)
		return (FAILURE);
	if (parse_start_pos(cubed) == FAILURE)
	{
		printf("Error:\nIncorrect start positions(s)\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	input_parsing(t_cubed *cubed, char *argv)
{
	cubed->fd = open(argv, O_RDONLY);
	if (cubed->fd == -1)
		perror_exit("Error:\nFailed to open .cub");
	cubed->file = cub_to_double_array(cubed->fd);
	if (cubed->file == NULL)
	{
		close(cubed->fd);
		error_exit("Error:\nFailed to parse map to 2d array\n");
	}
	if (parsing(cubed) == FAILURE)
		return (FAILURE);
	if (validate_map(cubed, cubed->start_pos[Y], cubed->start_pos[X])
		== FAILURE)
	{
		ft_printf("Error:\nInvalid map\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
