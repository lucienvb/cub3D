#include "../../include/cubed.h"

char *load_path(char *line)
{
    char *path;
    int start = 0;
    int end = 0;

    while (cb_isspace(line[start]) == FOUND && line[start])
        start++;
    end = start;
    while (!cb_isspace(line[end] == NOT_FOUND) && line[end])
        end++;
    path = cd_strndup(&line[start], end - 1);
    return (path);
}

int save_texture(t_cubed *cubed, char *line)
{
    char *path;
	
	path =  load_path(&line[2]);
    if (!path)
    {
        free(path);
        return NOT_FOUND;
    }
    if (ft_strncmp(line, "NO ", 3) == FOUND)
        cubed->n_texture = mlx_load_png(path);
    else if (ft_strncmp(line, "EA ", 3) == FOUND)
        cubed->e_texture = mlx_load_png(path);
    else if (ft_strncmp(line, "SO ", 3) == FOUND)
        cubed->s_texture = mlx_load_png(path);
    else if (ft_strncmp(line, "WE ", 3) == FOUND)
        cubed->w_texture = mlx_load_png(path);
    else
    {
        free(path);
        return NOT_FOUND;
    }
    free(path);
    return FOUND;
}

int	parse_texture(t_cubed *cubed)
{
	int	i;
	int	j;
	int	total_found;

	total_found = 0;
	i = 0;
	while (cubed->file[i])
	{
		j = 0;
		while (cb_isspace(cubed->file[i][j]) == FOUND && cubed->file[i][j])
			j++;

		if (save_texture(cubed, &cubed->file[i][j]) == FOUND)
			total_found += 1;
		i++;
	}
	if (total_found != 4)
	{
		ft_printf("Error:\nIncorrect path(s)\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
