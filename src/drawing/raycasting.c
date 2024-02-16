#include "../../include/cubed.h"

// static int worldMap[column][row]=
// {
// 	{1, 1, 1, 1, 1, 1, 1, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 1, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 1, 0, 1},
// 	{1, 0, 0, 0, 0, 1, 0, 1},
// 	{1, 0, 1, 0, 0, 0, 0, 1},
// 	{1, 0, 1, 1, 0, 0, 0, 1},
// 	{1, 0, 0, 1, 1, 0, 0, 1},
// 	{1, 0, 0, 0, 1, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 1, 1, 1, 1, 1, 1, 1}
// };

// static int worldMap[column][row]=
// {
// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };


// static int worldMap[column][row]=
// {
// 	{1, 1, 1, 1, 1, 1, 1, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 1, 1, 0, 1},
// 	{1, 0, 0, 0, 0, 1, 0, 1},
// 	{1, 0, 0, 0, 0, 1, 0, 1},
// 	{1, 0, 1, 1, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 1, 1, 1, 1, 1, 1, 1}
// };

static int worldMap[column][row]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

static bool	x_ray_is_shortest(t_cubed *cubed, double player_to_grid_x, double player_to_grid_y)
{
	double	pa;
	double	y_calc_x_ray;
	double	x_calc_y_ray;

	pa = cubed->pa + cubed->fov;

	y_calc_x_ray = player_to_grid_x * sin(pa) / cos(pa);
	x_calc_y_ray = player_to_grid_y * cos(pa) / sin(pa);

	cubed->x_ray_length = sqrt(player_to_grid_x * player_to_grid_x + y_calc_x_ray * y_calc_x_ray);
	cubed->y_ray_length = sqrt(x_calc_y_ray * x_calc_y_ray + player_to_grid_y * player_to_grid_y);

	if (cubed->x_ray_length < cubed->y_ray_length)
		return (true);
	return (false);
}

static t_hit	is_hit(t_cubed *cubed, double player_to_grid_x, double player_to_grid_y, bool x_ray_is_shortest)
{
	double		dot_thickness;
	double		draw_ray_hit;
	uint32_t	colorOrange;
	uint32_t	colorBlue;
	double		pa;
	double		x;
	double		y;
	
	draw_ray_hit = false;

	colorOrange = ft_pixel(255, 140, 0, 0xFF);
	colorBlue = ft_pixel(0, 0, 255, 0xFF);
	pa = cubed->pa + cubed->fov;
	dot_thickness = 2;
	x = 0;
	y = 0;
	if (x_ray_is_shortest)
	{
		x = ((cubed->posX + player_to_grid_x) * cubed->grid_width);
		y = ((cubed->posY + player_to_grid_x * sin(pa) / cos(pa)) * cubed->grid_height);
		if (worldMap[cubed->mapY][cubed->mapX + (int)cubed->dirX] == 1)
		{
			if (draw_ray_hit)
				drawPoint(cubed, x, y, colorOrange, dot_thickness);
            cubed->side = true;
			return (x_ray_hit);
		}
	}
	else
	{
		x = ((cubed->posX + player_to_grid_y * cos(pa) / sin(pa)) * cubed->grid_width);
		y = ((cubed->posY + player_to_grid_y) * cubed->grid_height);
		if (worldMap[cubed->mapY + (int)cubed->dirY][cubed->mapX] == 1)
		{
			if (draw_ray_hit)
				drawPoint(cubed, x, y, colorBlue, dot_thickness);
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
	(void)wall_position;

	bool		draw_walls = true;

	xRay_is_shortest_bool = false;
	is_hit_result = no_hit;
	while (1)
	{
		xRay_is_shortest_bool = x_ray_is_shortest(cubed, player_to_grid_x, player_to_grid_y);
		is_hit_result = is_hit(cubed, player_to_grid_x, player_to_grid_y, xRay_is_shortest_bool);
		if (!xRay_is_shortest_bool && is_hit_result == y_ray_hit)
        {
			get_perp_wall_dist(cubed, 0);
			if (draw_walls)
			    draw_wall(cubed, wall_position);
			return ;
        }
		else if (xRay_is_shortest_bool && is_hit_result == x_ray_hit)
		{
			get_perp_wall_dist(cubed, 1);
			if (draw_walls)
				draw_wall(cubed, wall_position);
			return ;
        }
		if (xRay_is_shortest_bool)
		{
			if (cubed->dirX == 1)
			{
				player_to_grid_x += 1;
				cubed->mapX++;
			}
			else
			{
				player_to_grid_x -= 1;
				cubed->mapX--;
			}
		}
		else
		{
			if (cubed->dirY == 1)
			{
				player_to_grid_y += 1;
				cubed->mapY++;
			}
			else
			{
				player_to_grid_y -= 1;
				cubed->mapY--;
			}
		}
	}
}

void	raycasting(t_cubed *cubed)
{
    size_t  wall_position;
	double 	iterations;

	// printf("\nnew raycasting cycle\n\n");
	iterations = 1 / cubed->screen_width;
	cubed->fov = M_PI / -6;
    wall_position = 0;
	clean_screen(cubed);
	while (cubed->fov <= M_PI / 6)
	{
		cubed->mapX = (int)cubed->posX;
		cubed->mapY = (int)cubed->posY;
		get_player_to_grid(cubed, &cubed->player_to_grid_x, &cubed->player_to_grid_y);
		ray_loop(cubed, cubed->player_to_grid_x, cubed->player_to_grid_y, &wall_position);
		cubed->fov += iterations;
	}
}