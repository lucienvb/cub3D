#include "cubed.h"
#include <string.h> //remove

static void    print_input_info(void) // change to ft_printf
{
	printf("wrong input\n");
	printf("cub3d program requires 2 argmuents:\n");
	printf("< ./cubed >  +  < map_name >\n");
}

static int check_file_type(char *argv)
{
	int index;
	index = 0;

	while(argv[index])
	{
		if (argv[index] == '.')
		{
		  if (strcmp(&argv[index], ".cub") == FOUND)
		  	return (SUCCESS);
		}
		index++;
	}
	return (FAILURE);
}


void   error_handling(int argc, char **argv)
{
	if (argc != 2 || !*argv[1] || (strcmp(argv[1], " ") == FOUND)) //change to ft_strcmp!!
	{
		print_input_info();
		exit(EXIT_FAILURE);
	}
	if (check_file_type(argv[1]) == FAILURE)
	{
		printf("wrong file type"); // change to ft_printf
		exit(EXIT_FAILURE);
	}
}
