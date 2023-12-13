#include "../../include/cubed.h"
#include <string.h>

// check if everything is initialized correctly

void    init_cubed(t_cubed *cubed, t_mlx *mlx, t_screen *screen, char *argv)
{
	bzero(cubed, sizeof(*cubed));
	cubed->map = NULL;
	cubed->start_pos = NULL;
	cubed->argv = argv;
	cubed->ceiling_color = NULL;
	cubed->floor_color = NULL;
	cubed->EA = NULL;
	cubed->WE = NULL;
	cubed->NO = NULL;
	cubed->SO = NULL;
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