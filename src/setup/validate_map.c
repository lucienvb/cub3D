#include "../../include/cubed.h"

int	save_pos(t_cubed *cubed, char pos, int x, int y)
{
	cubed->start_pos[Y] = y;
	cubed->start_pos[X] = x;
	cubed->start_cardinal_point = pos;
	cubed->map_val[y][x] = '0';
	return (1);
}

int	is_cardinal_point(char c)
{
	if ((c == 'N' || c == 'S' ||
				c == 'E' || c == 'W'))
		return (TRUE);
	return (FALSE);
}

void	parse_start_pos(t_cubed *cubed)
{
	int	x;
	int y;
	int	count;
	int flag;

	count = 0;
	y = 0;
	while (cubed->map_val[y])
	{
		x = 0;
		flag = 0;
		while (cubed->map_val[y][x])
		{
			if (cubed->map_val[y][x] == '1' && cubed->map_val[y][x + 1] == '0')
				flag = 1;
			if (is_cardinal_point(cubed->map_val[y][x]) == TRUE && flag == 1)
				count += save_pos(cubed, cubed->map_val[y][x], x, y);
			x++;
		}
		y++;
	}
	if (count != 1)
	{
		printf("%i \n", count);
		error_exit("invalid or no start position(s)");
	}
}

int	validate_map(t_cubed *cubed, int y, int x)
{
	char	wall;
	char	flag;

	wall = '1';
	flag = 'X';

	if (x < 0 || y < 0)
		return (0);
	 if (y >= cubed->height || x >= cubed->width ||
	 cubed->map_val[y][x] == wall || cubed->map_val[y][x] == flag) 
        return 0;
	if (x == 0 || y == 0 || y == cubed->height - 1 || x == cubed->width - 1)
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
