/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 14:58:00 by cter-maa      #+#    #+#                 */
/*   Updated: 2024/03/13 15:10:06 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static int	save_pos(t_cubed*c, char pos, int x, int y)
{
	c->start_pos[Y] = y;
	c->start_pos[X] = x;
	c->start_cardinal_point = pos;
	c->map_val[y][x] = '0';
	c->map[y][x] = '0';
	return (1);
}

static int	is_cardinal_point(char c)
{
	if ((c == 'N' || c == 'S' || c == 'E' || c == 'W'))
		return (TRUE);
	return (FALSE);
}

int	parse_start_pos(t_cubed*c)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (c->map[y])
	{
		printf("%i ", y);
		x = 0;
		while (c->map[y][x])
		{
			while (c->map[y][x] && (c->map[y][x] == ' ' || c->map[y][x] == '1'))
				x++;
			if (is_cardinal_point(c->map[y][x]) == TRUE)
				count += save_pos(c, c->map[y][x], x, y);
			if (c->map[y][x])
				x++;
		}
		y++;
	}
	if (count != 1)
		return (FAILURE);
	return (SUCCESS);
}

int	validate_map(t_cubed*c, int y, int x)
{
	char	wall;
	char	flag;

	wall = '1';
	flag = 'X';
	if (x < 0 || y < 0)
		return (0);
	if (y >= c->total_row || x >= c->max_column
		|| c->map_val[y][x] == wall || c->map_val[y][x] == flag)
		return (0);
	if (x == 0 || y == 0 || y == c->total_row - 1 || x == c->max_column - 1)
		return (1);
	if (c->map_val[y][x] && c->map_val[y][x] != '0')
		return (1);
	c->map_val[y][x] = flag;
	if (validate_map(c, y + 1, x) == 1)
		return (1);
	if (validate_map(c, y - 1, x) == 1)
		return (1);
	if (validate_map(c, y, x + 1) == 1)
		return (1);
	if (validate_map(c, y, x - 1) == 1)
		return (1);
	return (0);
}
