/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bus <lvan-bus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:54:25 by chavertterm       #+#    #+#             */
/*   Updated: 2024/03/21 10:49:18 by lvan-bus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

#include <stdint.h>

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;
	if (a < 0)
		a = 0;
	else if (a > 255)
		a = 255;
	return (((uint32_t)r << 24) | ((uint32_t)g << 16)
		| ((uint32_t)b << 8) | (uint32_t)a);
}

void	draw_color_stripe(t_cubed *c, t_mini_map m)
{
	uint32_t	color;
	int32_t		y;
	int32_t		x;

	color = ft_pixel(218, 223, 225, 0xFF);
	y = m.startY + m.border;
	while (y < m.endY - m.border)
	{
		x = m.startX + m.border;
		while (x < m.endX - m.border)
		{
			mlx_put_pixel(c->image, x, y, color);
			x++;
		}
		y++;
	}
}

void	clean_screen(t_cubed *c)
{
	uint32_t	color_transparent;
	double		mini_map_surface;
	size_t		x;
	size_t		y;

	color_transparent = ft_pixel(0, 0, 0, 0);
	mini_map_surface = c->mini_map_size * c->grid_width;
	y = 0;
	while (y < c->screen_height)
	{
		x = 0;
		while (x < c->screen_width)
		{
			if (x < mini_map_surface && y < mini_map_surface)
				mlx_put_pixel(c->image_game, x, y, color_transparent);
			else if (x < c->screen_width - 1 && y < c->screen_height / 2 - 1)
				mlx_put_pixel(c->image_game, x, y,
					ft_pixel(255, 243, 231, 0xFF));
			else
				mlx_put_pixel(c->image_game, x, y, ft_pixel(255, 0, 0, 0xFF));
			x++;
		}
		y++;
	}
}
