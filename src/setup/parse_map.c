#include "../../include/cubed.h"

int	parse_map_dimensions(t_cubed *cubed)
{
	int	y;
	int	x;
	int	max_x;

	y = 0;
	max_x = 0;
	while(cubed->map[y])
	{
		x = 0;
		while(cubed->map[y][x])
			x++;
		if (x >= max_x)
			max_x = x;
		y++;
	}
	if (y == 0 || x == 0)
	{
		ft_printf("incorrect map");
		return (FAILURE);
	}
	cubed->height = y;
	cubed->width = max_x;
	return (SUCCESS);
}

char **copy_map(char **file, int start, int end, int index)
{
	char **map;
	int	strlen;

	map = malloc(((end - start) + 1) * sizeof(char*));
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

int	find_start_map(char **file) 
{
	int i;
	int j;
	int	start;

	i = 0;
	j = 0;
	start = 0;
	while(file[i])
	{
		j = 0;
		while(file[i][j] == '1' || file[i][j] == ' ')
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
	int		start;
	int 	end;
	int		norminette_intje;
	
	end = 0;
	norminette_intje = 0;
	start = find_start_map(cubed->file);
	if (start == 0)
		error_exit("map is incorrect or not present");
	while(cubed->file[end])
		end++;
	cubed->map = copy_map(cubed->file, start, end, norminette_intje);
	if (cubed->map == NULL)
		return (FAILURE);
	cubed->map_val = copy_map(cubed->file, start, end, norminette_intje);
	if (cubed->map_val == NULL)
	{
		free_2d_array(cubed->map);
		return (FAILURE);
	}
	return (SUCCESS);
}

