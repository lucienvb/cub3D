#include "../../include/cubed.h"
#include "./get_next_line/get_next_line.h"
#include <fcntl.h>

char	**cub_to_double_array(int fd) // todo: check if free correctly!!
{	
	char	*line;
	char	*new_line;
	char	**file;

	new_line = "";
	while((line = get_next_line(fd)))
	{
		new_line = ft_strjoin(new_line, line); // todo: protect string join
		if (new_line == NULL)
			return (NULL);
	}
	file = ft_split(new_line, '\n');
	free(line);
	free(new_line);
	return (file);
}

void	test_input(t_cubed *cubed)
{
	int index = 0;
	while(cubed->map[index])
	{
		printf("\n%i ) %s", index , cubed->map[index]);
		index++;
	}

	printf("\n\n%i = cubed->pos_y\n", cubed->start_pos[Y]);
	printf("%i = cubed->pos_x\n", cubed->start_pos[X]);
	index = 0;
	printf("\n\nceiling color: ");
	while(index < 3)
	{
		printf(" %i", cubed->ceiling_color[index]);
		index++;
	}
	printf("\n");
	index = 0;
	printf("floor color: ");
	while(index < 3)
	{
		printf(" %i", cubed->floor_color[index]);
		index++;
	}
	printf("\n");
}

int	parsing(t_cubed *cubed)
{
	if (parse_map(cubed) == FAILURE)
	{
		close(cubed->fd);
		free_2d_array(cubed->file);
		error_exit("malloc failed in parsing");
	}
	if (parse_color_code(cubed) == FAILURE)
		return (FAILURE);
	if (parse_texture(cubed) == FAILURE)
		return (FAILURE);
	if (parse_start_pos(cubed) == FAILURE)
		return (FAILURE);
	if (parse_map_dimensions(cubed) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	input_parsing(t_cubed *cubed, char *argv)
{
	cubed->fd = open(argv, O_RDONLY);
	if (cubed->fd == -1)
		perror_exit("failed to open .cub");
	cubed->file = cub_to_double_array(cubed->fd);
	if (cubed->file == NULL)
		error_exit("failed to parse map to 2d array");
	if (validate_map(cubed, cubed->start_pos[Y], cubed->start_pos[X]) == FAILURE)
	{
		ft_printf("incorrect borders in map");
		return (FAILURE);
	}
	test_input(cubed);
	return (SUCCESS);
}
