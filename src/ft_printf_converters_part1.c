#include "ft_printf.h"

char	*convert_c(t_pfs *pfs)
{
	char	c;
	char	*rs;

	if (pfs->spec != '%')
		c = va_arg(pfs->ap, int);
	else
		c = '%';
	pfs->vallen = 1;
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
	char	temprs[20];
	size_t	num;

	num = va_arg(pfs->ap, unsigned);
	ft_itoba_nomalloc(num, 16, temprs);
	if (pfs->spec == 'X')
		ft_strtoupper(temprs);
	pfs->vallen = ft_strlen(temprs);
	rs = make_field(pfs);
	if (!rs)
		return (NULL);
	if (pfs->precision == 0 && pfs->width < 1 && num == 0)
		pfs->count = 0;
	if (pfs->min_flag)
		paste_min_flag(pfs, rs, temprs);
	else
		paste_nomin_flag(pfs, rs, temprs);
	return (rs);
}

char	*convert_p(t_pfs *pfs)
{
	char	*rs;
	char	temprs[20];
	size_t	num;

	pfs->precision = -1;
	num = va_arg(pfs->ap, unsigned long);
	ft_itoba_nomalloc(num, 16, temprs);
	pfs->vallen = ft_strlen(temprs);
	rs = make_field(pfs);
	if (!rs)
		return (NULL);
	if (pfs->min_flag && pfs->width > pfs->vallen + 2)
	{
		ft_memset(rs + 2, ' ', pfs->width - pfs->vallen);
		ft_memcpy(rs + 2, temprs, pfs->vallen);
	}
	else if (pfs->width > pfs->vallen + 2)
	{
		ft_memset(rs + pfs->count - pfs->vallen, ' ', pfs->vallen);
		ft_memcpy(rs + pfs->count - pfs->vallen, temprs, pfs->vallen);
	}
	else
		ft_memcpy(rs + 2, temprs, pfs->vallen);
	return (rs);
}

char	*convert_i(t_pfs *pfs)
{
	char	*rs;
	char	temprs[30];
	long	num;

	if (pfs->zero_flag && pfs->min_flag)
		pfs->zero_flag = 0;
	num = va_arg(pfs->ap, long);
	if (num < 0)
	{
		pfs->isneg = 1;
		num *= -1;
	}
	ft_itoba_nomalloc(num, 10, temprs);
	pfs->vallen = ft_strlen(temprs);
	rs = make_field(pfs);
	if (!rs)
		return (NULL);
	if (pfs->precision == 0 && pfs->width < 1 && num == 0)
		pfs->count = 0;
	if (pfs->min_flag)
		paste_min_flag(pfs, rs, temprs);
	else
		paste_nomin_flag(pfs, rs, temprs);
	return (rs);
}

char	*convert_u(t_pfs *pfs)
{
	char	*rs;
	char	temprs[30];
	size_t	num;

	num = va_arg(pfs->ap, unsigned);
	ft_itoba_nomalloc(num, 10, temprs);
	pfs->vallen = ft_strlen(temprs);
	rs = make_field(pfs);
	if (!rs)
		return (NULL);
	if (pfs->precision == 0 && pfs->width < 1 && num == 0)
		pfs->count = 0;
	if (pfs->min_flag)
		paste_min_flag(pfs, rs, temprs);
	else
		paste_nomin_flag(pfs, rs, temprs);
	return (rs);
}
