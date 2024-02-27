#include "../../include/cubed.h"

void hooks(void* param)
{
	t_cubed	*cubed;

	cubed = param;

	if (mlx_is_key_down(cubed->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cubed->mlx);
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_W))
	{
		if ((cubed->posX > 1 - cubed->stepX && cubed->posX < cubed->map_width - 1 - cubed->stepX) && 
			(cubed->posY > 1 - cubed->stepY && cubed->posY < cubed->map_height - 1 - cubed->stepY))
		{
			cubed->posX += cubed->stepX;
			cubed->posY += cubed->stepY;
		}
		reset_settings(cubed);
	}
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_S))
	{
		if (cubed->posX > 1 + cubed->stepX && cubed->posX < cubed->map_width - 1 + cubed->stepX && 
			cubed->posY > 1 + cubed->stepY && cubed->posY < cubed->map_height - 1 + cubed->stepY) 
		{
			cubed->posX -= cubed->stepX;
			cubed->posY	-= cubed->stepY;
		}
		reset_settings(cubed);
	}
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_A))
	{
		if (cubed->posX + cubed->stepXctrlA > 1 && cubed->posX + cubed->stepXctrlA < (double)cubed->total_row - 1)
			cubed->posX += cubed->stepXctrlA;
		if (cubed->posY + cubed->stepYctrlA > 1 && cubed->posY + cubed->stepYctrlA < (double)cubed->max_column - 1)
			cubed->posY	+= cubed->stepYctrlA;	
		reset_settings(cubed);
	}
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_D))
	{
		if (cubed->posX + cubed->stepXctrlD > 1 && cubed->posX + cubed->stepXctrlD < (double)cubed->total_row -1)
			cubed->posX += cubed->stepXctrlD;
		if (cubed->posY + cubed->stepYctrlD > 1 && cubed->posY + cubed->stepYctrlD < (double)cubed->max_column -1)
			cubed->posY += cubed->stepYctrlD;
		reset_settings(cubed);
	}
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_LEFT))
	{
		cubed->pa -= 0.03;
		if (cubed->pa < 0)
			cubed->pa += 2 * M_PI;
		cubed->stepX = cos(cubed->pa) * 0.05;
		cubed->stepY = sin(cubed->pa) * 0.05;
		cubed->stepXctrlA = cos(cubed->pa - 0.5 * M_PI) * 0.05;
		cubed->stepYctrlA = sin(cubed->pa - 0.5 * M_PI) * 0.05;
		cubed->stepXctrlD = cos(cubed->pa + 0.5 * M_PI) * 0.05;
		cubed->stepYctrlD = sin(cubed->pa + 0.5 * M_PI) * 0.05;
		reset_settings(cubed);
	}
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_RIGHT))
	{
		cubed->pa += 0.03;
		if (cubed->pa > 2 * M_PI)
			cubed->pa -= 2 * M_PI;
		cubed->stepX = cos(cubed->pa) * 0.05;
		cubed->stepY = sin(cubed->pa) * 0.05;
		cubed->stepXctrlA = cos(cubed->pa - 0.5 * M_PI) * 0.05;
		cubed->stepYctrlA = sin(cubed->pa - 0.5 * M_PI) * 0.05;
		cubed->stepXctrlD = cos(cubed->pa + 0.5 * M_PI) * 0.05;
		cubed->stepYctrlD = sin(cubed->pa + 0.5 * M_PI) * 0.05;
		reset_settings(cubed);
	}
	
}