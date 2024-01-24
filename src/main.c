// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	(void)argv;
//     // t_cubed     cubed;
//     // t_mlx       mlx;
//     // t_screen    screen;

//     // error_handling(argc, argv);
//     // input_initialization(&cubed, &mlx, &screen, argv[1]);
//     // input_parsing(&cubed, argv[1]);
//     // printf("%i\n", )

// 	printf("Raycasting !");
//     return (0);
// }

#include "../include/cubed.h"

#define BLOCK_WIDTH 25
#define BLOCK_HEIGHT 25

double	obstacle_startX;
double	obstacle_endX;
double	obstacle_startY;
double	obstacle_endY;
double	diff_x;
double	diff_y;
double	angle;


static int worldMap[column][row]=
{
	{1, 1, 1, 1, 1, 1, 1},
	{1, 1, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1}
};

void draw_color_stripe(int32_t startX, int32_t endX, int32_t startY, int32_t endY, uint32_t color, t_cubed *cubed)
{
	int32_t	y;
	int32_t	x;

	y = startY;
	while (y < endY)
    {
		x = startX;
       while(x < endX)
        {
            mlx_put_pixel(cubed->image, x, y, color);
			x++;
        }
		y++;
	}
}

void	draw_floor_and_ceiling(t_cubed *cubed)
{
	uint32_t colorBrown = ft_pixel(139, 69, 19, 0xFF);
	uint32_t colorPurple = ft_pixel(160, 32, 240, 0xFF);

	draw_color_stripe(0, cubed->screen_width - 1, 0, cubed->screen_height / 2 - 1, colorPurple, cubed);
	draw_color_stripe(0, cubed->screen_width - 1, cubed->screen_height / 2 - 1, cubed->screen_height - 1, colorBrown, cubed);
}

void	drawPoint(t_cubed *cubed, double posX, double posY, uint32_t color, int thickness)
{
	int	y = 0;

	while (y < cubed->mapHeight && posY > 0 && posY < cubed->mapHeight)
	{
		int x = 0;
		while (x < cubed->mapWidth && posX > 0 && posX < cubed->mapWidth)
		{
			if ((x > posX - thickness && x < posX + thickness)
						&& (y > posY - thickness && y < posY + thickness)
						&& (x != posX && y != posY))
					mlx_put_pixel(cubed->image, round(x), round(y) + cubed->mini_map_start_y, color);
			x++;
		}
		y++;
	}
}

bool	checkRay(t_cubed *cubed, double x_target, double y_target)
{
	int	x;
	int	y;

	y = 0;
	while (y < column)
	{
		x = 0;
		while (x < row)
		{
			if (worldMap[y][x] == 1)
			{
				if ((x_target >= x * cubed->widthBlock  && x_target <= (x + 1) * cubed->widthBlock + 1) &&
						(y_target >= y * cubed->heightBlock && y_target <= (y + 1) * cubed->heightBlock + 1))
					return (true);
			}
			x++;
		} 
		y++;
	}
	return (false);
}

void	get_directions(t_cubed *cubed, double pa)
{
	if (pa > 2 * M_PI)
		pa -= 2 * M_PI;
	if (pa >= (M_PI / 2) && pa < (M_PI * 3/2)) 
		cubed->dirX = -1;
	else
		cubed->dirX = 1;
	if (pa >= 0 && pa < M_PI)
		cubed->dirY = 1;
	else
		cubed->dirY = -1;
}

void	getAxAy(t_cubed *cubed, double *Ax, double *Ay)
{
	double	pa = cubed->pa + cubed->fov;

	get_directions(cubed, pa);
	if (cubed->dirX == 1)
		*Ax = cubed->posX;
	else if (cubed->dirX == -1)
		*Ax = cubed->mapWidth - cubed->posX;
	// else // not sure about this
	// 	*Ax = 0;
	if (cubed->dirY == 1)
		*Ay = cubed->posY;
	else if (cubed->dirY == -1)
		*Ay = cubed->mapHeight - cubed->posY;
	// else // not sure about this
	// 	*Ay = 0;

	while (*Ax >= 0)
		*Ax -= cubed->widthBlock;
	if (cubed->dirX == 1)
		*Ax *= -1;
	
	while (*Ay >= 0)
		*Ay -= cubed->heightBlock;
	if (cubed->dirY == 1)
		*Ay *= -1;
}

bool	x_ray_is_shortest(t_cubed *cubed, double Ax, double Ay)
{
	double	pa = cubed->pa + cubed->fov;

	cubed->x_ray_length = sqrt(Ax * Ax + (Ax * sin(pa) / cos(pa)) * (Ax * sin(pa) / cos(pa)));
	cubed->y_ray_length = sqrt((Ay * cos(pa) / sin(pa)) * (Ay * cos(pa) / sin(pa)) + Ay * Ay);

	if (cubed->x_ray_length < cubed->y_ray_length)
		return (true);
	return (false);
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

t_hit	is_hit(t_cubed *cubed, double Ax, double Ay, bool x_ray_is_shortest)
{
	uint32_t	colorOrange = ft_pixel(255, 140, 0, 0xFF);
	double		pa = cubed->pa + cubed->fov;
	double		x;
	double		y;
	double		dot_thickness;

	dot_thickness = 2;
	x = 0;
	y = 0;
	if (x_ray_is_shortest) // if true the x-ray has a hit, that means a wall is hit horizontally
	{
		x = cubed->posX + Ax;						// x-coordinate of hit
		y = cubed->posY + Ax * sin(pa) / cos(pa);	// y-coordinate of hit
		if (checkRay(cubed, x, y)) // change name
		{
			drawPoint(cubed, x, y, colorOrange, dot_thickness); // we want to move these to another function to draw everything at once
			cubed->side = false;
			return (x_ray_hit);
		}
	} // i < cubed->screen_width
	else // the y-ray has a hit, that means a wall is hit vertically
	{
		x = cubed->posX + Ay * cos(pa) / sin(pa);	// x-coordinate of hit
		y = cubed->posY + Ay;						// y-coordinate of hit
		if (checkRay(cubed, x, y))
		{
			drawPoint(cubed, x, y, colorOrange, dot_thickness);	// we want to move these to another function to draw everything at once
			// draw_wall(cubed, Ax, Ay, x);			// we want to move these to another function to draw everything at once
			cubed->side = true;
			return (y_ray_hit);
		}
	}
	return (no_hit);
}

void	ray_loop(t_cubed *cubed, double Ax, double Ay)
{
	bool		xRay_is_shortest_bool;
	t_hit		is_hit_result;

	xRay_is_shortest_bool = false;
	is_hit_result = no_hit;
	while (1)
	{
		xRay_is_shortest_bool = x_ray_is_shortest(cubed, Ax, Ay);
		is_hit_result = is_hit(cubed, Ax, Ay, xRay_is_shortest_bool);
		if (!xRay_is_shortest_bool && is_hit_result == y_ray_hit)
			return ;
		else if (xRay_is_shortest_bool && is_hit_result == x_ray_hit)
			return ;
		if (xRay_is_shortest_bool)
		{
			if (cubed->dirX == 1)
				Ax += cubed->widthBlock;
			else
				Ax -= cubed->widthBlock;
		}
		else
		{
			if (cubed->dirY == 1)
				Ay += cubed->heightBlock;
			else
				Ay -= cubed->heightBlock;
		}
	}
}

void	raycasting(void *param)
{
	t_cubed	*cubed = param;
	double 	iterations;

	iterations = 0.01;
	cubed->fov = M_PI / -6;
	while (cubed->fov <= M_PI / 6)
	{
		getAxAy(cubed, &cubed->Ax, &cubed->Ay);
		ray_loop(cubed, cubed->Ax, cubed->Ay);
		cubed->fov += iterations;
	}
}

void draw_screen(void* param)
{
	t_cubed	*cubed;

	cubed = param;
	draw_floor_and_ceiling(param);
	mini_map(param);
	raycasting(param);
	cubed->draw_screen = false;
}

void	reset_settings(t_cubed *cubed)
{
	cubed->raycasting_is_done = false;
	cubed->draw_screen = true;
	draw_screen(cubed);
}

bool	initialize_cubed(t_cubed *cubed)
{
	cubed->posX = 50;
	cubed->posY = 60;
	cubed->dirX = 0.0;
	cubed->dirY = 0.0;
	cubed->screen_width = 840;
	cubed->screen_height = 800;
	cubed->mapWidth = 200;
	cubed->mapHeight = 200;
	cubed->mini_map_start_y = cubed->screen_height - cubed->mapHeight;
	cubed->pa = 1.973598;
	cubed->fov = 0;
	cubed->pdx = 0;
	cubed->pdy = 0;
	cubed->widthBlock = cubed->mapWidth / (double)row;
	cubed->heightBlock = cubed->mapHeight / (double)column;
	cubed->raycasting_is_done = false;
	cubed->x_ray_length = 0;
	cubed->y_ray_length = 0;
	cubed->side = false;
	cubed->Ax = 0; // length_till_x_axis
	cubed->Ay = 0; // length_till_y_axis
	cubed->draw_screen = true;
	return (true);
}

int32_t main(void)
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
