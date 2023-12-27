#include "../../include/cubed.h"

char *remove_space(char *line)
{
	int index;

	index = 0;
	while(cb_isspace(line[index]) == FOUND)
		index++;
	return (&line[index]);
}

int	save_texture(t_cubed *cubed, char *line)
{
	int	found;

	char *line_nospace;
	found = 0;
	if (ft_strncmp(line, "NO ", 3) == FOUND)
	{
		line_nospace = remove_space(&line[2]);
		printf("%s\n", line_nospace);
		found++;
	}
	if (ft_strncmp(line, "EA ", 3) == FOUND)
	{
		line_nospace = remove_space(&line[2]);
		printf("%s\n", line_nospace);
		found++;
	}
	if (ft_strncmp(line, "SO ", 3) == FOUND)
	{
		line_nospace = remove_space(&line[2]);
		printf("%s\n", line_nospace);
		found++;
	}
	if (ft_strncmp(line, "WE ", 3) == FOUND)
	{
		line_nospace = remove_space(&line[2]);
		printf("%s\n", line_nospace);
		found++;
	}
	if (found == 1000) // todo: here to surpass compile flags, REMOVE
		printf("%i", cubed->start_cardinal_point);
	return (found);
}

// todo: actual function below, dont delete!!!!!!!

// int	save_texture(t_cubed *cubed, char *line)
// {
// 	if (ft_strncmp(line, "NO ", 3) == FOUND)
// 	{
// 		cubed->n_texture = remove_space(&line[2]);
// 		return (FOUND);
// 	}
// 	if (ft_strncmp(line, "EA ", 3) == FOUND)
// 	{
// 		cubed->e_texture = remove_space(&line[2]);
// 		return (FOUND);
// 	}
// 	if (ft_strncmp(line, "SO ", 3) == FOUND)
// 	{
// 		cubed->s_texture = remove_space(&line[2]);
// 		return (FOUND);
// 	}
// 	if (ft_strncmp(line, "WE ", 3) == FOUND)
// 	{
// 		cubed->w_texture = remove_space(&line[2]);
// 		return (FOUND);
// 	}
// 	return (NOT_FOUND;
// }

void	parse_texture(t_cubed *cubed, char **file) // todo: Does not check if path is correct!!
{
	int	i;
	int	j;
	int	total_found;

	total_found = 0;
	i = 0;
	while (file[i])
	{
		j = 0;
		while (cb_isspace(file[i][j]) == FOUND)
			j++;
		total_found += save_texture(cubed, &file[i][j]);
		i++;
	}
	if (total_found != 4)
	{
		printf("\n%i ignore\n", total_found);
		error_exit("incorrect path(s)");
	}
}
