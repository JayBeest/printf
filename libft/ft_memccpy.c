/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 17:13:02 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/01/09 18:01:29 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*retdest;

	i = 0;
	retdest = (unsigned char *)dest;
	while (i < n)
	{
		retdest[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return (&retdest[i + 1]);
		i++;
	}
	return (NULL);
}
