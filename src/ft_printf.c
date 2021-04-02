/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 16:25:25 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/03/31 21:53:20 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>
#include <stdlib.h>

t_pfs	*init_pfs(t_pfs *pfs, int reset)
{
	if (!reset)
		pfs = (t_pfs *) malloc(sizeof(t_pfs));
	if (pfs)
	{
		pfs->precision = -1;
		pfs->width = -1;
		ft_bzero(&pfs->spec, 29);
		return (pfs);
	}
	return (NULL);
}

int	printf_converter(t_pfs *pfs)
{
	static const t_convspec	funptr[94] = {
			['s' - 32] = &convert_s,
			['c' - 32] = convert_c,
			['%' - 32] = &convert_c,
			['i' - 32] = convert_i,
			['u' - 32] = &convert_u,
			['p' - 32] = convert_p,
			['d' - 32] = &convert_i,
			['x' - 32] = convert_x,
			['X' - 32] = &convert_x
	};
	char					*converted;

	converted = funptr[(int)pfs->spec - 32](pfs);
	if (!converted)
		return (0);
	write(1, converted, pfs->count);
	free(converted);
	return (1);
}

int	printf_parser(const char *format, t_pfs *pfs)
{
	pfs = init_pfs(pfs, 1);
	if (!pfs)
		return (-1);
	check_flags(format + pfs->nest_i, pfs);
	check_width(format + pfs->nest_i, pfs);
	if (pfs->star_width && pfs->width < 0)
	{
		pfs->width *= -1;
		pfs->min_flag = 1;
	}
	check_precision(format + pfs->nest_i, pfs);
	if (ft_strchr(CONV_SPEC, *(format + pfs->nest_i)))
		pfs->spec = *(format + pfs->nest_i);
	else
		return (-1);
	pfs->nest_i++;
	if (printf_converter(pfs))
		return (pfs->nest_i);
	return (-1);
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
		if (s[i] == '%')
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

int 	ft_printf(const char *format, ...)
{
	t_pfs		*pfs;
	int			rv;

	pfs = NULL;
	pfs = init_pfs(pfs, 0);
	if (!pfs || !format)
		return (-1);
	va_start(pfs->ap, format);
	rv = write_count(format, pfs);
	va_end(pfs->ap);
	free(pfs);
	return (rv);
}
