#include "ft_printf.h"
#include <stdlib.h>

void 	add_pointer(char *rs)
{
	rs[0] = '0';
	rs[1] = 'x';
}

void 	set_field_precision(t_pfs *pfs)
{
	if (pfs->precision > pfs->vallen && pfs->width <= pfs->precision && !pfs->min_flag)
	{
		pfs->width = pfs->precision;
		pfs->zero_flag = 1;
	}
	if (pfs->spec == 'p')
		pfs->precision = -1;
}

char 	*make_field(t_pfs *pfs)
{
	char *rs;

	if (pfs->spec != 's' && pfs->spec != 'p')
		set_field_precision(pfs);
	pfs->count = pfs->vallen;
	if (pfs->precision > pfs->vallen && pfs->vallen)
		pfs->count = pfs->precision;
	if (pfs->width > pfs->count)
		pfs->count = pfs->width;
	if (pfs->spec == 'p' && pfs->width < pfs->vallen + 1)
		pfs->count += 2;
	rs = (char *)malloc(pfs->count);
	if (!rs)
		return (NULL);
	if (pfs->zero_flag)
		ft_memset(rs, '0', pfs->count);
	else
		ft_memset(rs, ' ', pfs->count);
	if (pfs->spec == 'p' && pfs->min_flag)
		add_pointer(rs);
	else if (pfs->spec == 'p')
		add_pointer(rs + pfs->count - pfs->vallen - 2);
	return (rs);
}

void	paste_min_flag(t_pfs *pfs, char *rs, char *temprs)
{
	if (pfs->precision > pfs->vallen)
	{
		ft_memset(rs, '0', pfs->precision - pfs->vallen);
		ft_memcpy(rs + pfs->precision - pfs->vallen, temprs, pfs->vallen);
	}
//	else if (pfs->precision > pfs->vallen)
//	{
//		ft_memset(rs + pfs->count - pfs->precision, '0', pfs->precision - pfs->vallen);
//		ft_memcpy(rs + pfs->count - pfs->vallen, temprs, pfs->vallen);
//	}
	else
		ft_memcpy(rs, temprs, pfs->vallen);
}

void	paste_nomin_flag(t_pfs *pfs, char *rs, char *temprs)
{
	if (pfs->precision > pfs->vallen)
	{
		ft_memset(rs + pfs->count - pfs->precision, '0', pfs->precision - pfs->vallen);
		ft_memcpy(rs + pfs->count - pfs->vallen, temprs, pfs->vallen);
	}
	else
		ft_memcpy(rs + pfs->count - pfs->vallen, temprs, pfs->vallen);
}
