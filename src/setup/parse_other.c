#include "../../include/cubed.h"

void	parse_start_pos(t_cubed *cubed)
{
	int	x;
	int y;

	y = 0;
	while (cubed->map[y])
	{
		x = 0;
		while (cubed->map[y][x])
		{
			if (cubed->map[y][x] == 'N' || cubed->map[y][x] == 'Z' ||
				cubed->map[y][x] == 'E' || cubed->map[y][x] == 'W')
			{
				cubed->pos_x = x;
				cubed->pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	perror("start position not found");
	exit (EXIT_FAILURE);
}

void	parse_path_pics(t_cubed *cubed, char **file_array)
{
	int	i;
	int	total_found;

	i = 0;
	total_found = 0;
	while (file_array[i])
	{
		if (strncmp(file_array[i], "F ", 2) == FOUND)
		{
			cubed->floor_color(file_array)

		}
		if (strncmp(file_array[i], "C ", 2) == FOUND)
		{


		}
		i++;
	}
	
	printf("%s\n", F);
	printf("%s\n", C);
	if (total_found != 2)
	{
		perror("path to png pictures not found");
		exit (EXIT_FAILURE);
	}
}