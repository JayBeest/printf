#include "ft_printf.h"

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
	if (pfs->precision >= 0 && pfs->vallen && pfs->vallen >= pfs->precision)
		pfs->vallen = pfs->precision;
	rs = make_field(pfs);
	if (pfs->min_flag)
		ft_memcpy(rs, temp, pfs->vallen);
	else
		ft_memcpy(rs + pfs->count - pfs->vallen, temp, pfs->vallen);
	return (rs);
}
