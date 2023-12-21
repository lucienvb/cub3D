#include "../../include/cubed.h"

int	save_pos(t_cubed *cubed, int x, int y)
{
	cubed->start_pos[Y] = y;
	cubed->start_pos[X] = x;
	cubed->map[y][x] = '0';
	return (1);
}

void	parse_start_pos(t_cubed *cubed)
{
	int	x;
	int y;
	int	count;
	int flag;

	count = 0;
	y = 0;
	while (cubed->map[y])
	{
		x = 0;
		flag = 0;
		while (cubed->map[y][x])
		{
			if (cubed->map[y][x] == '1' && cubed->map[y][x + 1] == '0')
				flag = 1;
			if ((cubed->map[y][x] == 'N' || cubed->map[y][x] == 'Z' ||
				cubed->map[y][x] == 'E' || cubed->map[y][x] == 'W') 
					&& (flag == 1))
				count += save_pos(cubed, x, y);
			x++;
		}
		y++;
	}
	if (count != 1)
		perror_exit("invalid or no start position(s)");
}

int	validate_map(t_cubed *cubed, int y, int x) 
{
	char	wall;
	char	flag;

	wall = '1';
	flag = '2';

	if (x < 0 || y < 0)
		return (0);
	 if (y >= cubed->height || x >= cubed->width) 
        return 0;
	if (cubed->map[y][x] == wall || cubed->map[y][x] == flag)
		return (0);
	if (x == 0 || y == 0 || y == cubed->height - 1
		|| x == cubed->width - 1)
		return (1); //
	if (cubed->map[y][x] && cubed->map[y][x] != '0')
		return (1);
	cubed->map[y][x] = flag;
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
