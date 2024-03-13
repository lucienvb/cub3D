/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/08 13:30:48 by lvan-bus      #+#    #+#                 */
/*   Updated: 2024/03/13 15:45:03 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static bool	x_ray_is_shortest(t_cubed *cubed, double player_to_grid_x,
	double player_to_grid_y)
{
	double	pa;
	double	y_calc_x_ray;
	double	x_calc_y_ray;

	pa = cubed->pa + cubed->fov;
	y_calc_x_ray = player_to_grid_x * sin(pa) / cos(pa);
	x_calc_y_ray = player_to_grid_y * cos(pa) / sin(pa);
	cubed->x_ray_length = sqrt(player_to_grid_x * player_to_grid_x
			+ y_calc_x_ray * y_calc_x_ray);
	cubed->y_ray_length = sqrt(x_calc_y_ray * x_calc_y_ray
			+ player_to_grid_y * player_to_grid_y);
	if (cubed->x_ray_length < cubed->y_ray_length)
		return (true);
	return (false);
}

static void	ray_loop_increase(t_cubed *cubed, double *player_to_grid_x,
	double *player_to_grid_y, bool xray_is_shortest)
{
	if (xray_is_shortest && cubed->dirX == 1)
	{
		*player_to_grid_x += 1;
		cubed->mapX++;
	}
	else if (xray_is_shortest && cubed->dirX != 1)
	{
		*player_to_grid_x -= 1;
		cubed->mapX--;
	}
	else if (!xray_is_shortest && cubed->dirY == 1)
	{
		*player_to_grid_y += 1;
		cubed->mapY++;
	}
	else if (!xray_is_shortest && cubed->dirY != 1)
	{
		*player_to_grid_y -= 1;
		cubed->mapY--;
	}
}

static void	ray_loop(t_cubed *cubed, double player_to_grid_x,
	double player_to_grid_y, size_t *wall_position)
{
	bool	xray_is_shortest;
	t_hit	is_hit_result;

	xray_is_shortest = false;
	is_hit_result = no_hit;
	while (1)
	{
		xray_is_shortest = x_ray_is_shortest(cubed, player_to_grid_x,
				player_to_grid_y);
		is_hit_result = is_hit(cubed, player_to_grid_x, player_to_grid_y,
				xray_is_shortest);
		if (!xray_is_shortest && is_hit_result == y_ray_hit)
		{
			draw_wall(cubed, wall_position, xray_is_shortest);
			return ;
		}
		else if (xray_is_shortest && is_hit_result == x_ray_hit)
		{
			draw_wall(cubed, wall_position, xray_is_shortest);
			return ;
		}
		ray_loop_increase(cubed, &player_to_grid_x, &player_to_grid_y,
			xray_is_shortest);
	}
}

void	raycasting(t_cubed *cubed)
{
	size_t	wall_position;
	double	iterations;

	iterations = 1 / cubed->screenW;
	cubed->fov = M_PI / -6;
	wall_position = 0;
	clean_screen(cubed);
	while (cubed->fov <= M_PI / 6)
	{
		cubed->mapX = (int)cubed->posX;
		cubed->mapY = (int)cubed->posY;
		get_player_to_grid(cubed, &cubed->player_to_grid_x,
			&cubed->player_to_grid_y);
		ray_loop(cubed, cubed->player_to_grid_x, cubed->player_to_grid_y,
			&wall_position);
		cubed->fov += iterations;
	}
}
