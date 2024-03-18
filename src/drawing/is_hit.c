/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_hit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: chaverttermaat <chaverttermaat@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 11:06:33 by chavertterm   #+#    #+#                 */
/*   Updated: 2024/03/18 11:10:11 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static t_hit	is_hit_validate(t_cubed *cubed, double x,
bool x_ray_is_shortest)
{
	if (x_ray_is_shortest)
	{
		if (cubed->map[cubed->mapY][cubed->mapX + (int)cubed->dirX] == '1')
		{
			cubed->percentage_wall_width = fmod(x, 40) / 40;
			cubed->side = true;
			return (x_ray_hit);
		}
	}
	else
	{
		if (cubed->map[cubed->mapY + (int)cubed->dirY][cubed->mapX] == '1')
		{
			cubed->percentage_wall_width = fmod(x, 40) / 40;
			cubed->side = false;
			return (y_ray_hit);
		}
	}
	return (no_hit);
}

t_hit	is_hit(t_cubed *cubed, double player_to_grid_x,
double player_to_grid_y, bool x_ray_is_shortest)
{
	double	pa;
	double	x;
	double	y;

	pa = cubed->pa + cubed->fov;
	x = 0;
	if (x_ray_is_shortest)
	{
		x = ((cubed->posX + player_to_grid_x) * cubed->grid_width);
		y = ((cubed->posY + player_to_grid_x * sin(pa) / cos(pa))
				* cubed->grid_height);
		return (is_hit_validate(cubed, y, x_ray_is_shortest));
	}
	else
	{
		x = ((cubed->posX + player_to_grid_y * cos(pa) / sin(pa))
				* cubed->grid_width);
		y = ((cubed->posY + player_to_grid_y) * cubed->grid_height);
		return (is_hit_validate(cubed, x, x_ray_is_shortest));
	}
}
