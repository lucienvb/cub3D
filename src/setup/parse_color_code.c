#include "../../include/cubed.h"

int	get_color(t_cubed *cubed, char *line, char *identifier)
{
	int i;
	int j;


	i = 0;
	j = 0;
	if (ft_strncmp(line, identifier, 2) == FOUND)
		{
			while(line[i])
			{
				while(cb_isnum(line[i]) == FALSE)
					i++;
				if (ft_strncmp(identifier, "C ", 2))
					cubed->ceiling_color[j] = cb_atoi(&line[i]);
				if (ft_strncmp(identifier, "F ", 2))
					cubed->floor_color[j] = cb_atoi(&line[i]);
				j++;
				while(cb_isnum(line[i]) == TRUE)
					i++;
			}
			return (FOUND);
		}
	return(NOT_FOUND);
}

void	parse_color_code(t_cubed *cubed, char **file)
{
	int	i;
	int	total_found;

	i = 0;
	total_found = 0;
	while (file[i])
	{
		if (get_color(cubed, file[i], "F ") == FOUND)
			total_found++;

		if (get_color(cubed, file[i], "C ") == FOUND)
			total_found++;
		i++;
	}
	if (total_found != 2)
		error_exit("color code(s) incorrect");
}
