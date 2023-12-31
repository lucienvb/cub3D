#include "../../include/cubed.h"
#include <string.h>

// check if everything is initialized correctly

static void	init_cubed(t_cubed *cubed, char *argv)
{
	bzero(cubed, sizeof(*cubed));
	cubed->fd = -1;
	cubed->file = NULL;
	cubed->map = NULL;
	cubed->map_val = NULL;
	cubed->argv = argv;
	cubed->start_pos[Y] = 0;
	cubed->start_pos[X] = 0;
	cubed->start_cardinal_point = 0;
	cubed->ceiling[0] = 0;
	cubed->ceiling[1] = 0;
	cubed->ceiling[2] = 0;
	cubed->floor[0] = 0;
	cubed->floor[1] = 0;
	cubed->floor[2] = 0;
	cubed->width = 0;
	cubed->height = 0;
}

void	input_init(t_cubed *cubed, char *argv)
{
	init_cubed(cubed, argv);
}
