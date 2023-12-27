#include "../../include/cubed.h"
#include <string.h>

// check if everything is initialized correctly

void    init_cubed(t_cubed *cubed, t_mlx *mlx, t_screen *screen, char *argv)
{
	bzero(cubed, sizeof(*cubed));
	cubed->map = NULL;
	cubed->map_val = NULL;
	cubed->start_pos[Y] = 0;
	cubed->start_pos[X] = 0;
	cubed->start_cardinal_point = 0;
	cubed->ceiling_color[0] = 0;
	cubed->ceiling_color[1] = 0;
	cubed->floor_color[0] = 0;
	cubed->floor_color[1] = 0;
	cubed->width = 0;
	cubed->height = 0;
	cubed->argv = argv;
	// todo: init mlx?
	cubed->mlx = mlx;
	cubed->screen = screen;
}


void	init_mlx(t_mlx *mlx) 
{
	bzero(mlx, sizeof(*mlx));

}

void    init_screen(t_screen *screen)
{
	bzero(screen, sizeof(*screen));
}

void	input_initialization(t_cubed *cubed, t_mlx *mlx, t_screen *screen, char *argv)
{
	init_cubed(cubed, mlx, screen, argv);
	init_mlx(mlx);
	init_screen(screen);
}
