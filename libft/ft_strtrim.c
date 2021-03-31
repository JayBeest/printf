/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 17:30:09 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/01/09 19:13:51 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	inset(const char *set, int c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static const char	*get_begin(char const *s, char const *set)
{
	while (*s)
	{
		if (inset(set, *s))
			s++;
		else
			break ;
	}
	return (s);
}

static int	get_endlen(char const *s, char const *set, const size_t len)
{
	int		i;
	size_t	index;

	i = 0;
	index = len;
	while (index != 0)
	{
		if (inset(set, s[index - 1]))
		{
			index--;
			i++;
		}
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t		len;
	char		*str;

	if (!s)
		return (NULL);
	if (!set)
		return (ft_strdup(s));
	s = get_begin(s, set);
	if (!*s)
		return (ft_strdup(""));
	len = ft_strlen(s);
	len -= get_endlen(s, set, len);
	str = malloc(len + 1);
	if (str)
	{
		ft_memcpy(str, s, len);
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
