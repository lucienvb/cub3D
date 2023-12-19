#include "../../include/cubed.h"

void	perror_exit(char *message)
{
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

int	cb_isnum(char a)
{
	if (a >= '0' && a <= '9')
		return(TRUE);
	return(FALSE);
}

int	cb_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\0');
}
int	cb_atoi(const char *str)
{
	int	index;
	int	result;

	index = 0;
	result = 0;
	while ((str[index] >= '0' && str[index] <= '9') && str[index] && (index <= 3))
	{
		result = result * 10;
		result = (result + (str[index] - '0'));
		index++;
	}
	if (result > 255)
	{
		perror("collor code incorrect");
		exit(EXIT_FAILURE);
	}
	return (result);
}
