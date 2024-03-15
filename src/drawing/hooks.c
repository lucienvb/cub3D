/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 14:55:23 by cter-maa      #+#    #+#                 */
/*   Updated: 2024/03/13 16:17:08 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

void	s_w_key(t_cubed *c)
{
	if (mlx_is_key_down(c->mlx, MLX_KEY_W))
	{
		if (c->map[(int)(c->posY)][(int)(c->posX + c->stepX)] == '0')
			c->posX += c->stepX;
		if (c->map[(int)(c->posY + c->stepY)][(int)(c->posX)] == '0')
			c->posY += c->stepY;
		reset_settings(c);
	}
	if (mlx_is_key_down(c->mlx, MLX_KEY_S))
	{
		if (c->map[(int)(c->posY)][(int)(c->posX - c->stepX)] == '0')
			c->posX -= c->stepX;
		if (c->map[(int)(c->posY - c->stepY)][(int)(c->posX)] == '0')
			c->posY -= c->stepY;
		reset_settings(c);
	}
}

void	a_d_key(t_cubed *c)
{
	if (mlx_is_key_down(c->mlx, MLX_KEY_A))
	{
		if (c->map[(int)(c->posY)][(int)(c->posX + c->stepXctrlA)] == '0')
			c->posX += c->stepXctrlA;
		if (c->map[(int)(c->posY + c->stepYctrlA)][(int)(c->posX)] == '0')
			c->posY += c->stepYctrlA;
		reset_settings(c);
	}
	if (mlx_is_key_down(c->mlx, MLX_KEY_D))
	{
		if (c->map[(int)(c->posY)][(int)(c->posX + c->stepXctrlD)] == '0')
			c->posX += c->stepXctrlD;
		if (c->map[(int)(c->posY + c->stepYctrlD)][(int)(c->posX)] == '0')
			c->posY += c->stepYctrlD;
		reset_settings(c);
	}
}

void	left_key(t_cubed *c)
{
	if (mlx_is_key_down(c->mlx, MLX_KEY_LEFT))
	{
		c->pa -= 0.03;
		if (c->pa < 0)
			c->pa += 2 * M_PI;
		c->stepX = cos(c->pa) * 0.05;
		c->stepY = sin(c->pa) * 0.05;
		c->stepXctrlA = cos(c->pa - 0.5 * M_PI) * 0.05;
		c->stepYctrlA = sin(c->pa - 0.5 * M_PI) * 0.05;
		c->stepXctrlD = cos(c->pa + 0.5 * M_PI) * 0.05;
		c->stepYctrlD = sin(c->pa + 0.5 * M_PI) * 0.05;
		reset_settings(c);
	}
}

void	right_key(t_cubed *c)
{
	if (mlx_is_key_down(c->mlx, MLX_KEY_RIGHT))
	{
		c->pa += 0.03;
		if (c->pa > 2 * M_PI)
			c->pa -= 2 * M_PI;
		c->stepX = cos(c->pa) * 0.05;
		c->stepY = sin(c->pa) * 0.05;
		c->stepXctrlA = cos(c->pa - 0.5 * M_PI) * 0.05;
		c->stepYctrlA = sin(c->pa - 0.5 * M_PI) * 0.05;
		c->stepXctrlD = cos(c->pa + 0.5 * M_PI) * 0.05;
		c->stepYctrlD = sin(c->pa + 0.5 * M_PI) * 0.05;
		reset_settings(c);
	}
}

void	hooks(void *param)
{
	t_cubed	*c;

	c = param;
	if (mlx_is_key_down(c->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(c->mlx);
	s_w_key(c);
	a_d_key(c);
	left_key(c);
	right_key(c);
}
