/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_free.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 14:54:35 by cter-maa      #+#    #+#                 */
/*   Updated: 2024/03/13 15:00:25 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

void	free_2d_array(char **array)
{
	int	index;

	index = 0;
	if (!array)
		return ;
	while (array[index])
	{
		free(array[index]);
		array[index] = NULL;
		index++;
	}
	free(array);
}

void	free_allocations(t_cubed *cubed)
{
	free_2d_array(cubed->file);
	free_2d_array(cubed->map);
	free_2d_array(cubed->map_val);
	close(cubed->fd);
}

void	error_exit(char *message)
{
	ft_printf("Error:\n");
	ft_printf("%s \n", message);
	exit(EXIT_FAILURE);
}

void	perror_exit(char *message)
{
	ft_printf("Error: \n");
	perror(message);
	exit(EXIT_FAILURE);
}
