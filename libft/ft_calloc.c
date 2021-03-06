/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 20:32:16 by jcorneli      #+#    #+#                 */
/*   Updated: 2020/11/26 16:27:47 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*retptr;

	if (nmemb != 0 && ((size_t)-1 / nmemb < size))
		return (NULL);
	if (nmemb * size > ((size_t)-1))
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	retptr = malloc(nmemb * size);
	if (retptr)
		ft_bzero(retptr, nmemb * size);
	return (retptr);
}
