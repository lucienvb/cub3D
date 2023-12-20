#include "../../include/cubed.h"

// int	check_start_char(char c)
// {

// 	return (FOUND);
// }

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
			{
				cubed->pos_x = x;
				cubed->pos_y = y;
				count++;
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		perror_exit("invalid or no start position(s)");
}

int	validate_map(t_cubed *cubed, size_t x, size_t y) //cubed->map needs a duplicate
{ // not working because of start pos?
	char	wall;
	char	flag;

	wall = '1';
	flag = '2';

	if (cubed->map[y][x] == wall || cubed->map[y][x] == flag)
		return (0);
	else if (cubed->map[y][x] != '0' && cubed->map[y][x])
		return (1);
	cubed->map[y][x] = flag;
	if (validate_map(cubed, x + 1, y) == 1)
		return (1);
	if (validate_map(cubed, x - 1, y) == 1)
		return (1);
	if (validate_map(cubed, x, y + 1) == 1)
		return (1);
	if (validate_map(cubed, x, y - 1) == 1)
		return (1);
	return (0);
}
