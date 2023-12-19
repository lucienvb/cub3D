#include "../../include/cubed.h"
#include <string.h>

// check if everything is initialized correctly

void    init_cubed(t_cubed *cubed, t_mlx *mlx, t_screen *screen, char *argv)
{
	bzero(cubed, sizeof(*cubed));
	cubed->map = NULL;
	cubed->pos_x = 0;
	cubed->pos_y = 0;
	cubed->argv = argv;
	cubed->ceiling_color[0] = '\0';
	cubed->floor_color[0] = '\0';
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
