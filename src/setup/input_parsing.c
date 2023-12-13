#include "cubed.h"
#include <fcntl.h>

char **cub_to_buffer(char *argv)
{
	char	**buffer;
	int		bytes_read;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("failed to open .cub");
		return (NULL);
	}
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

int	input_parsing(t_cubed cubed, char *argv)
{
	char	**buffer;
	int index = 0;

	buffer = cub_to_buffer(argv);
	if (buffer == NULL)
		return (FAILURE);
	while(buffer[index])
	{
		printf("%s", buffer[index]);
		index++;
	}
}