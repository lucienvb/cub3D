#ifndef CUBED_H
#define CUBED_H

// headers
# include <stdlib.h>
# include <stdio.h> // remove
# include <unistd.h>
# include <string.h> // remove
# include "../lib/libft/libft.h"
# include "../lib/libft/ft_printf/ft_printf.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"

// defines
# define FAILURE		1
# define SUCCESS		0
# define NOT_FOUND		1
# define FOUND			0
# define TRUE			1
# define FALSE			0
# define SCREEN_WIDTH	640
# define SCREEN_HEIGHT	480

// enum


// structures
typedef struct s_cubed
{
	mlx_t	*mlx;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	time;
	double	oldTime;
	double	pa;
	double	px;
	double	py;
	double	pdx;
	double	pdy;
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

#endif