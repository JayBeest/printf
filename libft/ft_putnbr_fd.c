/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 18:10:15 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/01/09 18:19:53 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static char		*getstr(long num, char *s)
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

void			ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	temp[13];

	num = n;
	if (n == 0)
	{
		temp[0] = '0';
		temp[1] = '\0';
	}
	else
		getstr(num, temp);
	write(fd, temp, ft_strlen(temp));
}
