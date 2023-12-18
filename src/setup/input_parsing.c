#include "../../include/cubed.h"
# include "./get_next_line/get_next_line.h"
#include <fcntl.h>


char **copy_map(char **file, int start, int end, int index)
{
	char **map;
	int	strlen;

	map = malloc(((end - start) + 1) * sizeof(char*));
	if (!map)
	{
		perror("Malloc failed in copy_map #1\n");
		return (NULL);
	}
	map[end - start] = NULL;
    while (start < end)
    {
        strlen = ft_strlen(file[start]);
        map[index] = malloc((strlen + 1) * sizeof(char));
        if (!map[index])
        {
            perror("Malloc failed in copy_map #2\n");
            return (NULL);
        }
        ft_strlcpy(map[index], file[start], strlen);
        start++;
        index++;
    }
	return (map);
}

int	find_start_map(char **file)
{
	int i;
	int j;
	int	start;

	i = 0;
	j = 0;
	start = 0;
	while(file[i])
	{
		j = 0;
		while(file[i][j] == '1' || file[i][j] == ' ')
			j++;
		if (file[i][j] == '\0')
		{
			start = i;
			break ;
		}
		i++;
	}
	return (start);
}

char	**extract_map(char **file)
{
	char	**map;
	int		start;
	int 	end;
	int		norminette_intje;
	
	end = 0;
	norminette_intje = 0;
	start = find_start_map(file);
	while(file[end])
		end++;
	map = copy_map(file, start, end, norminette_intje);
	if (map == NULL)
		return (NULL);
	return (map);
}

char	**cub_to_double_array(int fd)
{	
	char	*line;
	char	*new_line;
	char	**double_array;

	while((line = get_next_line(fd))) // TODO: protect gnl?
		new_line = ft_strjoin(new_line, line); // TODO: protect string join??
	return (double_array = ft_split(new_line, '\n'));
	
}

int	open_cub_file(char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("failed to open .cub");
		return (CRASH);
	}
	return (fd);
}

int	input_parsing(t_cubed *cubed, char *argv)
{
	int		fd;
	char	**file_array;

	int index = 0;
	fd = open_cub_file(argv);
	file_array = cub_to_double_array(fd);
	cubed->map = extract_map(file_array);
	while(cubed->map[index])
	{
		printf("\n%i ) %s", index , cubed->map[index]);
		index++;
	}
	(void) cubed;
	close(fd);
	return (SUCCESS);
}
