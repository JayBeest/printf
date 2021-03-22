#include "ft_printf.h"

void 	check_flags(const char *s, t_pfs *pfs)
{
	int		i;

	i = 0;
	while (!ft_strchr(CONV_SPEC, s[i]))
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

void 	check_width(const char *format, t_pfs *pfs)
{
	int		i;

	i = 0;
	while (!ft_strchr(CONV_SPEC, format[i]))
	{
		if (format[i] == '*')
		{
			pfs->width = va_arg(pfs->ap, int);
			pfs->star_width = 1;
			i++;
			break ;
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

void	check_precision(const char *s, t_pfs *pfs)
{
	int	i;

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
