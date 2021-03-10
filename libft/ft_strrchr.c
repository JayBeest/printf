/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 09:18:50 by jcorneli      #+#    #+#                 */
/*   Updated: 2020/11/26 16:51:39 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*retdst;

	retdst = 0;
	while (1)
	{
		if (*s == c)
			retdst = (char *)s;
		if (!*s)
			break ;
		s++;
	}
	return (retdst);
}
