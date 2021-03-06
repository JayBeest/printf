/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 00:51:10 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/01/09 19:22:32 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	mallen;
	char	*subs;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		mallen = 1;
	else if (slen - start >= len)
		mallen = len + 1;
	else
		mallen = slen - start + 1;
	subs = malloc(mallen);
	if (subs)
	{
		ft_strlcpy(subs, &s[start], mallen);
		subs[mallen - 1] = '\0';
	}
	return (subs);
}
