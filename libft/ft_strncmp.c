/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 14:13:40 by jcorneli      #+#    #+#                 */
/*   Updated: 2020/11/26 16:51:01 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

signed int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		else if (s1[i] == 0)
			break ;
		i++;
	}
	return (0);
}
