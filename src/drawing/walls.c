#include "../../include/cubed.h"

uint32_t get_tex_color(mlx_texture_t *texture, double x, double y) 
{
    uint32_t color;
    uint32_t tex_x;
    uint32_t tex_y;
    uint32_t pixel_index;

    tex_x = (uint32_t)(x * texture->width);
    tex_y = (uint32_t)(y * texture->height);
    // pixel_index = (tex_y * (texture->width + tex_x)) * texture->bytes_per_pixel;
    pixel_index = (tex_y * texture->width + tex_x) * texture->bytes_per_pixel;
    color = (uint32_t)(texture->pixels[pixel_index] << 24) |
            (uint32_t)(texture->pixels[pixel_index + 1] << 16) |
            (uint32_t)(texture->pixels[pixel_index + 2] << 8) |
            (uint32_t)(texture->pixels[pixel_index + 3]);
    return color;
}

static mlx_texture_t	*set_tex_direction(t_cubed *cubed)
{
	if (cubed->side == true)
	{
		if (cubed->dirX > 0)
			return (cubed->e_texture);
		else
			return (cubed->w_texture);
	}
	else
	{
		if (cubed->dirY > 0)
			return (cubed->s_texture);
		else
			return (cubed->n_texture);
	}
}

void	get_texture(t_cubed *cubed, size_t *wall_position, int y, double wall_height)
{
	double texture_x;
	double texture_y;
	double wall_int = *wall_position;

	// if (wall_int == 790)
	// 	exit(1); 
	// texture_x = wall_int * cubed->percentage_wall_width;
	// printf("%f = percentage_wall_width", cubed->percentage_wall_width);
	// printf("%f = texture_x\n", texture_x);
	// printf("%f = wall_pos    |    %f = percentage_wall_width      |     %f = texture_x\n\n", wall_int, cubed->percentage_wall_width, texture_x);
	// texture_x = ((double)(wall_int)) / 94;
	texture_x = cubed->percentage_wall_width;
	texture_y = (double)(y - (cubed->screen_height / 2) + (wall_height / 2)) / wall_height;
	// printf("%f = percentage_wall_width", cubed->percentage_wall_width);
	// texture_y = (double)(y - (cubed->screen_height / 2) + (wall_height / 2)) / wall_height;
	if (texture_y <= 0)
		texture_y = 0;
	// printf("%f = texture_y\n", texture_y);
	mlx_texture_t *texture = set_tex_direction(cubed);
	uint32_t texture_color = get_tex_color(texture, texture_x, texture_y);
	mlx_put_pixel(cubed->image_game, wall_int, y, texture_color);
	}

void draw_wall(t_cubed *cubed, size_t *wall_position)
{
	double	wall_height;
	int		y;
	double	end_y;

	wall_height = (cubed->screen_height / cubed->perp_wall_dist) * 0.5;
	if (wall_height > cubed->screen_height)
		wall_height = cubed->screen_height;
	y = (cubed->screen_height / 2) - (wall_height / 2);
	end_y = (cubed->screen_height / 2) + (wall_height / 2);
	// wall_width = get_wall_width(cubed, wall_position);
	while (y < end_y)
	{
		if (*wall_position >= cubed->screen_width)
			break;
		if (*wall_position < cubed->mini_map_surface && y < cubed->mini_map_surface)
			mlx_put_pixel(cubed->image_game, *wall_position, y, cubed->colorTransparent);
		else
			get_texture(cubed, wall_position, y, wall_height);
		y++;
	}
	*wall_position += 1;
}

// static uint32_t get_color(t_cubed *cubed)
// {
// 	if (cubed->side == true)
// 	{
// 		if (cubed->dirX > 0)
// 			return (ft_pixel(250, 150, 10, 0xFF)); // Red (cubed->e_texture);
// 		else
// 			return (ft_pixel(0, 255, 0, 0xFF)); // Green (cubed->w_texture);
// 	}
// 	else
// 	{
// 		if (cubed->dirY > 0)
// 			return (ft_pixel(0, 0, 255, 0xFF)); // Blue (cubed->s_texture);
// 		else
// 			return (ft_pixel(255, 255, 0, 0xFF)); // Yellow (cubed->n_texture);
// 	}
// }