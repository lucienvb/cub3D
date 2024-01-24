#include "../include/cubed.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	uint32_t	status;
    // t_cubed     cubed;
    // t_mlx       mlx;
    // t_screen    screen;

    // error_handling(argc, argv);
    // input_initialization(&cubed, &mlx, &screen, argv[1]);
    // input_parsing(&cubed, argv[1]);
    // printf("%i\n", )
	status = start_cubed();
    return (status);
}

// void	draw_vertical(int x, int drawStart, int endStart, uint32_t color, t_cubed *cubed)
// {
// 	// (void)cubed;
// 	// uint32_t	colorYellow = ft_pixel(255, 165, 0, 0xFF);

// 	int y = drawStart;

// 	// printf("y(drawStart): %i, endStart: %i\n", y, endStart);
// 	while (y < endStart)
// 	{
// 		// printf("test draw vertical in while loop\n");
// 		mlx_put_pixel(image, x, y, color);
// 		y++;
// 	}
// }

// void	draw_walls(void *param)
// {
// 	size_t	i;
// 	size_t	end;
// 	// size_t	index;
// 	t_cubed *cubed = param;

// 	i = 0;

// 	end = cubed->intersections_index;
// 	while (i < end)
// 	{
// 		double	x = cubed->intersections[i].x;
// 		double	y = cubed->intersections[i].y;
// 		printf("on index %zu the coordinates are: (x: %f, y: %f)\n",i, x, y);

// 		draw_one_wall(cubed, cubed->Ax, cubed->Ay, i);
// 		i++;
// 	}
// }



