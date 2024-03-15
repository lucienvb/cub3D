/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_cubed.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 14:56:07 by cter-maa      #+#    #+#                 */
/*   Updated: 2024/03/13 15:35:56 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static void	position_mini_map(t_cubed *cubed)
{
	double	distancex;
	double	distancey;

	distancex = - (cubed->posX - (cubed->mini_map_size / 2));
	distancey = - (cubed->posY - (cubed->mini_map_size / 2));
	cubed->image->instances[0].x = distancex * cubed->grid_size;
	cubed->image->instances[0].y = distancey * cubed->grid_size;
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
