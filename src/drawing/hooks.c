/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: chaverttermaat <chaverttermaat@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 11:36:29 by chavertterm   #+#    #+#                 */
/*   Updated: 2024/03/18 11:39:25 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static void	keys_w_s(t_cubed *cubed)
{
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_W))
	{
		if (cubed->map[(int)(cubed->posY)][(int)
		(cubed->posX + cubed->stepX)] == '0')
			cubed->posX += cubed->stepX;
		if (cubed->map[(int)(cubed->posY + cubed->stepY)][(int)
		(cubed->posX)] == '0')
			cubed->posY += cubed->stepY;
		reset_settings(cubed);
	}
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_S))
	{
		if (cubed->map[(int)(cubed->posY)][(int)
		(cubed->posX - cubed->stepX)] == '0')
			cubed->posX -= cubed->stepX;
		if (cubed->map[(int)(cubed->posY - cubed->stepY)][(int)
		(cubed->posX)] == '0')
			cubed->posY -= cubed->stepY;
		reset_settings(cubed);
	}
}

static void	keys_a_d(t_cubed *cubed)
{
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_A))
	{
		if (cubed->map[(int)(cubed->posY)][(int)
		(cubed->posX + cubed->stepXctrlA)] == '0')
			cubed->posX += cubed->stepXctrlA;
		if (cubed->map[(int)(cubed->posY + cubed->stepYctrlA)][(int)
		(cubed->posX)] == '0')
			cubed->posY += cubed->stepYctrlA;
		reset_settings(cubed);
	}
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_D))
	{
		if (cubed->map[(int)(cubed->posY)][(int)
		(cubed->posX + cubed->stepXctrlD)] == '0')
			cubed->posX += cubed->stepXctrlD;
		if (cubed->map[(int)(cubed->posY + cubed->stepYctrlD)][(int)
		(cubed->posX)] == '0')
			cubed->posY += cubed->stepYctrlD;
		reset_settings(cubed);
	}
}

static void	key_right(t_cubed *cubed)
{
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_RIGHT))
	{
		cubed->pa += 0.03;
		if (cubed->pa > 2 * M_PI)
			cubed->pa -= 2 * M_PI;
		cubed->stepX = cos(cubed->pa) * 0.05;
		cubed->stepY = sin(cubed->pa) * 0.05;
		cubed->stepXctrlA = cos(cubed->pa - 0.5 * M_PI) * 0.05;
		cubed->stepYctrlA = sin(cubed->pa - 0.5 * M_PI) * 0.05;
		cubed->stepXctrlD = cos(cubed->pa + 0.5 * M_PI) * 0.05;
		cubed->stepYctrlD = sin(cubed->pa + 0.5 * M_PI) * 0.05;
		reset_settings(cubed);
	}
}

static void	key_left(t_cubed *cubed)
{
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_LEFT))
	{
		cubed->pa -= 0.03;
		if (cubed->pa < 0)
			cubed->pa += 2 * M_PI;
		cubed->stepX = cos(cubed->pa) * 0.05;
		cubed->stepY = sin(cubed->pa) * 0.05;
		cubed->stepXctrlA = cos(cubed->pa - 0.5 * M_PI) * 0.05;
		cubed->stepYctrlA = sin(cubed->pa - 0.5 * M_PI) * 0.05;
		cubed->stepXctrlD = cos(cubed->pa + 0.5 * M_PI) * 0.05;
		cubed->stepYctrlD = sin(cubed->pa + 0.5 * M_PI) * 0.05;
		reset_settings(cubed);
	}
}

void	hooks(void *param)
{
	t_cubed	*cubed;

	cubed = param;
	if (mlx_is_key_down(cubed->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cubed->mlx);
	keys_w_s(cubed);
	keys_a_d(cubed);
	key_left(cubed);
	key_right(cubed);
}
