/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 23:33:11 by jcorneli      #+#    #+#                 */
/*   Updated: 2020/11/26 16:43:56 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*retdest;

	retdest = (unsigned char *)dest;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			retdest[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			retdest[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	return (dest);
}
