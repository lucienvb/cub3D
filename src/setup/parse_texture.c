#include "../../include/cubed.h"

void	parse_texture(t_cubed *cubed, char **file) // todo: Does not check if path is right!!
{
	int				total_found;
	int				i;
	// mlx_texture_t	*texture;

	total_found = 0;
	i = 0;
	printf("\n paths textures:\n");
	while (file[i])
	{
		if (ft_strncmp(file[i], "NO ", 3) == FOUND)
		{
			printf("NO = %s\n", &file[i][3]); // for testing purposes
			// cubed->n_texture = &file[i][3];
			total_found++;
		}
		if (ft_strncmp(file[i], "EA ", 3) == FOUND)
		{
			printf("EA = %s\n", &file[i][3]); // for testing purposes
			// cubed->e_texture = &file[i][3];
			total_found++;
		}
		if (ft_strncmp(file[i], "SO ", 3) == FOUND)
		{
			printf("SO = %s\n", &file[i][3]); // for testing purposes
			// cubed->s_texture = &file[i][3];
			total_found++;
		}
		if (ft_strncmp(file[i], "WE ", 3) == FOUND)
		{
			printf("WE = %s\n", &file[i][3]); // for testing purposes
			// cubed->w_texture = &file[i][3];
			total_found++;
		}
		i++;
	}
	if (total_found != 4)
	{
		printf("%i", cubed->pos_x);
		perror("path missing");
		exit (EXIT_FAILURE);
	}
}
