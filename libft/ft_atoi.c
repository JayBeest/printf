/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:42:27 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/02/18 12:18:50 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'\
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static long	checkflow(long long retv)
{
	if (retv > LLONG_MAX)
		retv = LLONG_MAX;
	else if (retv > LONG_MAX)
		retv = LONG_MAX;
	else if (retv < LLONG_MIN)
		retv = LLONG_MIN;
	else if (retv < LONG_MIN)
		retv = LONG_MIN;
	return (retv);
}

static char	*cleanstr(const char *ptr, int *multip)
{
	while (*ptr && isspace(*ptr))
		ptr++;
	if (*ptr == '-')
	{
		*multip *= -1;
		ptr++;
	}
	else if (*ptr == '+')
		ptr++;
	return ((char *)ptr);
}

int			ft_atoi(const char *ptr)
{
	int			multip;
	long long	retv;
	char		*str;

	retv = 0;
	multip = 1;
	if (!*ptr)
		return (0);
	str = cleanstr(ptr, &multip);
	if (!ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
	{
		if (retv == 0)
			retv = *str - 48;
		else
			retv = retv * 10 + (*str - 48);
		str++;
	}
	retv = checkflow(retv);
	return (retv * multip);
}
