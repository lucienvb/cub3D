#include "../../include/cubed.h"

int	create_image_mlx(t_cubed *cubed)
{
if (!(cubed->mlx = mlx_init((int32_t)cubed->screen_width,
	(int32_t)cubed->screen_height, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(FAILURE);
	}
	if (!(cubed->image = mlx_new_image(cubed->mlx,
		(int32_t)cubed->mini_map_width, (int32_t)cubed->mini_map_height)))
	{
		mlx_close_window(cubed->mlx);
		puts(mlx_strerror(mlx_errno));
		return(FAILURE);
	}
	if (!(cubed->image_game = mlx_new_image(cubed->mlx,
		(int32_t)cubed->screen_width, (int32_t)cubed->screen_height)))
	{
		mlx_close_window(cubed->mlx);
		puts(mlx_strerror(mlx_errno));
		return(FAILURE);
	}
	return (SUCCESS);
}

int	image_to_window_mlx(t_cubed *cubed)
{
	if (mlx_image_to_window(cubed->mlx, cubed->image, 0, 0) == -1)
	{
		mlx_close_window(cubed->mlx);
		puts(mlx_strerror(mlx_errno));
		return(FAILURE);
	}
	if (mlx_image_to_window(cubed->mlx, cubed->image_game, 0, 0) == -1)
	{
		mlx_close_window(cubed->mlx);
		puts(mlx_strerror(mlx_errno));
		return(FAILURE);
	}
	return (SUCCESS);
}
