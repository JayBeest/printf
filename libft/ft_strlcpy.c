/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:12:37 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/01/09 19:01:36 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;

	if (src == NULL)
		return (0);
	srclen = ft_strlen(src);
	if (size >= srclen + 1)
		ft_memcpy(dst, src, srclen + 1);
	else if (size > 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (srclen);
}
