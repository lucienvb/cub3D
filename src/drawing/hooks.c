#include "../../include/cubed.h"

void hooks(void* param)
{
	t_cubed	*cubed;

	cubed = param;

	if (mlx_is_key_down(cubed->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cubed->mlx);
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_W)) // move forward (zoom isn)
	{
		if (cubed->posX < cubed->mapWidth - cubed->pdx && cubed->posY < cubed->mapHeight - cubed->pdy) 
		{
			cubed->posX += cubed->pdx;
			cubed->posY += cubed->pdy;

		}
		reset_settings(cubed);
	}
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_S)) // move backward (zoom out)
	{
		if (cubed->posX >= 0 + cubed->pdx && cubed->posY >= 0 + cubed->pdy)
		{
			cubed->posX -= cubed->pdx;
			cubed->posY	-= cubed->pdy;
		}
		reset_settings(cubed);
	}
	// if (mlx_is_key_down(cubed->mlx, MLX_KEY_A)) // move to the left (change position in map)
	// {
	// }
	// if (mlx_is_key_down(cubed->mlx, MLX_KEY_D)) // move to the right (change position in map)
	// {
	// }
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_LEFT)) // change screen to the left
	{
		cubed->pa -= 0.05;
		if (cubed->pa < 0)
			cubed->pa += 2 * M_PI;
		cubed->pdx = cos(cubed->pa)	* 2;
		cubed->pdy = sin(cubed->pa) * 2;
		reset_settings(cubed);
	}
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_RIGHT)) // change screen to the right
	{
		cubed->pa += 0.05;
		if (cubed->pa > 2 * M_PI)
			cubed->pa -= 2 * M_PI;
		cubed->pdx = cos(cubed->pa)	* 2;
		cubed->pdy = sin(cubed->pa) * 2;
		reset_settings(cubed);
	}
}