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

int	get_color(t_cubed *cubed, char *string, char *search)
{
	int i;
	int j;


	i = 0;
	j = 0;
	if (ft_strncmp(string, search, 2) == FOUND)
		{
			while(string[i])
			{
				while(cb_isnum(string[i]) == FALSE)
					i++;
				if (ft_strncmp(search, "C ", 2))
					cubed->ceiling_color[j] = cb_atoi(&string[i]);
				if (ft_strncmp(search, "F ", 2))
					cubed->floor_color[j] = cb_atoi(&string[i]);
				j++;
				while(cb_isnum(string[i]) == TRUE)
					i++;
			}
			return (FOUND);
		}
	return(NOT_FOUND);
}

void	parse_color_code(t_cubed *cubed, char **file_array)
{
	int	i;
	int	total_found;

	i = 0;
	total_found = 0;
	while (file_array[i])
	{
		if (get_color(cubed, file_array[i], "F ") == FOUND)
			total_found++;

		if (get_color(cubed, file_array[i], "C ") == FOUND)
			total_found++;
		i++;
	}
	if (total_found != 2)
	{
		perror("colors not found");
		exit (EXIT_FAILURE);
	}
}
