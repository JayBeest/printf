/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 21:02:45 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/01/09 19:01:54 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dstlen)
		return (size + srclen);
	while (size - dstlen - 1 > 0 && *src)
	{
		*(dst + dstlen) = *src;
		dst++;
		src++;
		size--;
	}
	*(dst + dstlen) = '\0';
	return (dstlen + srclen);
}
