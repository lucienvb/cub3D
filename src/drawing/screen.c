#include "../../include/cubed.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

static double   length_to_map_edge(t_cubed *cubed)
{
    double  x_length;
    double  y_length;

    if (cubed->dirX == 1)
        x_length = cubed->mini_map_width - cubed->posX;
    else if (cubed->dirX == -1)
        x_length = cubed->mini_map_width - (cubed->mini_map_width - cubed->posX);
    else
        x_length = 0;
    if (cubed->dirY == 1)
        y_length = cubed->mini_map_height - cubed->posY;
    else if (cubed->dirY == -1)
        y_length = cubed->mini_map_height - (cubed->mini_map_height - cubed->posY);
    else
        y_length = 0;
    
    return (sqrt(x_length * x_length + y_length * y_length));
}

void    draw_wall(t_cubed *cubed, size_t *wall_position)
{
    uint32_t	colorYellow = ft_pixel(255, 165, 0, 0xFF);
	uint32_t	colorOrange = ft_pixel(255, 140, 0, 0xFF);
	uint32_t	color;
    size_t		x;
    size_t 		y;
	double	wall_height;

    double	max_length = length_to_map_edge(cubed);
	if (cubed->side == true)
		color = colorOrange;
	else
		color = colorYellow;
	wall_height = cubed->screen_height * (1 - cubed->current_ray_length / max_length);
	x = 0;
	y = (cubed->screen_height / 2) - (wall_height / 2);
	wall_height += y;
    while (y < wall_height)
	{
        x = *wall_position;
        while (x < (*wall_position) + 8)
        {
		    mlx_put_pixel(cubed->image, x, y, color);
            x++;
        }
		y++;
	}
	*wall_position += 8;
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

void	draw_floor_and_ceiling(t_cubed *cubed)
{
	uint32_t colorBrown = ft_pixel(139, 69, 19, 0xFF);
	uint32_t colorPurple = ft_pixel(160, 32, 240, 0xFF);

	draw_color_stripe(0, cubed->screen_width - 1, 0, cubed->screen_height / 2 - 1, colorPurple, cubed);
	draw_color_stripe(0, cubed->screen_width - 1, cubed->screen_height / 2 - 1, cubed->screen_height - 1, colorBrown, cubed);
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
					mlx_put_pixel(cubed->image, round(x), round(y) + cubed->mini_map_start_y, color);
			x++;
		}
		y++;
	}
}