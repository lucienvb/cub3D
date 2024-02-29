#include "../../include/cubed.h"

static int	save_pos(t_cubed *cubed, char pos, int x, int y)
{
	cubed->start_pos[Y] = y;
	cubed->start_pos[X] = x;
	cubed->start_cardinal_point = pos;
	cubed->map_val[y][x] = '0';
	cubed->map[y][x] = '0';
	return (1);
}

static int	is_cardinal_point(char c)
{
	if ((c == 'N' || c == 'S' || c == 'E' || c == 'W'))
		return (TRUE);
	return (FALSE);
}

int	parse_start_pos(t_cubed *cubed)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (cubed->map[y])
	{
		printf("%i ", y);
		x = 0;
		while (cubed->map[y][x])
		{
			while(cubed->map[y][x] && (cubed->map[y][x] == ' ' || 
				cubed->map[y][x] == '1'))
					x++;
			if (is_cardinal_point(cubed->map[y][x]) == TRUE)
				count += save_pos(cubed, cubed->map[y][x], x, y);
			if(cubed->map[y][x])
				x++;
		}
		y++;
	}
	if (count != 1)
		return (FAILURE);
	return (SUCCESS);
}

int	validate_map(t_cubed *cubed, int y, int x)
{
	char	wall;
	char	flag;

	wall = '1';
	flag = 'X';
	if (x < 0 || y < 0)
		return (0);
	if (y >= cubed->total_row || x >= cubed->max_column
		|| cubed->map_val[y][x] == wall || cubed->map_val[y][x] == flag)
		return (0);
	if (x == 0 || y == 0 || y == cubed->total_row - 1 || x == cubed->max_column - 1)
		return (1);
	if (cubed->map_val[y][x] && cubed->map_val[y][x] != '0')
		return (1);
	cubed->map_val[y][x] = flag;
	if (validate_map(cubed, y + 1, x) == 1)
		return (1);
	if (validate_map(cubed, y - 1, x) == 1)
		return (1);
	if (validate_map(cubed, y, x + 1) == 1)
		return (1);
	if (validate_map(cubed, y, x - 1) == 1)
		return (1);
	return (0);
}
