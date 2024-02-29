#include "../include/cubed.h"
// minimap klopt niet.
// wanneer je met A & D toets begint kun out of bound lopen.

// void f(){
// 	system("leaks cub3d");
// }

int	main(int argc, char **argv)
{
	t_cubed		cubed;
	uint32_t	status;

	input_error_handling(argc, argv);
	input_init(&cubed, argv[1]);
	if (input_parsing(&cubed, argv[1]) == FAILURE)
	{
		free_allocations(&cubed);
		return (FAILURE);
	}
	status = start_cubed(&cubed);
	free_allocations(&cubed);
	// atexit(f);
    return (status);
}
