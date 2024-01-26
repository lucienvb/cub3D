#include "../../include/cubed.h"

static int worldMap[column][row]=
{
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}
};

// static int worldMap[column][row]=
// {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
//   {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
//   {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };

static bool	x_ray_is_shortest(t_cubed *cubed, double player_to_grid_x, double player_to_grid_y)
{
	double	pa;
	double	y_calc_x_ray;
	double	x_calc_y_ray;

	pa = cubed->pa + cubed->fov;

	double	x_addition;
	double	y_addition;
	x_addition = 0;
	y_addition = 0;
	// if (cubed->dirX == -1)
	// 	x_addition = 10;
	// if (cubed->dirY == -1)
	// 	y_addition = 10;

	y_calc_x_ray = player_to_grid_x * sin(pa) / cos(pa);
	x_calc_y_ray = player_to_grid_y * cos(pa) / sin(pa);
	cubed->x_ray_length = sqrt(player_to_grid_x * player_to_grid_x + y_calc_x_ray * y_calc_x_ray);
	cubed->y_ray_length = sqrt(x_calc_y_ray * x_calc_y_ray + player_to_grid_y * player_to_grid_y);

	if (cubed->x_ray_length + x_addition < cubed->y_ray_length + y_addition)
    {
        cubed->current_ray_length = cubed->x_ray_length;
		return (true);
    }
    cubed->current_ray_length = cubed->y_ray_length;
	return (false);
}

static bool	ray_hits_wall(t_cubed *cubed, double x_target, double y_target)
{
	size_t	x;
	size_t	y;
	int		addition;

	addition = 1;
	y = 0;
	while (y < column)
	{
		x = 0;
		while (x < row)
		{
			if (worldMap[y][x] == 1)
			{
				if ((x_target >= x * cubed->grid_width  && x_target < ((x + 1) * cubed->grid_width) + addition) &&
						(y_target >= y * cubed->grid_height && y_target < ((y + 1) * cubed->grid_height) + addition))
						{
							// printf("%f < x_target: %f < %f\t",  x * cubed->grid_width, x_target, (x + 1) * cubed->grid_width + addition);
							// printf("%f < y_target: %f < %f\n",  y * cubed->grid_height, y_target, (y + 1) * cubed->grid_height + addition);
					return (true);
						}
			}
			x++;
		} 
		y++;
	}
	return (false);
}

static t_hit	is_hit(t_cubed *cubed, double player_to_grid_x, double player_to_grid_y, bool x_ray_is_shortest)
{
	double		pa = cubed->pa + cubed->fov;
	double		x;
	double		y;
	
	uint32_t	colorOrange = ft_pixel(255, 140, 0, 0xFF);
	uint32_t	colorBlue = ft_pixel(0, 0, 255, 0xFF);
	double		dot_thickness;
	dot_thickness = 2;

	x = 0;
	y = 0;
	if (x_ray_is_shortest) // if true the x-ray has a hit, that means a wall is hit horizontally
	{
		x = cubed->posX + player_to_grid_x;						// x-coordinate of hit
		y = cubed->posY + player_to_grid_x * sin(pa) / cos(pa);	// y-coordinate of hit
		if (ray_hits_wall(cubed, x, y)) // change name
		{
			drawPoint(cubed, x, y, colorOrange, dot_thickness); // we want to move these to another function to draw everything at once
			
            cubed->side = true;
			return (x_ray_hit);
		}
	}
	else // the y-ray has a hit, that means a wall is hit vertically
	{
		x = cubed->posX + player_to_grid_y * cos(pa) / sin(pa);	// x-coordinate of hit
		y = cubed->posY + player_to_grid_y;						// y-coordinate of hit
		if (ray_hits_wall(cubed, x, y))
		{
			drawPoint(cubed, x, y, colorBlue, dot_thickness);	// we want to move these to another function to draw everything at once
			cubed->side = false;
			return (y_ray_hit);
		}
	}
	return (no_hit);
}

static void	ray_loop(t_cubed *cubed, double player_to_grid_x, double player_to_grid_y, size_t *wall_position)
{
	bool		xRay_is_shortest_bool;
	t_hit		is_hit_result;

	xRay_is_shortest_bool = false;
	is_hit_result = no_hit;
	while (1)
	{
		xRay_is_shortest_bool = x_ray_is_shortest(cubed, player_to_grid_x, player_to_grid_y);
		is_hit_result = is_hit(cubed, player_to_grid_x, player_to_grid_y, xRay_is_shortest_bool);
		if (!xRay_is_shortest_bool && is_hit_result == y_ray_hit)
        {
			printf("y_ray has a hit\t");
			printf("x_ray_len: %f, y_ray_len: %f\n", cubed->x_ray_length, cubed->y_ray_length);
            draw_wall(cubed, wall_position);
			return ;
        }
		else if (xRay_is_shortest_bool && is_hit_result == x_ray_hit)
		{
			printf("x_ray has a hit\t");
			printf("x_ray_len: %f, y_ray_len: %f\n", cubed->x_ray_length, cubed->y_ray_length);
            draw_wall(cubed, wall_position);
			return ;
        }
		if (xRay_is_shortest_bool)
		{
			if (cubed->dirX == 1)
				player_to_grid_x += cubed->grid_width;
			else
				player_to_grid_x -= cubed->grid_width;
		}
		else
		{
			if (cubed->dirY == 1)
				player_to_grid_y += cubed->grid_height;
			else
				player_to_grid_y -= cubed->grid_height;
		}
	}
}

void	raycasting(t_cubed *cubed)
{
	double 	iterations;
    size_t  wall_position;

	printf("\nnew raycasting cycle\n\n");
    wall_position = 0;
	iterations = 0.01;
	cubed->fov = M_PI / -6;
	while (cubed->fov <= M_PI / 6)
	{
		get_player_to_grid(cubed, &cubed->player_to_grid_x, &cubed->player_to_grid_y);
		ray_loop(cubed, cubed->player_to_grid_x, cubed->player_to_grid_y, &wall_position);
		cubed->fov += iterations;
	}
}