#include "../../include/cubed.h"

void draw_screen(t_cubed *cubed)
{
	draw_floor_and_ceiling(cubed);
	mini_map(cubed);
	raycasting(cubed);
	// cubed->draw_screen = false;
}

void	reset_settings(t_cubed *cubed)
{
	// cubed->raycasting_is_done = false;
	// cubed->draw_screen = true;
	draw_screen(cubed);
}

static bool	initialize_cubed(t_cubed *cubed)
{
	// screen variables
	cubed->screen_width = 800;
	cubed->screen_height = 480;
	cubed->map_width = (double)column;
	cubed->map_height = (double)row;
	cubed->mini_map_width = 300;
	cubed->mini_map_height = 300;
	cubed->mini_map_start_y = cubed->screen_height - cubed->mini_map_height;
	// cubed->multiplier_mini_map_x = cubed->mini_map_width / column;
	// cubed->multiplier_mini_map_y = cubed->mini_map_height / row;
	// cubed->grid_width = cubed->mini_map_width / (double)row;
	// cubed->grid_height = cubed->mini_map_height / (double)column;0
	cubed->grid_width = 20;
	cubed->grid_height = 20;
	cubed->draw_screen = true;

	// player variables
	cubed->posX = 2;
	cubed->posY = 2;
	cubed->mapX = 0;
	cubed->mapY = 0;
	cubed->dirX = 0.0;
	cubed->dirY = 0.0;
	cubed->pa = 0;
	cubed->fov = 0;
	cubed->stepX = 0;
	cubed->stepY = 0;
	cubed->raycasting_is_done = false;
	cubed->x_ray_length = 0;
	cubed->y_ray_length = 0;
	cubed->side = false;
	cubed->player_to_grid_x = 0;
	cubed->player_to_grid_y = 0;
	cubed->mapX = (int)cubed->posX;
	cubed->mapY = (int)cubed->posY;

	return (true);
}

int32_t start_cubed(void)
{
	t_cubed	cubed;
	
	if (!initialize_cubed(&cubed))
		return (1);
	if (!(cubed.mlx = mlx_init(cubed.screen_width, cubed.screen_height, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(cubed.image = mlx_new_image(cubed.mlx, cubed.screen_width, cubed.screen_height)))
	{
		mlx_close_window(cubed.mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(cubed.mlx, cubed.image, 0, 0) == -1)
	{
		mlx_close_window(cubed.mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	draw_screen(&cubed);
	mlx_loop_hook(cubed.mlx, hooks, &cubed);
	mlx_loop(cubed.mlx);
	mlx_terminate(cubed.mlx);
	return (EXIT_SUCCESS);
}
