#include "../../include/cubed.h"

int	save_path(t_cubed *cubed, char *string, char *idf) // todo: malloc
{
	
	int i;
	int strlen;

	i = 0;
	strlen = ft_strlen(&string[i]);
	if (ft_strncmp(string, idf, 3) == FOUND)
	{
		while(string[i] != '.')
			i++;
		cubed->NO = malloc(sizeof(char) * (strlen + 1)); 
		if (cubed->NO == NULL)
		{
			perror("malloc failed in get path");
			exit(EXIT_FAILURE);
		}
		cubed->NO[strlen + 1] = '\0';
		ft_memcpy(cubed->NO, &string[i], ft_strlen(&string[i]));
		return (FOUND);
	}
	return(NOT_FOUND);
}

void	parse_path_pics(t_cubed *cubed, char **file_array)
{
	int	i;
	int	total_found;

	i = 0;
	total_found = 0;
	while (file_array[i])
	{
		if (get_path(cubed, file_array[i], "NO ") == FOUND)
			total_found++;
		if (get_path(cubed, file_array[i], "SO ") == FOUND)
			total_found++;
		if (get_path(cubed, file_array[i], "WE ") == FOUND)
			total_found++;
		if (get_path(cubed, file_array[i], "EA ") == FOUND)
			total_found++;
		i++;
	}
	if (total_found != 4)
	{
		perror("path to png not found");
		exit (EXIT_FAILURE);
	}
}
