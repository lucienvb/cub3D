/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   walls.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 14:56:50 by cter-maa      #+#    #+#                 */
/*   Updated: 2024/03/13 15:45:21 by cter-maa      ########   odam.nl         */
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
	color = (uint32_t)(texture->pixels[pixel_index] << 24)
		| (uint32_t)(texture->pixels[pixel_index + 1] << 16)
		| (uint32_t)(texture->pixels[pixel_index + 2] << 8)
		| (uint32_t)(texture->pixels[pixel_index + 3]);
	return (color);
}

static mlx_texture_t	*set_tex_direction(t_cubed *c)
{
	if (c->side == true)
	{
		if (c->dirX > 0)
			return (c->e_texture);
		else
			return (c->w_texture);
	}
	else
	{
		if (c->dirY > 0)
			return (c->s_texture);
		else
			return (c->n_texture);
	}
}

void	get_texture(t_cubed *c, size_t *wall_position, int y, double w_height)
{
	double			perc_y;
	uint32_t		tex_color;
	mlx_texture_t	*texture;

	perc_y = (double)(y - (c->screenH / 2) + (w_height / 2)) / w_height;
	if (perc_y <= 0)
		perc_y = 0;
	texture = set_tex_direction(c);
	tex_color = get_tex_color(texture, c->percentage_wall_width, perc_y);
	mlx_put_pixel(c->image_game, *wall_position, y, tex_color);
}

void	draw_wall(t_cubed *c, size_t *wall_position, bool xray_is_shortest)
{
	double	wall_height;
	int		y;
	double	end_y;

	get_perp_wall_dist(c, xray_is_shortest);
	wall_height = (c->screenH / c->perp_wall_dist) * 0.5;
	if (wall_height > c->screenH)
		wall_height = c->screenH;
	y = (c->screenH / 2) - (wall_height / 2);
	end_y = (c->screenH / 2) + (wall_height / 2);
	while (y < end_y)
	{
		if (*wall_position >= c->screenW)
			break ;
		if (*wall_position < c->mini_map_surface && y < c->mini_map_surface)
			mlx_put_pixel(c->image_game, *wall_position,
				y, c->colorTransparent);
		else
			get_texture(c, wall_position, y, wall_height);
		y++;
	}
	*wall_position += 1;
}
