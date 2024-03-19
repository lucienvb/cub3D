/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_cubed.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: chaverttermaat <chaverttermaat@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 11:48:28 by chavertterm   #+#    #+#                 */
/*   Updated: 2024/03/18 11:49:20 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static void	position_mini_map(t_cubed *cubed)
{
	double	distance_x;
	double	distance_y;

	distance_x = - (cubed->posX - (cubed->mini_map_size / 2));
	distance_y = - (cubed->posY - (cubed->mini_map_size / 2));
	cubed->image->instances[0].x = distance_x * cubed->grid_width;
	cubed->image->instances[0].y = distance_y * cubed->grid_height;
}

void	draw_screen(t_cubed *cubed)
{
	mini_map(cubed);
	raycasting(cubed);
	position_mini_map(cubed);
	clean_screen(cubed);
	draw_player_mini_map(cubed);
	reset_settings(cubed);
}

void	reset_settings(t_cubed *cubed)
{
	position_mini_map(cubed);
	clean_screen(cubed);
	raycasting(cubed);
	draw_player_mini_map(cubed);
}

int32_t	start_cubed(t_cubed *cubed)
{
	if (create_image_mlx(cubed) == FAILURE)
		return (FAILURE);
	if (image_to_window_mlx(cubed) == FAILURE)
		return (FAILURE);
	draw_screen(cubed);
	mlx_loop_hook(cubed->mlx, hooks, cubed);
	mlx_loop(cubed->mlx);
	mlx_terminate(cubed->mlx);
	return (SUCCESS);
}
