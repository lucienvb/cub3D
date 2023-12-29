#include "../../include/cubed.h"

void	free_allocations(t_cubed *cubed)
{
	free_2d_array(cubed->file);
	free_2d_array(cubed->map);
	free_2d_array(cubed->map_val);
	close(cubed->fd);
}
