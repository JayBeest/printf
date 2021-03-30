/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 21:18:06 by jcorneli      #+#    #+#                 */
/*   Updated: 2020/11/26 16:40:05 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nod;

	nod = *lst;
	while (*lst)
	{
		nod = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nod;
	}
	lst = NULL;
}
