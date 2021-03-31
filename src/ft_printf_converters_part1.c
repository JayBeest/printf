/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_converters_part1.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 16:25:25 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/03/24 15:03:58 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_c(t_pfs *pfs)
{
	char	c;
	char	*rs;

	if (pfs->spec != '%')
		c = va_arg(pfs->ap, int);
	else
		c = '%';
	pfs->precision = -1;
	pfs->vallen = 1;
	if (pfs->width > 1)
		pfs->count = pfs->width;
	rs = make_field(pfs);
	if (!rs)
		return (NULL);
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
	{
		pfs->count = 0;
		return (rs);
	}
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
	{
		pfs->count = 0;
		return (rs);
	}
	if (pfs->min_flag)
		paste_min_flag(pfs, rs, temprs);
	else
		paste_nomin_flag(pfs, rs, temprs);
	return (rs);
}

char	*convert_i(t_pfs *pfs)
{
	char	*rs;
	char	temprs[30];
	long	num;

	if (pfs->zero_flag && pfs->min_flag)
		pfs->zero_flag = 0;
	num = (long)va_arg(pfs->ap, int);
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
	{
		pfs->count = 0;
		return (rs);
	}
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
