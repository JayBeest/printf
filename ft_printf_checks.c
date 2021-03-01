# include "ft_printf.h"

#include <stdio.h>

static int 	check_flags(const char *s, t_pfs *pfs)
{
	int		i;

	i = 0;
	while (!ft_strchr("scpdiuxX", s[i]))
	{
		if (s[i] == '-')
		{
			pfs->min_flag = 1;
			pfs->zero_flag = 0;
		}
		else if (s[i] == '+')
			pfs->plus_flag = 1;
		else if (s[i] == '0' && !pfs->min_flag)
			pfs->zero_flag = 1;
		else
			break ;
		i++;
	}
//	printf("check_flags return i: %d\n", i);
	pfs->nest_i += i;
	return (i);
}

static int 	check_width(const char *format, t_pfs *pfs)
{
	int		i;

	i = 0;
	while (!ft_strchr("scpdiuxX", format[i]))
	{
		if (format[i] == '*')
		{
			pfs->width = va_arg(pfs->ap, int);
			i++;
			break;
		}
		else if (ft_isdigit(*format))
		{
			while (ft_isdigit(format[i]))
				i++;
			pfs->width = ft_atoi((char *)format);
			break ;
		}
		else
			break ;
	}
//	printf("check_width return i: %d\n", i);
	pfs->nest_i += i;
	return (i);
}

static int 	check_precision(const char *s, t_pfs *pfs)
{
	int i;

	i = 0;
	if (*s == '.')
	{
		pfs->precision = 0;
		pfs->nest_i++;
		if (ft_isdigit(*(s + 1)))
		{
			while (ft_isdigit(*(s + 1 + i)))
			{
				pfs->nest_i++;
				i++;
			}
			pfs->precision = ft_atoi(s + 1);
		}
		else if (*(s + 1) == '*')
		{
			pfs->precision = va_arg(pfs->ap, int);
			pfs->nest_i++;
		}
	}
	return (1);
}

static void 	check_spec(const char *format, t_pfs *pfs, t_convspec *funptr)
{
	if (ft_strchr("sciupdxX", *format))
	{
		pfs->spec = *format;
		if (*format == 's')
			*funptr = &convert_s;
		else if (*format == 'c')
			*funptr = &convert_c;
		else if (*format == 'p')
			*funptr = &convert_p;
		else if (*format == 'x' || *format == 'X')
			*funptr = &convert_x;
		else if (*format == 'd' || *format == 'i')
			*funptr = &convert_i;
		else if (*format == 'u')
			*funptr = &convert_u;
		pfs->nest_i++;
	}
}

long 	printf_parser(const char *format, t_pfs *pfs)
{
	t_convspec	funptr;
	int 		rv;

	pfs = init_pfs(pfs, 1);
	if (!pfs)
		return (-1);
	rv = check_flags(format + pfs->nest_i, pfs);
	if (rv >= 0)
		rv = check_width(format + pfs->nest_i, pfs);
	else
		return (-1);
	if (rv >= 0)
		rv = check_precision(format + pfs->nest_i, pfs);
	if (rv >= 0)
		check_spec(format + pfs->nest_i, pfs, &funptr);
	else
		{
		printf("okdan error\n");
		return (-1);
	}
	printf_converter(pfs, funptr);
//	printf("returnvalue parser nest_i: %d\n", pfs->nest_i);
	return (pfs->nest_i);
}

