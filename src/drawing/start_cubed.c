#include "../../include/cubed.h"

static void	position_mini_map(t_cubed *cubed)
{
	double	distanceX;
	double	distanceY;
	
	distanceX = - (cubed->posX - (cubed->mini_map_size / 2));
	distanceY = - (cubed->posY - (cubed->mini_map_size / 2));
	cubed->image->instances[0].x = distanceX * cubed->grid_width;
	cubed->image->instances[0].y = distanceY * cubed->grid_height;
	// mlx_set_instance_depth(cubed->image->instances, 1);
	// mlx_set_instance_depth(cubed->image_game->instances, 2);
}

void draw_screen(t_cubed *cubed)
{
	mini_map(cubed);
	raycasting(cubed);
	position_mini_map(cubed);
	clean_screen(cubed);
	draw_player_mini_map(cubed);
	reset_settings(cubed);
}

void	reset_settings(t_cubed *cubed)
{
	position_mini_map(cubed);
	clean_screen(cubed);
	raycasting(cubed);
	draw_player_mini_map(cubed);
}

int32_t start_cubed(t_cubed *cubed)
{
	if (create_image_mlx(cubed) == FAILURE)
		return (FAILURE);
	if (image_to_window_mlx(cubed) == FAILURE)
		return (FAILURE);
	draw_screen(cubed);
	mlx_loop_hook(cubed->mlx, hooks, cubed);
	mlx_loop(cubed->mlx);
	mlx_terminate(cubed->mlx);
	return (SUCCESS);
}
