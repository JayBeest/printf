#include "ft_printf.h"
#include <stdlib.h>

char 	*make_field(t_pfs *pfs)
{
	char *rs;

	if (pfs->precision > pfs->vallen)
		pfs->count = pfs->precision;
	if (pfs->width > pfs->count)
		pfs->count = pfs->width;
	rs = (char *)malloc(pfs->count);
	if (!rs)
		return (NULL);
	if (pfs->zero_flag)  //|| pfs->precision > pfs->vallen
			ft_memset(rs, '0', pfs->count);
	else
			ft_memset(rs, ' ', pfs->count);
	return (rs);
}