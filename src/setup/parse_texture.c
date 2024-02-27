#include "../../include/cubed.h"

static char *remove_space(char *line)
{
	int start;
	int     end;
	char *tex;

	start = 0;
	end = 0;
	while (cb_isspace(line[start]) == FOUND && line[start])
		start++;
	end = start;
	while(!cb_isspace(line[end] == NOT_FOUND) && line[end])
		end++;
	tex = cd_strndup(&line[start], end -1);
	return (tex);
}

int save_texture(t_cubed *cubed, char *line)
{
	mlx_texture_t	*texture;
	char *tex;

	tex = remove_space(&line[2]);
	if (!tex){
		free (tex);
		return (NOT_FOUND);
	}
	printf("%s\n", tex);
	texture = mlx_load_png(tex); 
	free(tex);
	if (!texture)
		return (FAILURE);
	if (ft_strncmp(line, "NO ", 3) == FOUND)
		cubed->n_texture = texture;
	else if (ft_strncmp(line, "EA ", 3) == FOUND)
		cubed->e_texture = texture;  
	else if (ft_strncmp(line, "SO ", 3) == FOUND)
		cubed->s_texture = texture; 
	else if (ft_strncmp(line, "WE ", 3) == FOUND)
		cubed->w_texture = texture;
	else
		return (NOT_FOUND);
	return (FOUND);
}

int	parse_texture(t_cubed *cubed) // todo: Does not check if path is correct!!
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
		printf("%i = total_found\n", total_found);
		ft_printf("Error: Incorrect path(s)\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
