#include "ft_printf.h"
#include <stdlib.h>

#include <stdio.h>

char	*convert_s(t_pfs *pfs)
{
	char	temp;
	char	*rs;
	int		len;

	temp = va_arg(pfs->ap, char *);
	len = ft_strlen(temp);
	if (pfs->precision >= 0)
		len = pfs->precision;
	rs = make_field(pfs, len);
	if (!rs)
		return (NULL);
	if (pfs->min_flag == 1)
		ft_memcpy(rs, temp, len);
	else
		ft_memcpy(rs + pfs->count - len, temp, len);
	return (rs);
}

char	*convert_c(t_pfs *pfs)
{
	char c;
	char *rs;

	c = va_arg(pfs->ap, int);
	rs = make_field(pfs, 1);
	if (!rs)
		return (NULL);
	if (pfs->min_flag == 1)
		ft_memset(rs, c, 1);
	else
		ft_memset(rs + pfs->count - 1, c, 1);
	return (rs);
}

char	*convert_x(t_pfs *pfs)
{
	char	*rs;
	char 	temprs[20];
	size_t	num;
	long	len;

	num = va_arg(pfs->ap, unsigned);
	ft_itoba_nomalloc(num, 16, temprs);
	if (pfs->spec == 'x')
		ft_strtolower(temprs);
	len = ft_strlen(temprs);
	if (pfs->precision > len)
	{
		add_zeros(pfs, &temprs, len, pfs->precision - len))
		make_field(pfs, pfs->precision);
	}
	else
	{
		pfs->count += len;
		make_field(pfs, len);
	}
}

char	*convert_i(t_pfs *pfs)
{

}

char	*convert_u(t_pfs *pfs)
{

}