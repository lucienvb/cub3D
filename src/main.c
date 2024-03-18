/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: chaverttermaat <chaverttermaat@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 09:56:04 by chavertterm   #+#    #+#                 */
/*   Updated: 2024/03/18 13:09:41 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

int	main(int argc, char **argv)
{
	t_cubed	cubed;

	input_error_handling(argc, argv);
	init_setup(&cubed, argv[1]);
	if (input_parsing(&cubed, argv[1]) == FAILURE)
	{
		return (FAILURE);
	}
	init_drawing(&cubed);
	if (start_cubed(&cubed) == FAILURE)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
