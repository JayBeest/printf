/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 22:48:49 by jcorneli      #+#    #+#                 */
/*   Updated: 2020/11/26 17:00:42 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*retstr;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	retstr = ft_strdup(s);
	if (retstr)
	{
		while (retstr[i])
		{
			retstr[i] = f(i, s[i]);
			i++;
		}
		return (retstr);
	}
	return (NULL);
}
