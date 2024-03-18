/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_texture.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: chaverttermaat <chaverttermaat@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 10:29:42 by chavertterm   #+#    #+#                 */
/*   Updated: 2024/03/18 11:01:28 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static char	*remove_spaces_from_line(char *line)
{
	char	*path;
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (cb_isspace(line[start]) == FOUND && line[start])
		start++;
	end = start;
	while (cb_isspace(line[end]) == NOT_FOUND && line[end])
		end++;
	path = cd_strndup(&line[start], end - 1);
	return (path);
}

static int	save_texture_to_struct(t_cubed *cubed, char *line, char *path)
{
	if (ft_strncmp(line, "NO ", 3) == FOUND)
	{
		cubed->n_texture = mlx_load_png(path);
		if (cubed->n_texture == NULL)
			return (FAILED);
	}
	else if (ft_strncmp(line, "EA ", 3) == FOUND)
	{
		cubed->e_texture = mlx_load_png(path);
		if (cubed->e_texture == NULL)
			return (FAILED);
	}
	else if (ft_strncmp(line, "SO ", 3) == FOUND)
	{
		cubed->s_texture = mlx_load_png(path);
		if (cubed->s_texture == NULL)
			return (FAILED);
	}
	else if (ft_strncmp(line, "WE ", 3) == FOUND)
	{
		cubed->w_texture = mlx_load_png(path);
		if (cubed->w_texture == NULL)
			return (FAILED);
	}
	return (SUCCESS);
}

static int	count_textures(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == FOUND)
		return (FOUND);
	else if (ft_strncmp(line, "EA ", 3) == FOUND)
		return (FOUND);
	else if (ft_strncmp(line, "SO ", 3) == FOUND)
		return (FOUND);
	else if (ft_strncmp(line, "WE ", 3) == FOUND)
		return (FOUND);
	return (NOT_FOUND);
}

static int	get_texture(t_cubed *cubed, char *line)
{
	char	*path;

	path = remove_spaces_from_line(&line[2]);
	if (!path)
	{
		free(path);
		return (FAILED);
	}
	if (count_textures(line) == NOT_FOUND)
	{
		free (path);
		return (FAILED);
	}
	if (save_texture_to_struct(cubed, line, path) == FAILED)
	{
		free (path);
		return (FAILED);
	}
	free (path);
	return (SUCCESS);
}

int	parse_texture(t_cubed *cubed)
{
	int	i;
	int	j;
	int	total_found;

	total_found = 0;
	i = 0;
	while (cubed->file[i])
	{
		j = 0;
		while (cb_isspace(cubed->file[i][j]) == FOUND && cubed->file[i][j])
			j++;
		if (get_texture(cubed, &cubed->file[i][j]) == SUCCESS)
			total_found += 1;
		i++;
	}
	if (total_found != 4)
	{
		ft_printf("Error:\nIncorrect path(s)\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
