#ifndef CUBED_H
#define CUBED_H

// headers
# include <stdlib.h>
# include <stdio.h> 
# include <unistd.h>
// # include <MLX42/MLX42.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

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


// enum


// structures

	
typedef struct s_mlx
{
	int	i; //only here to surpass flags
} t_mlx;

typedef struct s_screen
{
	int	i; //only here to surpass flags
} t_screen;

typedef struct s_cubed
{
	char		**map;
	char		*argv;
	int			start_pos[2];
	int			ceiling_color[3];
	int			floor_color[3];
	int		width;
	int		height;
	// mlx_texture_t	*n_texture;
	// mlx_texture_t	*e_texture;
	// mlx_texture_t	*s_texture;
	// mlx_texture_t	*w_texture;
	t_mlx		*mlx;
	t_screen	*screen;
} t_cubed;

// src/setup/input
void	input_error_handling(int argc, char **argv);
void	input_initialization(t_cubed *cubed, t_mlx *mlx, t_screen *screen, char *argv);
char	*get_next_line(int fd);

// src/setup/parsing
void	input_parsing(t_cubed *cubed, char *argv);
char	**cub_to_double_array(int fd);
void	parse_map(t_cubed *cubed, char **file);
void	parse_start_pos(t_cubed *cubed);
void	parse_color_code(t_cubed *cubed, char **file_array);
void	parse_texture(t_cubed *cubed, char **file_array);
int		validate_map(t_cubed *cubed, int x, int y);
void	parse_map_dimensions(t_cubed *cubed);

// src/setup/utils
int		validate_map_char(int c);
int		cb_atoi(const char *str);
int		cb_isnum(char c);
int		cb_isspace(int c);
void	perror_exit(char *message);

#endif
