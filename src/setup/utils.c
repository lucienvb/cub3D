/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 14:57:53 by cter-maa      #+#    #+#                 */
/*   Updated: 2024/03/13 15:10:57 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

char	*cd_strndup(const char *str, size_t n)
{
	size_t	i;
	char	*dup;

	if (!str)
		return (NULL);
	if (ft_strlen(str) < n)
		n = ft_strlen(str);
	dup = ft_calloc (n + 1, sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = str[i];
		i++;
	}
	dup[n] = '\0';
	return (dup);
}

int	validate_map_char(int c)
{
	if (((c == 'N') || (c == 'E') || (c == 'S')
			|| (c == 'W') || (c == '1') || (c == '0') || (c == ' ')))
		return (TRUE);
	return (FALSE);
}

int	cb_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\0')
		return (FOUND);
	else
		return (NOT_FOUND);
}

void	print_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_printf("%c", map[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}
