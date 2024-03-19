/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_free.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 09:58:40 by chavertterm   #+#    #+#                 */
/*   Updated: 2024/03/19 15:15:33 by cter-maa      ########   odam.nl         */
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
	free_png(cubed);
}

void	error_exit(char *message)
{
	ft_printf("%s", message);
	exit(EXIT_FAILURE);
}

void	perror_exit(char *message)
{
	ft_printf("Error: \n");
	perror(message);
	exit(EXIT_FAILURE);
}

void	free_png(t_cubed *cubed)
{
	if (cubed->n_texture != NULL)
		mlx_delete_texture(cubed->n_texture);
	if (cubed->e_texture != NULL)
		mlx_delete_texture(cubed->e_texture);
	if (cubed->s_texture != NULL)
		mlx_delete_texture(cubed->s_texture);
	if (cubed->w_texture != NULL)
		mlx_delete_texture(cubed->w_texture);
}
