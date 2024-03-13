#include "../../include/cubed.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	r = (r < 0) ? 0 : (r > 255) ? 255 : r;
	g = (g < 0) ? 0 : (g > 255) ? 255 : g;
	b = (b < 0) ? 0 : (b > 255) ? 255 : b;
	a = (a < 0) ? 0 : (a > 255) ? 255 : a;
	return ((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) | (uint32_t)a;
}

void draw_color_stripe(int32_t startX, int32_t endX, int32_t startY, int32_t endY, uint32_t color, t_cubed *c)
{
	int32_t	y;
	int32_t	x;

	y = startY;
	while (y < endY)
	{
		x = startX;
		while(x < endX)
		{
			mlx_put_pixel(c->image, x, y, color);
			x++;
		}
		y++;
	}
}

void	drawPoint(t_cubed *c, double posX, double posY, uint32_t color, int thickness)
{
	int	y = 0;

	while (y < c->mini_map_height && posY > 0 && posY < c->mini_map_height)
	{
		int x = 0;
		while (x < c->mini_map_width && posX > 0 && posX < c->mini_map_width)
		{
			if ((x > posX - thickness && x < posX + thickness)
						&& (y > posY - thickness && y < posY + thickness)
						&& (x != posX && y != posY))
					mlx_put_pixel(c->image_game, x, y, color);
			x++;
		}
		y++;
	}
}

void	clean_screen(t_cubed *c)
{
	double		mini_map_surface;
	uint32_t	color_transparent;
	size_t		x;
	size_t		y;

	color_transparent = ft_pixel(0, 0, 0, 0);
	mini_map_surface = c->mini_map_size * c->grid_size;
	y = 0;
	while (y < c->screen_height)
	{
		x = 0;
		while (x < c->screen_width)
		{
			if (x < mini_map_surface && y < mini_map_surface)
				mlx_put_pixel(c->image_game, x, y, color_transparent);
			else if (x < c->screen_width - 1 && y < c->screen_height
				/ 2 - 1)
				mlx_put_pixel(c->image_game, x, y,
					ft_pixel(255, 243, 231, 0xFF));
			else
				mlx_put_pixel(c->image_game, x, y, ft_pixel(255, 0, 0, 0xFF));
			x++;
		}
		y++;
	}
}
