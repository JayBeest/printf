/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 20:00:37 by jcorneli      #+#    #+#                 */
/*   Updated: 2020/11/26 20:55:03 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*getstr(long num, char *s)
{
	if (num < 0)
	{
		*s = '-';
		getstr(-num, s + 1);
		return (s);
	}
	else if (num / 10 != 0)
		s = getstr(num / 10, s);
	*s = num % 10 + '0';
	*(s + 1) = '\0';
	return (s + 1);
}

char		*ft_itoa(int n)
{
	long	num;
	char	temp[13];
	char	*a;

	a = "";
	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	getstr(num, temp);
	a = ft_strdup(temp);
	if (!a)
		return (NULL);
	return (a);
}
