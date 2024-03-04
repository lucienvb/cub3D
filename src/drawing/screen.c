#include "../../include/cubed.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	r = (r < 0) ? 0 : (r > 255) ? 255 : r;
    g = (g < 0) ? 0 : (g > 255) ? 255 : g;
    b = (b < 0) ? 0 : (b > 255) ? 255 : b;
    a = (a < 0) ? 0 : (a > 255) ? 255 : a;
   return ((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) | (uint32_t)a;
}
// uint32_t get_texture_color(mlx_texture_t *texture, double x, double y) {
//     // Assuming texture coordinates are in the range [0, 1]
//     uint32_t color;

//     // Calculate the pixel position in the texture
//     uint32_t tex_x = (uint32_t)(x * texture->width);
//     uint32_t tex_y = (uint32_t)(y * texture->height);

//     // Calculate the pixel index in the texture array
//     uint32_t pixel_index = (tex_y * texture->width + tex_x) * texture->bytes_per_pixel;

//     // Get the color from the texture
//     color = (uint32_t)(texture->pixels[pixel_index] << 24) |
//             (uint32_t)(texture->pixels[pixel_index + 1] << 16) |
//             (uint32_t)(texture->pixels[pixel_index + 2] << 8) |
//             (uint32_t)(texture->pixels[pixel_index + 3]);

//     return color;
// }

// static mlx_texture_t *get_texture(t_cubed *cubed)
// {
// 	if (cubed->side == 0)
// 	{
// 		if (cubed->stepX > 0)
// 			return (cubed->e_texture);
// 		else
// 			return (cubed->w_texture);
// 	}
// 	else
// 	{
// 		if (cubed->stepY > 0)
// 			return (cubed->s_texture);
// 		else
// 			return (cubed->n_texture);
// 	}
// }


// void get_texture_pixel(t_cubed *cubed, int x, int y, double wall_height, double wall_width) {
//     uint32_t color;
    
//     // Calculate texture coordinates
//     double texture_x;
//     double texture_y;

//     // Assuming cubed->e_texture is the texture structure
//     texture_x = (double)x / wall_width;  // Adjust based on your texture coordinates
//     texture_y = (double)(y - (cubed->screen_height / 2) + (wall_height / 2)) / wall_height;

//     // Get the color from the texture
//     uint32_t texture_color = get_texture_color(cubed->e_texture, texture_x, texture_y);

//     if (cubed->side == true)
//         color = texture_color;
//     else
//         color = ft_pixel(177, 255, 203, 0xFF);;  // You can modify this based on your requirements

//     mlx_put_pixel(cubed->image_game, x, y, color);
// }

static uint32_t get_color(t_cubed *cubed)
{
	if (cubed->side == true)
	{
		if (cubed->dirX > 0)
			return (ft_pixel(250, 150, 10, 0xFF)); // Red (cubed->e_texture);
		else
			return (ft_pixel(0, 255, 0, 0xFF)); // Green (cubed->w_texture);
	}
	else
	{
		if (cubed->dirY > 0)
			return (ft_pixel(0, 0, 255, 0xFF)); // Blue (cubed->s_texture);
		else
			return (ft_pixel(255, 255, 0, 0xFF)); // Yellow (cubed->n_texture);
	}
}

void	get_texture_pixel(t_cubed *cubed, int x, int y)
{
	uint32_t color;

	color = get_color(cubed);
	mlx_put_pixel(cubed->image_game, x, y, color);
}

void    draw_wall(t_cubed *cubed, size_t *wall_position)
{
    // uint32_t	colorYellow = ft_pixel(177, 255, 203, 0xFF);
	// uint32_t	colorOrange = ft_pixel(83, 215, 135, 0xFF);
	uint32_t	colorTransparent;
	uint32_t	color;
    size_t		x;
    size_t 		y;
	double		wall_height;
	double		mini_map_surface;
	// double		wall_width = 0;

	// if (cubed->side == true)
	color = get_color(cubed);
	// else
	// 	color = colorYellow;
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
				// get_texture_pixel(cubed, x, y, wall_height, wall_width);
				// get_texture_pixel(cubed, x, y);
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
