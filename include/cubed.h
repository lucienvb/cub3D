#ifndef CUBED_H
#define CUBED_H

// headers
# include <stdlib.h>
# include <stdio.h> // remove
# include <unistd.h>
# include <string.h> // remove

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
	char		**start_pos;
	char		*argv;
	size_t		*ceiling_color;
	size_t		*floor_color;
	char		*EA;
	char		*WE;
	char		*NO;
	char		*SO;
	t_mlx		*mlx;
	t_screen	*screen;
} t_cubed;

// src/setup
void	input_error_handling(int argc, char **argv);
void	input_initialization(t_cubed *cubed, t_mlx *mlx, t_screen *screen, char *argv);
int		input_parsing(t_cubed *cubed, char *argv);


// temp
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
