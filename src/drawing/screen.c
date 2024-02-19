#include "../../include/cubed.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void    draw_wall(t_cubed *cubed, size_t *wall_position)
{
    uint32_t	colorYellow = ft_pixel(177, 255, 203, 0xFF);
	uint32_t	colorOrange = ft_pixel(83, 215, 135, 0xFF);
	uint32_t	colorTransparent;
	uint32_t	color;
    size_t		x;
    size_t 		y;
	double		wall_height;
	double		mini_map_surface;

	if (cubed->side == true)
		color = colorOrange;
	else
		color = colorYellow;
	colorTransparent = ft_pixel(0, 0, 0, 0);
	mini_map_surface = cubed->mini_map_size * cubed->grid_width;
	wall_height = (cubed->screen_height / cubed->perp_wall_dist) * 0.5;
	if (wall_height > cubed->screen_height)
		wall_height = cubed->screen_height;
	x = 0;
	y = (cubed->screen_height / 2) - (wall_height / 2);
	double	end_y = (cubed->screen_height / 2) + (wall_height / 2);
    while (y < end_y)
	{
        x = *wall_position;
		if (x >= cubed->screen_width)
			break ;
        while (x < (*wall_position) + 1)
        {
			if (x < mini_map_surface && y < mini_map_surface)
				mlx_put_pixel(cubed->image_game, x, y, colorTransparent);
			else
			    mlx_put_pixel(cubed->image_game, x, y, color);
            x++;
        }
		y++;
	}
	*wall_position += 1;
}

void draw_color_stripe(int32_t startX, int32_t endX, int32_t startY, int32_t endY, uint32_t color, t_cubed *cubed)
{
	int32_t	y;
	int32_t	x;

	y = startY;
	while (y < endY)
    {
		x = startX;
       while(x < endX)
        {
            mlx_put_pixel(cubed->image, x, y, color);
			x++;
        }
		y++;
	}
}

void	drawPoint(t_cubed *cubed, double posX, double posY, uint32_t color, int thickness)
{
	int	y = 0;

	while (y < cubed->mini_map_height && posY > 0 && posY < cubed->mini_map_height)
	{
		int x = 0;
		while (x < cubed->mini_map_width && posX > 0 && posX < cubed->mini_map_width)
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
