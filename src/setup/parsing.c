#include "../../include/cubed.h"
#include "./get_next_line/get_next_line.h"
#include <fcntl.h>

static char	**cub_to_double_array(int fd) // todo: check if free correctly!!
{
	char	*line;
	char	*new_line;
	char	**file;
	char	*temp;

	new_line = ft_calloc(1, 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = new_line;
		new_line = ft_strjoin(new_line, line);
		free(line);
		free(temp);
		if (new_line == NULL)
			return (NULL);
		line = get_next_line(fd);
	}
	file = ft_split(new_line, '\n');
	free(new_line);
	return (file);
}

static int	parsing(t_cubed *cubed)
{
	if (parse_map(cubed) == FAILURE)
	{
		close(cubed->fd);
		free_2d_array(cubed->file);
		ft_printf("Error: Invalid file\n");
		exit(EXIT_FAILURE);
	}
	if (parse_color_code(cubed) == FAILURE)
		return (FAILURE);
	if (parse_texture(cubed) == FAILURE)
		return (FAILURE);
	if (parse_start_pos(cubed) == FAILURE){
		printf("Error: Incorrect start positions(s)\n");
		return (FAILURE);
	}
	// cubed->intMap = create_intMap(cubed); // todo: protect
	// printIntArray(cubed);
	return (SUCCESS);
}

int	input_parsing(t_cubed *cubed, char *argv)
{
	cubed->fd = open(argv, O_RDONLY);
	if (cubed->fd == -1)
		perror_exit("Failed to open .cub");
	cubed->file = cub_to_double_array(cubed->fd);
	if (cubed->file == NULL)
		error_exit("Failed to parse map to 2d array\n");
	if (parsing(cubed) == FAILURE)
		return (FAILURE);
	print_map(cubed->map_val);
	if (validate_map(cubed, cubed->start_pos[Y], cubed->start_pos[X])
		== FAILURE)
	{
		ft_printf("Error: Invalid map\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
