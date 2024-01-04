#include "../../include/cubed.h"

void	error_exit(char *message)
{
	ft_printf("Error \n");
	ft_printf("%s \n", message);
	exit(EXIT_FAILURE);
}

void	perror_exit(char *message)
{
	ft_printf("Error \n");
	perror(message);
	exit(EXIT_FAILURE);
}

int	validate_map_char(int c)
{
	if (((c == 'N') || (c == 'E') || (c == 'S')
			|| (c == 'W') || (c == '1') || (c == '0') || (c == ' ')))
		return (TRUE);
	return (FALSE);
}

int	cb_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\0')
		return (FOUND);
	else
		return (NOT_FOUND);
}
