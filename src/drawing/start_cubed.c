#include "../../include/cubed.h"

static void	position_mini_map(t_cubed *cubed)
{
	double	distanceX;
	double	distanceY;
	
	distanceX = -(cubed->posX - (cubed->mini_map_size / 2));
	distanceY = -(cubed->posY - (cubed->mini_map_size / 2));
	cubed->image->instances[0].x = distanceX * cubed->grid_width;
	cubed->image->instances[0].y = distanceY * cubed->grid_height;
	// mlx_set_instance_depth(cubed->image->instances, 1);
	// mlx_set_instance_depth(cubed->image_game->instances, 2);
}

void draw_screen(t_cubed *cubed)
{
	// draw_floor_and_ceiling(cubed);
	mini_map(cubed);
	raycasting(cubed);
	position_mini_map(cubed);
	clean_screen(cubed);
	draw_player_mini_map(cubed);
}

void	reset_settings(t_cubed *cubed)
{
	position_mini_map(cubed);
	clean_screen(cubed);
	raycasting(cubed);
	draw_player_mini_map(cubed);

}

static bool	initialize_cubed(t_cubed *cubed)
{
	// screen variables
	cubed->screen_width = 800;
	cubed->screen_height = 800;
	cubed->map_width = (double)row;
	cubed->map_height = (double)column;
	cubed->grid_width = 40;
	cubed->grid_height = 40;
	cubed->mini_map_width = (double)row * cubed->grid_width;
	cubed->mini_map_height = (double)column * cubed->grid_height;
	cubed->mini_map_start_y = cubed->screen_height - cubed->mini_map_height;
	cubed->mini_map_size = 6;
	cubed->mini_map_middle = cubed->mini_map_size * cubed->grid_width / 2;
	cubed->draw_screen = true;

	// player variables
	cubed->posX = 2;
	cubed->posY = 3;
	cubed->mapX = 0;
	cubed->mapY = 0;
	cubed->dirX = 0.0;
	cubed->dirY = 0.0;
	cubed->pa = M_PI;
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
	if (!(cubed.mlx = mlx_init((int32_t)cubed.screen_width, (int32_t)cubed.screen_height, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(cubed.image = mlx_new_image(cubed.mlx, (int32_t)cubed.mini_map_width, (int32_t)cubed.mini_map_height)))
	{
		mlx_close_window(cubed.mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(cubed.image_game = mlx_new_image(cubed.mlx, (int32_t)cubed.screen_width, (int32_t)cubed.screen_height)))
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
	if (mlx_image_to_window(cubed.mlx, cubed.image_game, 0, 0) == -1)
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
