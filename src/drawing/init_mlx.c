/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 14:55:31 by cter-maa      #+#    #+#                 */
/*   Updated: 2024/03/13 16:16:22 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

int	create_image_mlx(t_cubed *c)
{
	c->mlx = mlx_init((int32_t)c->screenW, (int32_t)c->screenH, "MLX42", true);
	if (!c->mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (FAILURE);
	}
	c->image = mlx_new_image(c->mlx, (int32_t)
			c->miniMapH, (int32_t)c->miniMapH);
	if (!c->image)
	{
		mlx_close_window(c->mlx);
		puts(mlx_strerror(mlx_errno));
		return (FAILURE);
	}
	c->image_game = mlx_new_image(c->mlx,
			(int32_t)c->screenW, (int32_t)c->screenH);
	if (!c->image_game)
	{
		mlx_close_window(c->mlx);
		puts(mlx_strerror(mlx_errno));
		return (FAILURE);
	}
	return (SUCCESS);
}

int	image_to_window_mlx(t_cubed *c)
{
	if (mlx_image_to_window(c->mlx, c->image, 0, 0) == -1)
	{
		mlx_close_window(c->mlx);
		puts(mlx_strerror(mlx_errno));
		return (FAILURE);
	}
	if (mlx_image_to_window(c->mlx, c->image_game, 0, 0) == -1)
	{
		mlx_close_window(c->mlx);
		puts(mlx_strerror(mlx_errno));
		return (FAILURE);
	}
	return (SUCCESS);
}
