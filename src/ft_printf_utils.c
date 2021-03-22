/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 16:25:25 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/03/22 22:43:04 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void 	add_pointer(char *rs, t_pfs *pfs)
{
	if (pfs->min_flag)
	{
		rs[0] = '0';
		rs[1] = 'x';
	}
	else
	{
		rs[pfs->count - pfs->vallen - 2] = '0';
		rs[pfs->count - pfs->vallen - 1] = 'x';
	}
}

void 	add_pointer_space(t_pfs *pfs)
{
	int		space;

	if (pfs->vallen == 0)
		pfs->vallen = 1;
	space = pfs->width - pfs->vallen;
	if (space > 0 && space < 3)
		pfs->count += space;
	space = pfs->width - pfs->vallen;
	if (pfs->width < pfs->vallen && space == 1)
		pfs->count++;
	else if (space < 1)
		pfs->count += 2;
}

char 	*make_field(t_pfs *pfs)
{
	char	*rs;

	pfs->count = pfs->vallen;
	if (pfs->precision > pfs->vallen && pfs->vallen && pfs->spec != 's')
		pfs->count = pfs->precision;
	if (pfs->width > pfs->count)
		pfs->count = pfs->width;
	if (pfs->spec == 'p')
		add_pointer_space(pfs);
	if (pfs->precision > -1 && pfs->spec != 's')
		pfs->zero_flag = 0;
	if (pfs->isneg && pfs->width <= pfs->vallen)
		pfs->count++;
	rs = (char *)malloc(pfs->count);
	if (!rs)
		return (NULL);
	if (pfs->zero_flag)
		ft_memset(rs, '0', pfs->count);
	else
		ft_memset(rs, ' ', pfs->count);
	if (pfs->spec == 'p')
		add_pointer(rs, pfs);
	return (rs);
}

void	paste_min_flag(t_pfs *pfs, char *rs, char *temprs)
{
	if (pfs->precision == 0 && *temprs == '0')
		*temprs = ' ';
	if (pfs->isneg)
	{
		*rs = '-';
		if (pfs->precision > pfs->vallen)
		{
			ft_memset(rs + 1, '0', pfs->precision - pfs->vallen);
			ft_memcpy(rs + pfs->precision - pfs->vallen + 1, temprs,
				pfs->vallen);
		}
		else
			ft_memcpy(rs + 1, temprs, pfs->vallen);
	}
	else
	{
		if (pfs->precision > pfs->vallen)
		{
			ft_memset(rs, '0', pfs->precision - pfs->vallen);
			ft_memcpy(rs + pfs->precision - pfs->vallen, temprs, pfs->vallen);
		}
		else
			ft_memcpy(rs, temprs, pfs->vallen);
	}
}

void	paste_nomin_flag(t_pfs *pfs, char *rs, char *temprs)
{
	if (pfs->precision == 0 && *temprs == '0')
		*temprs = ' ';
	if (pfs->isneg)
	{
		if (pfs->precision > pfs->vallen)
			*(rs + pfs->count - pfs->precision - 1) = '-';
		else if (pfs->width > pfs->vallen && pfs->zero_flag)
			*rs = '-';
		else
			*(rs + pfs->count - pfs->vallen - 1) = '-';
		if (pfs->precision > pfs->vallen)
			ft_memset(rs + pfs->count - pfs->precision, '0',
				pfs->precision - pfs->vallen + 1);
		ft_memcpy(rs + pfs->count - pfs->vallen, temprs, pfs->vallen);
	}
	else
	{
		if (pfs->precision > pfs->vallen)
			ft_memset(rs + pfs->count - pfs->precision, '0',
				pfs->precision - pfs->vallen);
		ft_memcpy(rs + pfs->count - pfs->vallen, temprs, pfs->vallen);
	}
}
