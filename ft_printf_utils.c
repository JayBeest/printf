#include "ft_printf.h"
#include <stdlib.h>

char 	*make_field(t_pfs *pfs)
{
	char *rs;

	rs = (char *)malloc(pfs->count);
	if (!rs)
		return (NULL);
	if (pfs->zero_flag)
		ft_memset(rs, '0', pfs->count);
	else
		ft_memset(rs, ' ', pfs->count);
	return (rs);
}

long 			add_zeros(t_pfs *pfs, char **rs, long zeros)
{
	char 	newrs[pfs->count];

	ft_memset(newrs, '0', zeros);
	ft_memcpy(newrs + zeros, *rs, pfs->vallen);
	*rs = newrs;
	pfs->vallen += zeros;
	return (zeros);
}