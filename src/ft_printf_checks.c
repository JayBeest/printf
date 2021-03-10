# include "ft_printf.h"

static void 	check_flags(const char *s, t_pfs *pfs)
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
	pfs->nest_i += i;
}

static void 	check_width(const char *format, t_pfs *pfs)
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
	pfs->nest_i += i;
}

static void 	check_precision(const char *s, t_pfs *pfs)
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
}

//static void 	check_spec(const char *format, t_pfs *pfs)
//{
//	if (ft_strchr("sciupdxX", *format))
//	{
//		pfs->spec = *format;
//		if (*format == 's')
//			*funptr = &convert_s;
//		else if (*format == 'c')
//			*funptr = &convert_c;
//		else if (*format == 'p')
//			*funptr = &convert_p;
//		else if (*format == 'x' || *format == 'X')
//			*funptr = &convert_x;
//		else if (*format == 'd' || *format == 'i')
//			*funptr = &convert_i;
//		else if (*format == 'u')
//			*funptr = &convert_u;
//		pfs->nest_i++;
//	}
//}

long 	printf_parser(const char *format, t_pfs *pfs)
{
	pfs = init_pfs(pfs, 1);
	if (!pfs)
		return (-1);
	check_flags(format + pfs->nest_i, pfs);
	check_width(format + pfs->nest_i, pfs);
    check_precision(format + pfs->nest_i, pfs);
    if (ft_strchr("sciupdxX", *(format + pfs->nest_i)))
        pfs->spec = *(format + pfs->nest_i);
    else
        return (-1);
    pfs->nest_i++;
	printf_converter(pfs);
	return (pfs->nest_i);
}

