/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoba.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 21:07:06 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/02/08 23:08:29 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*getstr(long long num, int base, int iscap, char *s)
{
	if (num < 0)
	{
		*s = '-';
		getstr(-num, base, iscap, s + 1);
		return (s);
	}
	else if (num / base != 0)
		s = getstr(num / base, base, iscap, s);
	if (num % base < 10)
		*s = num % base + '0';
	else if (iscap)
		*s = 'A' + num % base - 10;
	else
		*s = 'a' + num % base - 10;
	*(s + 1) = '\0';
	return (s + 1);
}

char	*ft_itoba(long long num, int base, int iscap)
{
	char	temp[100];
	char	*a;

	a = "";
	if (num == 0)
		return (ft_strdup("0"));
	if (base < 2 || base > 36)
		return (NULL);
	getstr(num, base, iscap, temp);
	a = ft_strdup(temp);
	if (!a)
		return (NULL);
	return (a);
}
