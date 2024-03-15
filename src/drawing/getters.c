/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getters.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 14:54:46 by cter-maa      #+#    #+#                 */
/*   Updated: 2024/03/13 15:01:18 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

void	get_perp_wall_dist(t_cubed *cubed, bool x_ray_is_shortest)
{
	double	temp_fov;
	double	current_ray_length;

	temp_fov = cubed->fov;
	if (temp_fov < 0)
		temp_fov *= -1;
	if (x_ray_is_shortest)
		current_ray_length = cubed->x_ray_length;
	else
		current_ray_length = cubed->y_ray_length;
	cubed->perp_wall_dist = cos(temp_fov) * current_ray_length;
}

static void	get_ray_direction(t_cubed *cubed, double pa)
{
	if (pa > 2 * M_PI)
		pa -= 2 * M_PI;
	if (pa >= (M_PI / 2) && pa < (M_PI * 3 / 2))
		cubed->dirX = -1;
	else
		cubed->dirX = 1;
	if (pa >= 0 && pa < M_PI)
		cubed->dirY = 1;
	else
		cubed->dirY = -1;
}

void	get_player_to_grid(t_cubed *cubed,
	double *player_to_grid_x, double *player_to_grid_y)
{
	double	pa;

	pa = cubed->pa + cubed->fov;
	get_ray_direction(cubed, pa);
	if (cubed->dirX == 1)
		*player_to_grid_x = cubed->posX;
	else if (cubed->dirX == -1)
		*player_to_grid_x = cubed->map_width - cubed->posX;
	else
		*player_to_grid_x = 0;
	if (cubed->dirY == 1)
		*player_to_grid_y = cubed->posY;
	else if (cubed->dirY == -1)
		*player_to_grid_y = cubed->map_height - cubed->posY;
	else
		*player_to_grid_y = 0;
	while (*player_to_grid_x >= 0)
		(*player_to_grid_x)--;
	if (cubed->dirX == 1)
		*player_to_grid_x *= -1;
	while (*player_to_grid_y >= 0)
		(*player_to_grid_y)--;
	if (cubed->dirY == 1)
		*player_to_grid_y *= -1;
}
