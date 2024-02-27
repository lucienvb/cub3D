#ifndef CUBED_H
# define CUBED_H

// headers
# include <stdlib.h>
# include <stdio.h> 
# include <unistd.h>
# include <math.h>
# include "cubed.h"
# include "../libs/libft/libft.h"
# include "../libs/libft/ft_printf/ft_printf.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"

// defines
# define FAILURE		1
# define SUCCESS		0
# define NOT_FOUND		1
# define FOUND			0
# define TRUE			1
# define FALSE			0
# define CRASH			-1
# define SCREEN_WIDTH	640
# define SCREEN_HEIGHT	480
# define Y				0
# define X				1
#define row 24
#define column 24

// enum
typedef enum e_hit
{
	x_ray_hit,
	y_ray_hit,
	no_hit,
}	t_hit;

// structures
typedef struct s_intersections
{
	double	x;
	double	y;
	double	ray_length;
}			t_intersections;

typedef struct s_cubed
{
	int			fd;
	char		**file;
	char		**map;
	char		**map_val;
	char		*argv;
	int			start_pos[2];
	char		start_cardinal_point;
	int			ceiling[3];
	int			floor[3];
	int			max_column;
	int			total_row;
	mlx_t		*mlx;
	mlx_image_t	*image;
	mlx_image_t	*image_game;
	double		screen_width;
	double		screen_height;
	double		map_width;
	double		map_height;
	double			mini_map_width;
	double			mini_map_height;
	double		mini_map_start_y;
	double		mini_map_size;
	double		mini_map_middle;
	double		grid_width;
	double		grid_height;
	bool		draw_screen;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		pa;
	double		fov;
	double		stepX;
	double		stepY;
	double		stepXctrlA;
	double		stepYctrlA;
	double		stepXctrlD;
	double		stepYctrlD;
	double		player_to_grid_x;
	double		player_to_grid_y;
	double		x_ray_length;
	double		y_ray_length;
	double		shortest_ray_length;
	double		perp_wall_dist;
	bool		side;
	bool		raycasting_is_done;
	double		diff;
	int			mapX;
	int			mapY;
	mlx_texture_t	*n_texture;
	mlx_texture_t	*e_texture;
	mlx_texture_t	*s_texture;
	mlx_texture_t	*w_texture;
}	t_cubed;

// src/setup/input
void	input_error_handling(int argc, char **argv);
void	input_init(t_cubed *cubed, char *argv);
char	*get_next_line(int fd);

// src/setup/parsing
int		input_parsing(t_cubed *cubed, char *argv);
int		parse_map(t_cubed *cubed);
int		parse_start_pos(t_cubed *cubed);
int		parse_color_code(t_cubed *cubed);
int		parse_texture(t_cubed *cubed);
int		validate_map(t_cubed *cubed, int x, int y);
int		parse_map_dimensions(t_cubed *cubed);

// src/setup/utils
void	free_2d_array(char **array);
int		validate_map_char(int c);
int		cb_isspace(int c);
void	perror_exit(char *message);
void	error_exit(char *message);
void	print_map(char **map);
char	*cd_strndup(const char *str, size_t n);

//src/cleanup
void	free_2d_array(char **array);
void	free_allocations(t_cubed *cubed);

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	draw_color_stripe(int32_t startX, int32_t endX, int32_t startY, int32_t endY, uint32_t color, t_cubed *cubed);
void	mini_map(t_cubed *cubed);
void	hooks(void* param);
void	reset_settings(t_cubed *cubed);
void	raycasting(t_cubed *cubed);
void 	draw_color_stripe(int32_t startX, int32_t endX, int32_t startY, int32_t endY, uint32_t color, t_cubed *cubed);
void	draw_floor_and_ceiling(t_cubed *cubed);
void	drawPoint(t_cubed *cubed, double posX, double posY, uint32_t color, int thickness);
void	get_player_to_grid(t_cubed *cubed, double *player_to_grid_x, double *player_to_grid_y);
void 	draw_screen(t_cubed *cubed);
void	reset_settings(t_cubed *cubed);
int32_t start_cubed(t_cubed *cubed);
void    draw_wall(t_cubed *cubed, size_t *wall_position);
void	get_perp_wall_dist(t_cubed *cubed, bool x_ray_is_shortest);
void	draw_player_mini_map(t_cubed *cubed);
void	clean_screen(t_cubed *cubed);

#endif
