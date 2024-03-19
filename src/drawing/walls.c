/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   walls.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 11:43:57 by chavertterm   #+#    #+#                 */
/*   Updated: 2024/03/19 15:15:12 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

uint32_t	get_tex_color(mlx_texture_t *texture, double x, double y)
{
	uint32_t	color;
	uint32_t	tex_x;
	uint32_t	tex_y;
	uint32_t	pixel_index;

	tex_x = (uint32_t)(x * texture->width);
	tex_y = (uint32_t)(y * texture->height);
	pixel_index = (tex_y * texture->width + tex_x) * texture->bytes_per_pixel;
	color = ((uint32_t)texture->pixels[pixel_index] << 24)
		| ((uint32_t)texture->pixels[pixel_index + 1] << 16)
		| ((uint32_t)texture->pixels[pixel_index + 2] << 8)
		| ((uint32_t)texture->pixels[pixel_index + 3]);
	return (color);
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

void	get_texture(t_cubed *cubed, size_t *wall_pos, int y, double wallh)
{
	double			texture_y;
	mlx_texture_t	*texture;
	uint32_t		tex_color;

	texture_y = (double)(y - (cubed->screen_height / 2)
			+ (wallh / 2)) / wallh;
	if (texture_y <= 0)
		texture_y = 0;
	texture = set_tex_direction(cubed);
	tex_color = get_tex_color(texture, cubed->percentage_wall_width, texture_y);
	mlx_put_pixel(cubed->image_game, *wall_pos, y, tex_color);
}

void	draw_wall(t_cubed *cubed, size_t *wall_pos)
{
	double	wall_height;
	int		y;
	double	end_y;

	wall_height = (cubed->screen_height / cubed->perp_wall_dist) * 0.5;
	if (wall_height > cubed->screen_height)
		wall_height = cubed->screen_height;
	y = (cubed->screen_height / 2) - (wall_height / 2);
	end_y = (cubed->screen_height / 2) + (wall_height / 2);
	while (y < end_y)
	{
		if (*wall_pos >= cubed->screen_width)
			break ;
		if (*wall_pos < cubed->mini_map_surface && y < cubed->mini_map_surface)
			mlx_put_pixel(cubed->image_game, *wall_pos, y,
				cubed->colorTransparent);
		else
			get_texture(cubed, wall_pos, y, wall_height);
		y++;
	}
	*wall_pos += 1;
}
