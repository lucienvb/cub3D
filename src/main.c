#include "../include/cubed.h"

// void f(){
// 	system("leaks cub3d");
// }

int	main(int argc, char **argv)
{
	t_cubed		cubed;

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
	// atexit(f);
    return (EXIT_SUCCESS);
}
