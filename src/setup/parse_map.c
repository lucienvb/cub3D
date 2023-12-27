#include "../../include/cubed.h"

void	parse_map_dimensions(t_cubed *cubed)
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
	cubed->height = y;
	cubed->width = max_x;
	printf("%i = map height\n", cubed->height);
	printf("%i = map width\n", cubed->width);
}

char **copy_map(char **file, int start, int end, int index)
{
	char **map;
	int	strlen;

	map = malloc(((end - start) + 1) * sizeof(char*));
	if (!map)
		perror_exit("Malloc failed in copy_map #1\n");
	map[end - start] = NULL;
    while (start < end)
    {
        strlen = ft_strlen(file[start]);
        map[index] = malloc((strlen + 1) * sizeof(char));
        if (!map[index])
			perror_exit("Malloc failed in copy_map #2\n");
        ft_strlcpy(map[index], file[start], strlen + 1); // TODO: protect?
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

void	parse_map(t_cubed *cubed, char **file)
{
	int		start;
	int 	end;
	int		norminette_intje;
	
	end = 0;
	norminette_intje = 0;
	start = find_start_map(file);
	if (start == 0)
		error_exit("empty file");
	while(file[end])
		end++;
	cubed->map = copy_map(file, start, end, norminette_intje);
}

