#include "../../include/cubed.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void    draw_wall(t_cubed *cubed, size_t *wall_position)
{
    uint32_t	colorYellow = ft_pixel(255, 165, 0, 0xFF);
	uint32_t	colorOrange = ft_pixel(255, 140, 0, 0xFF);
	uint32_t	color;
    size_t		x;
    size_t 		y;
	double	wall_height;

	if (cubed->side == true)
		color = colorOrange;
	else
		color = colorYellow;
	// wall_height = cubed->screen_height * (1 - cubed->current_ray_length / max_length);
	// printf("ray_len: %f\t", cubed->current_ray_length);
	// printf("max_len: %f\t",max_length);
	// printf("ray_len / max_len: %f\n", cubed->current_ray_length / max_length);
	// printf("ray_len: %f\n", cubed->5_ray_length);

	wall_height = cubed->screen_height / cubed->perp_wall_dist / 10;
	printf("{wall_heigth=%f}\n", wall_height);
	x = 0;
	y = (cubed->screen_height / 2) - (wall_height / 2);
	double	end_y = (cubed->screen_height / 2) + (wall_height / 2);
    while (y < end_y)
	{
        x = *wall_position;
		if (x >= cubed->screen_width)
			break ;
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
					mlx_put_pixel(cubed->image, x, y + cubed->mini_map_start_y, color);
			x++;
		}
		y++;
	}
}