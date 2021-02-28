#include "ft_printf.h"
#include <stdlib.h>

#include <stdio.h>

char	*convert_s(t_pfs *pfs)
{
	char	*temp;
	char	*rs;
	int		len;

	temp = va_arg(pfs->ap, char *);
	len = ft_strlen(temp);
	if (pfs->precision >= 0)
		len = pfs->precision;
	pfs->count = len;
	if (pfs->width > pfs->count)
		pfs->count = pfs->width;
	rs = make_field(pfs);
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
	pfs->count = 1;
	if (pfs->width > 1)
		pfs->count = pfs->width;
	rs = make_field(pfs);
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

	num = va_arg(pfs->ap, unsigned);
	ft_itoba_nomalloc(num, 16, temprs);
	pfs->vallen = ft_strlen(temprs);
	if (pfs->spec == 'x')
		ft_strtolower(temprs);
	pfs->count = pfs->vallen;
	rs = make_field(pfs);
	if (!rs)
		return (NULL);
	if (pfs->min_flag && pfs->precision > pfs->vallen)
	{
		ft_memset(rs, '0', pfs->precision - pfs->vallen);
		ft_memcpy(rs + pfs->precision - pfs->vallen, temprs, pfs->vallen);
	}
	else if (pfs->precision > pfs->vallen)
	{
		ft_memset(rs + pfs->count - pfs->precision, '0', pfs->precision - pfs->vallen);
		ft_memcpy(rs + pfs->count - pfs->vallen, temprs, pfs->vallen);
	}
	else
		ft_memcpy(rs, temprs, pfs->vallen);
	return (rs);
}

char	*convert_i(t_pfs *pfs)
{

}

char	*convert_u(t_pfs *pfs)
{

}