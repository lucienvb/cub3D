#ifndef CUBED_H
# define CUBED_H

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

// structures
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
	int			width;
	int			height;
	// mlx_texture_t	*n_texture;
	// mlx_texture_t	*e_texture;
	// mlx_texture_t	*s_texture;
	// mlx_texture_t	*w_texture;
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

//src/cleanup
void	free_2d_array(char **array);
void	free_allocations(t_cubed *cubed);

#endif
