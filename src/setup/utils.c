#include "../../include/cubed.h"

int	cb_isnum(char a)
{
	if (a >= '0' && a <= '9')
		return(TRUE);
	return(FALSE);
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
