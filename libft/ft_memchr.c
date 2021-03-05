/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 15:21:38 by jcorneli      #+#    #+#                 */
/*   Updated: 2020/11/26 22:25:16 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*rets;

	i = 0;
	rets = (unsigned char *)s;
	while (i < n)
	{
		if (rets[i] == (unsigned char)c)
			return (&rets[i]);
		i++;
	}
	return (NULL);
}
