/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bus <lvan-bus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:56:04 by chavertterm       #+#    #+#             */
/*   Updated: 2024/03/21 12:51:05 by lvan-bus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"
#include <signal.h>

int	main(int argc, char **argv)
{
	t_cubed		cubed;

	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
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
