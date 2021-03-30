/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 09:29:21 by jcorneli      #+#    #+#                 */
/*   Updated: 2020/11/26 16:51:22 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!*little)
		return ((char *)big);
	while (*big && len > 0)
	{
		if (*big == *little)
		{
			i = 0;
			while (little[i])
			{
				if (little[i] != big[i])
					break ;
				else if (len - i <= 0)
					return (NULL);
				else if (little[i + 1] == '\0')
					return ((char *)big);
				i++;
			}
		}
		big++;
		len--;
	}
	return (NULL);
}
