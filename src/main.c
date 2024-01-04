#include "cubed.h"

// static void	test_input(t_cubed *cubed)
// {
// 	int index = 0;
// 	while (cubed->map[index])
// 	{
// 		printf("\n%i ) %s", index , cubed->map[index]);
// 		index++;
// 	}

// 	printf("\n\n%i = cubed->pos_y\n", cubed->start_pos[Y]);
// 	printf("%i = cubed->pos_x\n", cubed->start_pos[X]);
// 	index = 0;
// 	printf("\n\nceiling color: ");
// 	while(index < 3)
// 	{
// 		printf(" %i", cubed->ceiling[index]);
// 		index++;
// 	}
// 	printf("\n");
// 	index = 0;
// 	printf("floor color: ");
// 	while(index < 3)
// 	{
// 		printf(" %i", cubed->floor[index]);
// 		index++;
// 	}
// 	printf("\n");
// }

int	main(int argc, char **argv)
{
	t_cubed		cubed;

	input_error_handling(argc, argv);
	input_init(&cubed, argv[1]);
	if (input_parsing(&cubed, argv[1]) == FAILURE)
	{
		free_allocations(&cubed);
		return (FAILURE);
	}
	free_allocations(&cubed);
	return (SUCCESS);
}
