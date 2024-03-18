/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screen.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: chaverttermaat <chaverttermaat@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 11:54:25 by chavertterm   #+#    #+#                 */
/*   Updated: 2024/03/18 11:59:43 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	r = (r < 0) ? 0 : (r > 255) ? 255 : r;
	g = (g < 0) ? 0 : (g > 255) ? 255 : g;
	b = (b < 0) ? 0 : (b > 255) ? 255 : b;
	a = (a < 0) ? 0 : (a > 255) ? 255 : a;
	return (((uint32_t)r << 24) | ((uint32_t)g << 16)
		| ((uint32_t)b << 8) | (uint32_t)a);
}

void	draw_color_stripe(int32_t startx, int32_t endx, int32_t starty,
int32_t endY, uint32_t color, t_cubed *cubed)
{
	int32_t	y;
	int32_t	x;

	y = starty;
	while (y < endY)
	{
		x = startx;
		while (x < endx)
		{
			mlx_put_pixel(cubed->image, x, y, color);
			x++;
		}
		y++;
	}
}

void	drawPoint(t_cubed *cubed, double posX, double posY,
uint32_t color, int thickness)
{
	int	y;
	int	x;

	y = 0;
	while (y < cubed->mini_map_height && posY > 0
		&& posY < cubed->mini_map_height)
	{
		x = 0;
		while (x < cubed->mini_map_width && posX > 0
			&& posX < cubed->mini_map_width)
		{
			if ((x > posX - thickness && x < posX + thickness)
				&& (y > posY - thickness && y < posY + thickness)
				&& (x != posX && y != posY))
				mlx_put_pixel(cubed->image_game, x, y, color);
			x++;
		}
		y++;
	}
}
