#include "../../include/cubed.h"

static void	get_ray_direction(t_cubed *cubed, double pa)
{
	if (pa > 2 * M_PI)
		pa -= 2 * M_PI;
	if (pa >= (M_PI / 2) && pa < (M_PI * 3/2)) 
		cubed->dirX = -1;
	else
		cubed->dirX = 1;
	if (pa >= 0 && pa < M_PI)
		cubed->dirY = 1;
	else
		cubed->dirY = -1;
}

void	get_player_to_grid(t_cubed *cubed, double *player_to_grid_x, double *player_to_grid_y)
{
	double	pa = cubed->pa + cubed->fov;

	get_ray_direction(cubed, pa);
	if (cubed->dirX == 1)
		*player_to_grid_x = cubed->posX;
	else if (cubed->dirX == -1)
		*player_to_grid_x = cubed->mini_map_width - cubed->posX;
	else // not sure about this
		*player_to_grid_x = 0;
	if (cubed->dirY == 1)
		*player_to_grid_y = cubed->posY;
	else if (cubed->dirY == -1)
		*player_to_grid_y = cubed->mini_map_height - cubed->posY;
	else // not sure about this
		*player_to_grid_y = 0;

	while (*player_to_grid_x >= 0)
		*player_to_grid_x -= cubed->grid_width ;
	if (cubed->dirX == 1)
		*player_to_grid_x *= -1;
	
	while (*player_to_grid_y >= 0)
		*player_to_grid_y -= cubed->grid_height;
	if (cubed->dirY == 1)
		*player_to_grid_y *= -1;
}