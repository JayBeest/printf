/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoba_nomalloc.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 21:07:06 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/02/08 23:08:29 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*getstr(long long num, int base, char *s)
{
	if (num < 0)
	{
		*s = '-';
		getstr(-num, base, s + 1);
		return (s);
	}
	else if (num / base != 0)
		s = getstr(num / base, base, s);
	if (num % base < 10)
		*s = num % base + '0';
	else
		*s = 'a' + num % base - 10;
	*(s + 1) = '\0';
	return (s + 1);
}

void	ft_itoba_nomalloc(long long num, int base, char *rs)
{
	if (base < 2 || base > 36)
		rs[0] = '\0';
	else if (num == 0)
	{
		rs[0] = '0';
		rs[1] = '\0';
	}
	else
		getstr(num, base, rs);
}
