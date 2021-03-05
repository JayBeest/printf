/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 11:03:49 by jcorneli      #+#    #+#                 */
/*   Updated: 2020/11/26 16:47:04 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	newstr = (char *)malloc(len_s1 + len_s2 + 1);
	if (newstr)
	{
		ft_memcpy(newstr, s1, len_s1);
		ft_memcpy(&newstr[len_s1], s2, len_s2 + 1);
		return (newstr);
	}
	return (NULL);
}
