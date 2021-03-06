/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 23:41:10 by jcorneli      #+#    #+#                 */
/*   Updated: 2020/11/26 16:39:22 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nod;

	nod = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		nod = ft_lstlast(*lst);
		nod->next = new;
	}
}
