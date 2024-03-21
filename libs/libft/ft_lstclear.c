/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 12:11:27 by cter-maa      #+#    #+#                 */
/*   Updated: 2024/01/04 16:14:26 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* Deletes and frees the given node and every successor of that node.		  */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (lst && *lst)
	{
		current = *lst;
		while (current)
		{
			next = current->next;
			if (del)
				del(current->content);
			free(current);
			current = next;
		}
		*lst = NULL;
	}
}
