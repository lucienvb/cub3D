#include "../../include/cubed.h"
#include <string.h>

// check if everything is initialized correctly
static void	init_screen(t_cubed *cubed)
{
	cubed->screen_width = 800;
	cubed->screen_height = 800;
	cubed->map_width = cubed->max_column;
	cubed->map_height = cubed->total_row;
	cubed->grid_width = 40;
	cubed->grid_height = 40;
	cubed->mini_map_width = cubed->max_column  * cubed->grid_width;
	cubed->mini_map_height = cubed->total_row * cubed->grid_height; 
	cubed->mini_map_start_y = cubed->screen_height - cubed->mini_map_height;
	cubed->mini_map_size = 6;
	cubed->mini_map_middle = cubed->mini_map_size * cubed->grid_width / 2;
	cubed->mini_map_surface = cubed->mini_map_size * cubed->grid_width;;
	cubed->draw_screen = true;
	cubed->stepXctrlA = 0;
	cubed->stepYctrlA = 0;
	cubed->stepXctrlD = 0;
	cubed->stepYctrlD = 0;
	cubed->colorTransparent = ft_pixel(0, 0, 0, 0);
	cubed->colorOrange = ft_pixel(255, 140, 0, 0xFF);
	cubed->colorBlue = ft_pixel(0, 0, 255, 0xFF);
	cubed->percentage_wall_width = 0;

}

static double	set_pa(t_cubed *cubed)
{
	printf("\n%c = pa", cubed->start_cardinal_point);
	if (cubed->start_cardinal_point == 'W')
		return (1 * M_PI);
	if (cubed->start_cardinal_point == 'E')
		return (0 * M_PI);
	if (cubed->start_cardinal_point == 'S')
		return (0.5 * M_PI);
	if (cubed->start_cardinal_point == 'N')
		return (1.5 * M_PI);
	return (0);
}
static void	init_player(t_cubed *cubed)
{
	cubed->posX = cubed->start_pos[X];
	cubed->posY = cubed->start_pos[Y];
	cubed->mapX = 0;
	cubed->mapY = 0;
	cubed->dirX = 0.0;
	cubed->dirY = 0.0;
	cubed->pa = set_pa(cubed);
	cubed->fov = 0;
	cubed->stepX = 0;
	cubed->stepY = 0;
	cubed->raycasting_is_done = false;
	cubed->x_ray_length = 0;
	cubed->y_ray_length = 0;
	cubed->shortest_ray_length = 1000;
	cubed->side = false;
	cubed->player_to_grid_x = 5;
	cubed->player_to_grid_y = 5;
	cubed->mapX = (int)cubed->posX;
	cubed->mapY = (int)cubed->posY;
}

void	init_setup(t_cubed *cubed, char *argv)
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
	cubed->max_column = 0;
	cubed->total_row = 0;
}

void	init_drawing(t_cubed *cubed)
{
	init_screen(cubed);
	init_player(cubed);
}