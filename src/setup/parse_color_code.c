#include "../../include/cubed.h"

int	cb_isnum(char a)
{
	if (a >= '0' && a <= '9')
		return(TRUE);
	return(FALSE);
}

int cb_atoi(const char *str)
{
    int i;
    int result;

    i = 0;
    result = 0;
    while (cb_isnum(str[i]) == TRUE && str[i] && (i < 3))
    {
        result = result * 10;
        result = (result + (str[i] - '0'));
        i++;
    }
    if (result > 255)
    {
        perror("color code incorrect");
        exit(EXIT_FAILURE);
    }
    return (result);
}

int get_color(t_cubed *cubed, char *line, char idf)
{
    int i = 0;
    int j = 0;
    if (line[i] == idf)
    {
        while (line[i])
        {
            while (cb_isnum(line[i]) == FALSE)
                i++;
            if (idf == 'C')
                cubed->ceiling_color[j] = cb_atoi(&line[i]);
            else if (idf == 'F')
                cubed->floor_color[j] = cb_atoi(&line[i]);
   			if (j == 2)
        		return (FOUND);
            j++;
            while (cb_isnum(line[i]) == TRUE)
                i++;
        }
    }
    return (NOT_FOUND);
}

int	parse_color_code(t_cubed *cubed)
{
	int	i;
	int	total_found;
	int j;

	i = 0;
	total_found = 0;
	while (cubed->file[i])
	{
		j = 0;
		while(cb_isspace(cubed->file[i][j]) == FALSE)
			j++;
		if (get_color(cubed, &cubed->file[i][j], 'C') == FOUND)
			total_found++;
		else if (get_color(cubed, &cubed->file[i][j], 'F') == FOUND)
			total_found++;
		i++;
	}
	if (total_found != 2)
	{
		ft_printf("color code(s) incorrect");
		return (FAILURE);
	}
	return (SUCCESS);
}
