/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_error_handling.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 14:57:22 by cter-maa      #+#    #+#                 */
/*   Updated: 2024/03/13 14:57:23 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static void	print_input_info(void)
{
	ft_printf("wrong input\n");
	ft_printf("cub3d program requires 2 argmuents:\n");
	ft_printf("< ./cubed >  +  < map_name >\n");
}

static int	check_file_type(char *argv)
{
	int	index;

	index = 0;
	while (argv[index])
	{
		if (argv[index] == '.')
		{
			if (ft_strncmp(&argv[index], ".cub\0", 5) == FOUND)
				return (SUCCESS);
		}
		index++;
	}
	return (FAILURE);
}

void	input_error_handling(int argc, char **argv)
{
	if (argc != 2 || !*argv[1] || (ft_strncmp(argv[1], " ", 1) == FOUND))
	{
		print_input_info();
		exit(EXIT_FAILURE);
	}
	if (check_file_type(argv[1]) == FAILURE)
		error_exit("Error\nWrong file type\n");
}
