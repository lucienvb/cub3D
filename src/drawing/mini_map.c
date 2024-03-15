/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/08 14:53:13 by lvan-bus      #+#    #+#                 */
/*   Updated: 2024/03/13 15:44:28 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static void	draw_visor(int x, int y, t_cubed *c)
{
	uint32_t	color_purple;
	int			line;
	double		pa;

	color_purple = ft_pixel(106, 90, 205, 0xFF);
	pa = c->pa;
	line = 15;
	while (line > 0)
	{
		mlx_put_pixel(c->image_game, x + cos(pa)
			* line, y + sin(pa) * line, color_purple);
		line--;
	}
}

void	draw_player_mini_map(t_cubed *c)
{
	double		player_size;
	uint32_t	color_green;
	size_t		x;
	size_t		y;

	player_size = 4;
	color_green = ft_pixel(60, 179, 113, 0xFF);
	y = c->mini_map_middle - player_size;
	while (y < c->mini_map_middle + player_size)
	{
		x = c->mini_map_middle - player_size;
		while (x < c->mini_map_middle + player_size)
		{
			mlx_put_pixel(c->image_game, x, y, color_green);
			if ((x > c->mini_map_middle - 1.5
					&& x < c->mini_map_middle + 1.5)
				&& (y > c->mini_map_middle - 1.5
					&& y < c->mini_map_middle + 1.5))
				draw_visor(x, y, c);
			x++;
		}
		y++;
	}
}

static void	draw_black_background(t_cubed *c)
{
	uint32_t	color_black;
	uint32_t	color_blue;
	size_t		x;
	size_t		y;

	color_black = ft_pixel(0, 0, 0, 0xFF);
	color_blue = ft_pixel(52, 126, 133, 0xFF);
	y = 0;
	while (y < c->miniMapH)
	{
		x = 0;
		while (x < c->miniMapH)
		{
			if (x == 0 || x == c->miniMapH -1
				|| y == 0 || y == c->miniMapH -1)
				mlx_put_pixel(c->image, x, y, color_blue);
			else
				mlx_put_pixel(c->image, x, y, color_black);
			x++;
		}
		y++;
	}
}

void	initialize_mini_map(t_cubed *c, t_minimap *m)
{
	m->color = ft_pixel(218, 223, 225, 0xFF);
	m->stepY = c->grid_size;
	m->stepX = c->grid_size;
	m->startY = 0;
	m->endY = m->startY + m->stepY;
	m->border = 1;
	m->y = 0;
}

void	mini_map(t_cubed *c)
{
	t_minimap	m;

	initialize_mini_map(c, &m);
	draw_black_background(c);
	while (c->map[m.y])
	{
		m.startX = 0;
		m.endX = m.stepX;
		m.x = 0;
		while (c->map[m.y][m.x])
		{
			if (c->map[m.y][m.x] == '1')
			{
				draw_color_stripe((int) m.startX + m.border,
					(int) m.endX - m.border, (int) m.startY + m.border,
					(int) m.endY - m.border, m.color, c);
			}
			m.startX = m.endX;
			m.endX += m.stepX;
			m.x++;
		}
		m.startY = m.endY;
		m.endY += m.stepY;
		m.y++;
	}
}
