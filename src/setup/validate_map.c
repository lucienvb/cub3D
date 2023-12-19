#include "../../include/cubed.h"

void	parse_start_pos(t_cubed *cubed)
{
	int	x;
	int y;
	int	count;

	y = 0;
	count = 0;
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
				count++;
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		perror_exit("invalid or no start position(s)");
}

void	validate_border(t_cubed *cubed, int x, int y)
{
	// if (x == 0 || y == 0 || cubed->map[y + 1] == NULL)
	// 	perror_exit("empty file 2");
	if (cb_isspace(cubed->map[y][x - 1]) || cb_isspace(cubed->map[y][x + 1])
			|| cb_isspace(cubed->map[y - 1][x]) || cb_isspace(cubed->map[y + 1][x]))
		perror_exit("map borders are incorrect");
}

void	validate_map(t_cubed *cubed)
{
	int	x;
	int	y;
	int	position_char;

	y = 0;
	position_char = 0;

	while(cubed->map[y] && position_char <= 1)
	{
		x = 0;
		while(cubed->map && position_char <= 1)
		{
			if (validate_map_char(cubed->map[y][x]) == FALSE)
				perror_exit("invalid character detected in map");
			validate_border(cubed, x, y);
			x++;
		}
		y++;
	}
}
