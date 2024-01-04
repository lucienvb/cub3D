#include "../../include/cubed.h"

int	parse_map_dimensions(t_cubed *cubed)
{
	int	y;
	int	x;
	int	max_x;

	y = 0;
	max_x = 0;
	while (cubed->map[y])
	{
		x = 0;
		while (cubed->map[y][x])
			x++;
		if (x >= max_x)
			max_x = x;
		y++;
	}
	if (y == 0 || x == 0)
	{
		ft_printf("incorrect map\n");
		return (FAILURE);
	}
	cubed->height = y;
	cubed->width = max_x;
	return (SUCCESS);
}

static char	**copy_map(char **file, int start, int end)
{
	char	**map;
	int		strlen;
	int		index;

	index = 0;
	map = malloc(((end - start) + 1) * sizeof (char*));
	if (!map)
		return (NULL);
	map[end - start] = NULL;
	while (start < end)
	{
		strlen = ft_strlen(file[start]);
		map[index] = malloc((strlen + 1) * sizeof(char));
		if (!map[index])
			return (NULL);
		ft_strlcpy(map[index], file[start], strlen + 1);
		start++;
		index++;
	}
	return (map);
}

static int	find_start_map(char **file, int i)
{
	int	j;
	int	start;

	j = 0;
	start = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j] == '1' || file[i][j] == ' ')
			j++;
		if (file[i][j] == '\0')
		{
			start = i;
			break ;
		}
		i++;
	}
	return (start);
}

int	parse_map(t_cubed *cubed)
{
	int	start;
	int	end;

	end = 0;
	start = find_start_map(cubed->file, 0);
	if (start == 0)
		return (FAILURE);
	end = find_start_map(cubed->file, start + 1) + 1;
	if (cubed->file[end] != NULL)
		return (FAILURE);
	cubed->map = copy_map(cubed->file, start, end);
	if (cubed->map == NULL)
		return (FAILURE);
	cubed->map_val = copy_map(cubed->file, start, end);
	if (cubed->map_val == NULL)
	{
		free_2d_array(cubed->map);
		return (FAILURE);
	}
	return (SUCCESS);
}
