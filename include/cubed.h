#ifndef CUBED_H
#define CUBED_H

// headers
# include <stdlib.h>
# include <stdio.h> // remove
# include <unistd.h>
# include <string.h> // remove
# include <math.h>
# include "../lib/libft/libft.h"
# include "../lib/libft/ft_printf/ft_printf.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

// defines
# define FAILURE		1
# define SUCCESS		0
# define NOT_FOUND		1
# define FOUND			0
# define TRUE			1
# define FALSE			0
# define SCREEN_WIDTH	640
# define SCREEN_HEIGHT	480

#define column 7
#define row 7

// enum
typedef enum e_hit
{
	x_ray_hit,
	y_ray_hit,
	no_hit,
	done,
}	t_hit;

typedef struct s_intersections
{
	double	x;
	double	y;
	double	ray_length;
}			t_intersections;

// structures
typedef struct s_cubed
{
	// screen variables
	mlx_t		*mlx;
	mlx_image_t	*image;
	double		screen_width;
	double		screen_height;
	double		mini_map_width;
	double		mini_map_height;
	double		mini_map_start_y;
	double		grid_width;
	double		grid_height;
	bool		draw_screen;

	// player variables
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	pa;
	double	fov;
	double	stepX;
	double	stepY;
	double	player_to_grid_x;
	double	player_to_grid_y;
	double	x_ray_length;
	double	y_ray_length;
	bool	side;
	bool	raycasting_is_done;

}			t_cubed;

	
// typedef struct s_mlx
// {
// 	// mlx_texture_t	*n_texture;
// 	// mlx_texture_t	*e_texture;
// 	// mlx_texture_t	*s_texture;
// 	// mlx_texture_t	*w_texture;
// } t_mlx;

// typedef struct s_screen
// {
	
// } t_screen;

// typedef struct s_cubed
// {
// 	char		**map;
// 	char		**start_pos;
// 	char		*argv;
// 	size_t		*ceiling_color;
// 	size_t		*floor_color;
// 	char		*EA;
// 	char		*WE;
// 	char		*NO;
// 	char		*SO;
// 	// t_mlx		*mlx;
// 	// t_screen	*screen;
// } t_cubed;

// src/setup
// void	error_handling(int argc, char **argv);
// void	initialization(t_cubed *cubed, t_mlx *mlx, t_screen *screen, char *argv);
// int		input_parsing();
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	draw_color_stripe(int32_t startX, int32_t endX, int32_t startY, int32_t endY, uint32_t color, t_cubed *cubed);
void	mini_map(void *cubed);
void	hooks(void* param);
void	reset_settings(t_cubed *cubed);
void	raycasting(void *param);
void draw_color_stripe(int32_t startX, int32_t endX, int32_t startY, int32_t endY, uint32_t color, t_cubed *cubed);
void	draw_floor_and_ceiling(t_cubed *cubed);
void	drawPoint(t_cubed *cubed, double posX, double posY, uint32_t color, int thickness);

void	get_player_to_grid(t_cubed *cubed, double *player_to_grid_x, double *player_to_grid_y);
void draw_screen(void* param);
void	reset_settings(t_cubed *cubed);
int32_t start_cubed(void);




#endif