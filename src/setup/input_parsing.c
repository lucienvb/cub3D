#include "../../include/cubed.h"
#include <fcntl.h>

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
char **read_cub_file(int fd)
{
	
	bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read == -1)
	{
		perror("failed to read fd");
		return (NULL);
	}
	if (bytes_read == 0)
	{
		perror("empty .cub file");
		return (NULL);
	}
	return (buffer);
}

int	input_parsing(t_cubed *cubed, char *argv)
{
	char	**buffer;
	int		fd;
	int index = 0;

	fd = open_cub_file(argv);
	buffer = read_cub_file(fd);
	if (buffer == NULL)
		return (FAILURE);
	while(buffer[index])
	{
		printf("%s", buffer[index]);
		index++;
	}
	close(fd);
	return (SUCCESS);
}