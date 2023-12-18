#include "../../include/cubed.h"
#include "./get_next_line/get_next_line.h"
#include <fcntl.h>

char	**cub_to_double_array(int fd)
{	
	char	*line;
	char	*new_line;
	char	**double_array;

	while((line = get_next_line(fd))) // TODO: protect gnl?
		new_line = ft_strjoin(new_line, line); // TODO: protect string join
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

void	input_parsing(t_cubed *cubed, char *argv)
{
	int		fd;
	char	**file_array;

	// int index = 0;
	fd = open_cub_file(argv);
	file_array = cub_to_double_array(fd);
	parse_map(cubed, file_array);
	// validate_map(cubed);
	parse_start_pos(cubed);
	// printf("%i\n", cubed->pos_x);
	// printf("%i\n", cubed->pos_y);
	parse_path_pics(cubed, file_array);
	// parse_color_code(cubed, file_array);
	// while(cubed->map[index])
	// {
	// 	printf("\n%i ) %s", index , cubed->map[index]);
	// 	index++;
	// }
	close(fd);
}


