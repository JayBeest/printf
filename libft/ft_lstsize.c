/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstssize.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 22:23:27 by jcorneli      #+#    #+#                 */
/*   Updated: 2020/11/26 16:42:04 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
