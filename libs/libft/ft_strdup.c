/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 15:05:02 by cter-maa      #+#    #+#                 */
/*   Updated: 2024/01/04 16:12:08 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ft_strdup allocates sufficient memory for a copy of the string s1,		  */
/* and returns a pointer to it.												  */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	index;
	char	*new_string;

	index = 0;
	new_string = malloc (sizeof(char) * ft_strlen(s1) + 1);
	if (!new_string)
		return (NULL);
	while (s1[index])
	{
		new_string[index] = s1[index];
		index++;
	}
	new_string[index] = '\0';
	return (new_string);
	free (new_string);
}
