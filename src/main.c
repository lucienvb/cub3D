/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 14:53:05 by cter-maa      #+#    #+#                 */
/*   Updated: 2024/03/13 14:53:43 by cter-maa      ########   odam.nl         */
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
		free_allocations(&cubed);
		return (FAILURE);
	}
	init_drawing(&cubed);
	if (start_cubed(&cubed) == FAILURE)
	{
		free_allocations(&cubed);
		return (EXIT_FAILURE);
	}
	free_allocations(&cubed);
	return (EXIT_SUCCESS);
}
