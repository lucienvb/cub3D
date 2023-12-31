#include "../../include/cubed.h"

static int	cb_isnum(char a)
{
	if (a >= '0' && a <= '9')
		return (FOUND);
	return (NOT_FOUND);
}

static int	cb_atoi(const char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (cb_isnum(str[i]) == FOUND && str[i] && (i < 3))
	{
		result = result * 10;
		result = (result + (str[i] - '0'));
		i++;
	}
	if (result > 255)
		return (FAILED);
	return (result);
}

static int	get_color(t_cubed *cubed, char *line, char idf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (line[i] == idf)
	{
		while (line[i])
		{
			while (cb_isnum(line[i]) == NOT_FOUND)
				i++;
			if (idf == 'C')
				cubed->ceiling[j] = cb_atoi(&line[i]);
			else if (idf == 'F')
				cubed->floor[j] = cb_atoi(&line[i]);
			if (cubed->ceiling[j] == FAILED || cubed->floor[j] == FAILED)
				return (FAILED);
			if (j == 2)
				return (FOUND);
			j++;
			while (cb_isnum(line[i]) == FOUND)
				i++;
		}
	}
	return (NOT_FOUND);
}

int	parse_color_code(t_cubed *cubed)
{
	int	i;
	int	total_found;
	int	j;

	i = 0;
	total_found = 0;
	while (cubed->file[i])
	{
		j = 0;
		while (cb_isspace(cubed->file[i][j]) == FOUND)
			j++;
		if (get_color(cubed, &cubed->file[i][j], 'C') == FOUND)
			total_found++;
		else if (get_color(cubed, &cubed->file[i][j], 'F') == FOUND)
			total_found++;
		i++;
	}
	if (total_found != 2)
	{
		ft_printf("Error\n");
		ft_printf("Color code(s) incorrect\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
