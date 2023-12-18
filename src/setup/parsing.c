#include "../../include/cubed.h"
#include "./get_next_line/get_next_line.h"
#include <fcntl.h>

char	**cub_to_double_array(int fd)
{	
	char	*line;
	char	*new_line;
	char	**double_array;

	while((line = get_next_line(fd))) // todo: protect gnl?
		new_line = ft_strjoin(new_line, line); // todo: protect string join
	return (double_array = ft_split(new_line, '\n'));
}

int	open_cub_file(char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("failed to open .cub");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	test_input(t_cubed *cubed)
{
	int index = 0;
	while(cubed->map[index])
	{
		printf("\n%i ) %s", index , cubed->map[index]);
		index++;
	}

	printf("\n\n%i = cubed->pos_x\n", cubed->pos_x);
	printf("%i = cubed->pos_y\n", cubed->pos_y);
	index = 0;
	printf("\n\nceiling color: ");
	while(index < 3)
	{
		printf("%i ", cubed->ceiling_color[index]);
		index++;
	}
	index = 0;
	printf("\nfloor color: ");
	while(index < 3)
	{
		printf("%i ", cubed->floor_color[index]);
		index++;
	}
	printf("\n %s", cubed->NO);
}

void	input_parsing(t_cubed *cubed, char *argv)
{
	int		fd;
	char	**file_array;

	fd = open_cub_file(argv);
	file_array = cub_to_double_array(fd); // todo: free
	parse_map(cubed, file_array);
	// validate_map(cubed);
	parse_start_pos(cubed);
	parse_path_pics(cubed, file_array);
	parse_color_code(cubed, file_array);
	test_input(cubed);

	close(fd);
}


