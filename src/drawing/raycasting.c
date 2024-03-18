/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: chaverttermaat <chaverttermaat@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 11:52:36 by chavertterm   #+#    #+#                 */
/*   Updated: 2024/03/18 12:00:29 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static bool	x_ray_is_shortest(t_cubed *c, double player_to_grid_x,
double player_to_grid_y)
{
	double	pa;
	double	y_calc_x_ray;
	double	x_calc_y_ray;

	pa = c->pa + c->fov;
	y_calc_x_ray = player_to_grid_x * sin(pa) / cos(pa);
	x_calc_y_ray = player_to_grid_y * cos(pa) / sin(pa);
	c->x_ray_length = sqrt(player_to_grid_x * player_to_grid_x + y_calc_x_ray
			* y_calc_x_ray);
	c->y_ray_length = sqrt(x_calc_y_ray * x_calc_y_ray + player_to_grid_y
			* player_to_grid_y);
	if (c->x_ray_length < c->y_ray_length)
		return (true);
	return (false);
}

static void	ray_loop_increase(t_cubed *c, double *player_to_grid_x,
double *player_to_grid_y, bool xray_is_shortest)
{
	if (xray_is_shortest && c->dirX == 1)
	{
		*player_to_grid_x += 1;
		c->mapX++;
	}
	else if (xray_is_shortest && c->dirX != 1)
	{
		*player_to_grid_x -= 1;
		c->mapX--;
	}
	else if (!xray_is_shortest && c->dirY == 1)
	{
		*player_to_grid_y += 1;
		c->mapY++;
	}
	else if (!xray_is_shortest && c->dirY != 1)
	{
		*player_to_grid_y -= 1;
		c->mapY--;
	}
}

static void	ray_loop(t_cubed *c, double p_to_grid_x,
double p_to_grid_y, size_t *wall_position)
{
	bool	xray_is_shortest;
	t_hit	is_hit_result;

	xray_is_shortest = false;
	is_hit_result = no_hit;
	while (1)
	{
		xray_is_shortest = x_ray_is_shortest(c, p_to_grid_x, p_to_grid_y);
		is_hit_result = is_hit(c, p_to_grid_x, p_to_grid_y, xray_is_shortest);
		if (!xray_is_shortest && is_hit_result == y_ray_hit)
		{
			get_perp_wall_dist(c, 0);
			draw_wall(c, wall_position);
			return ;
		}
		else if (xray_is_shortest && is_hit_result == x_ray_hit)
		{
			get_perp_wall_dist(c, 1);
			draw_wall(c, wall_position);
			return ;
		}
		ray_loop_increase(c, &p_to_grid_x, &p_to_grid_y, xray_is_shortest);
	}
}

void	raycasting(t_cubed *c)
{
	size_t	wall_position;
	double	iterations;

	iterations = 1 / c->screen_width;
	c->fov = M_PI / -6;
	wall_position = 0;
	clean_screen(c);
	while (c->fov <= M_PI / 6)
	{
		c->mapX = (int)c->posX;
		c->mapY = (int)c->posY;
		get_player_to_grid(c, &c->player_to_grid_x,
			&c->player_to_grid_y);
		ray_loop(c, c->player_to_grid_x, c->player_to_grid_y,
			&wall_position);
		c->fov += iterations;
	}
}
