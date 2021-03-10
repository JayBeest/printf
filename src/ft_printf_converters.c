#include "ft_printf.h"
#include <stdlib.h>

#include <stdio.h>

char	*convert_s(t_pfs *pfs)
{
	char	*temp;
	char	*rs;
	char	*nulltemp;

	nulltemp = "(null)";
	temp = va_arg(pfs->ap, char *);
	if (!temp)
		temp = nulltemp;
	pfs->vallen = ft_strlen(temp);
	if (pfs->precision >= 0 && pfs->vallen)
		pfs->vallen = pfs->precision;
	rs = make_field(pfs);
	if (pfs->min_flag)
		ft_memcpy(rs, temp, pfs->vallen);
	else
		ft_memcpy(rs + pfs->count - pfs->vallen, temp, pfs->vallen);
	return (rs);
}

char	*convert_c(t_pfs *pfs)
{
	char c;
	char *rs;

	c = va_arg(pfs->ap, int);
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
	char 	temprs[20];
	size_t	num;

	num = va_arg(pfs->ap, unsigned);
	ft_itoba_nomalloc(num, 16, temprs);
	if (pfs->spec == 'X')
		ft_strtoupper(temprs);
	pfs->vallen = ft_strlen(temprs);
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

char	*convert_p(t_pfs *pfs)
{
	char	*rs;
	char 	temprs[20];
	size_t	num;

	num = va_arg(pfs->ap, unsigned long);
	//printf("CHECK num value: %zu\n", num);
	ft_itoba_nomalloc(num, 16, temprs);
	pfs->vallen = ft_strlen(temprs);
	rs = make_field(pfs);
	if (!rs)
		return (NULL);
	if (pfs->min_flag && pfs->width > pfs->vallen + 2)
	{
		ft_memset(rs + 2, '0', pfs->width - pfs->vallen);
		ft_memcpy(rs + 2 + pfs->count - pfs->vallen, temprs, pfs->vallen);
	}
	else if (pfs->width > pfs->vallen + 2)
	{
		ft_memset(rs  + pfs->count - pfs->vallen, '0', pfs->vallen);
		ft_memcpy(rs  + pfs->count - pfs->vallen, temprs, pfs->vallen);
	}
	else
		ft_memcpy(rs + 2, temprs, pfs->vallen);

	return (rs);
}

char	*convert_i(t_pfs *pfs)
{

}

char	*convert_u(t_pfs *pfs)
{

}
