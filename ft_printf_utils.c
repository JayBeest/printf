#include "ft_printf.h"
#include <stdlib.h>

char 	*make_field(t_pfs *pfs)
{
	char *rs;

	pfs->count = pfs->vallen;
	if (pfs->precision > pfs->vallen)
	{
		pfs->count = pfs->precision;
	}
	if (pfs->width > pfs->count)
		pfs->count = pfs->width;
	if (pfs->spec == 'p' && pfs->width < pfs->vallen + 1)
		pfs->count += 2;
//	if (pfs->spec == 'p')
//	{
//		if (pfs->precision > 1)
//			pfs->precision += 2;
//		pfs->count += 2;
//	}
	rs = (char *)malloc(pfs->count);
	if (!rs)
		return (NULL);
	if (pfs->zero_flag)  //|| pfs->precision > pfs->vallen
			ft_memset(rs, '0', pfs->count);
	else
			ft_memset(rs, ' ', pfs->count);
	if (pfs->spec == 'p' && pfs->min_flag)
		add_pointer(rs);
	else if (pfs->spec == 'p')
		add_pointer(rs + pfs->count - pfs->vallen - 2);
	return (rs);
}

void 	add_pointer(char *rs)
{
	rs[0] = '0';
	rs[1] = 'x';
}
