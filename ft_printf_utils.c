#include "ft_printf.h"
#include <stdlib.h>

char 	*make_field(t_pfs *pfs, int specsize)
{
	char *rs;

	if (pfs->width > specsize)
		pfs->count = pfs->width;
	else
		pfs->count = specsize;
	rs = (char *)malloc(pfs->count);
	if (!rs)
		return (NULL);
	if (pfs->zero_flag)
		ft_memset(rs, '0', pfs->count);
	else
		ft_memset(rs, ' ', pfs->count);
	return (rs);
}

int 			add_zeros(t_pfs *pfs, char **rs, long len, long zeros)
{
	char	*ptr;
	char 	*newrs;

	ptr = *rs;
	newrs = (char *)malloc(len + zeros);
	if (!newrs)
		return (NULL);
	while (zeros > 0)
	{

	}

}