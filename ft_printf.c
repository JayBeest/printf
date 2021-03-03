/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 16:25:25 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/02/10 14:24:38 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>
#include <stdlib.h>

t_pfs *init_pfs(t_pfs *pfs, int reset)
{
	if (!reset)
		pfs = (t_pfs *) malloc(sizeof(t_pfs));
	if (pfs)
	{
		pfs->count = 0;
		pfs->nest_i = 0;
		pfs->vallen = 0;
		pfs->min_flag = 0;
		pfs->plus_flag = 0;
		pfs->zero_flag = 0;
		pfs->precision = -1;
		pfs->width = -1;
		return (pfs);
	}
	return (NULL);
}

static int	write_count(const char *s, t_pfs *pfs)
{
	int	i;
	int	nest_i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] == '%')
		{
			ft_putchar_fd('%', 1);
			count++;
			i++;
		}
		else if (s[i] == '%')
		{
			nest_i = printf_parser(s + i + 1, pfs);
			if (nest_i == -1)
				return (-1);
			i += nest_i;
			count += pfs->count;
		}
		else
		{
			write(1, &s[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int		printf_converter(t_pfs *pfs)
{
    static const t_convspec	funptr[255] = {
            ['s'] = &convert_s,
            ['c'] = &convert_c,
            ['i'] = &convert_i,
            ['u'] = &convert_u,
            ['p'] = &convert_p,
            ['d'] = &convert_i,
            ['x'] = &convert_x,
            ['X'] = &convert_x
    };
	char *converted;

	converted = funptr[pfs->spec](pfs);
	if (!converted)
		return (-1);
	write(1, converted, pfs->count);
	free(converted);
	return (0);
}

int 	ft_printf(const char *format, ...)
{
	t_pfs		*pfs;
	int			rv;

	pfs = init_pfs(pfs, 0);
	if (!pfs)
		return (-1);
	va_start(pfs->ap, format);
	rv = write_count(format, pfs);
	va_end(pfs->ap);
	free(pfs);
	return (rv);
}
