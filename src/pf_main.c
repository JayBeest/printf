/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 15:17:45 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/03/03 11:43:07 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>


static void test_percentile()
{
	printf("\033[1;34m");
	printf("Testing: %%");
	printf("\033[0m\n");
	printf("\033[1;33m");
	printf("\ttest base");
	printf("\033[0m\n");
	ft_printf("|\t%%\t| ft_printf\n");
	printf("|\t%%\t| printf\n\n");
}

static void	test_signed_dec_i(int width, int precision)
{
	printf("\033[1;34m");
	printf("Testing: signed decimal (i)");
	printf("\033[0m\n");
	printf("\033[1;33m");
	printf(">\ttest base");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%i\t\t|", 1));
	printf(" printf \t%i\n", printf("|\t%i\t\t|", 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%i\t\t|", 0));
	printf(" printf \t%i\n", printf("|\t%i\t\t|", 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%i\t\t|", -1));
	printf(" printf \t%i\n", printf("|\t%i\t\t|", -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%i\t|", INT_MAX));
	printf(" printf \t%i\n", printf("|\t%i\t|", INT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%i\t|", INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%i\t|", INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest precision");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*i\t\t|", precision, 1));
	printf(" printf \t%i\n", printf("|\t%.*i\t\t|", precision, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*i\t\t|", precision, 0));
	printf(" printf \t%i\n", printf("|\t%.*i\t\t|", precision, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*i\t\t|", precision, -1));
	printf(" printf \t%i\n", printf("|\t%.*i\t\t|", precision, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*i\t|", precision, INT_MAX));
	printf(" printf \t%i\n", printf("|\t%.*i\t|", precision, INT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*i\t|", precision, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%.*i\t|", precision, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest width");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%*i\t\t|", width, 1));
	printf(" printf \t%i\n", printf("|\t%*i\t\t|", width, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*i\t\t|", width, 0));
	printf(" printf \t%i\n", printf("|\t%*i\t\t|", width, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*i\t\t|", width, -1));
	printf(" printf \t%i\n", printf("|\t%*i\t\t|", width, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*i\t|", width, INT_MAX));
	printf(" printf \t%i\n", printf("|\t%*i\t|", width, INT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*i\t|", width, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%*i\t|", width, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest fillzero");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*i\t\t|", width, 1));
	printf(" printf \t%i\n", printf("|\t%0*i\t\t|", width, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*i\t\t|", width, 0));
	printf(" printf \t%i\n", printf("|\t%0*i\t\t|", width, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*i\t\t|", width, -1));
	printf(" printf \t%i\n", printf("|\t%0*i\t\t|", width, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*i\t|", width, INT_MAX));
	printf(" printf \t%i\n", printf("|\t%0*i\t|", width, INT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*i\t|", width, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%0*i\t|", width, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest left allign");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*i\t\t|", width, 1));
	printf(" printf \t%i\n", printf("|\t%-*i\t\t|", width, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*i\t\t|", width, 0));
	printf(" printf \t%i\n", printf("|\t%-*i\t\t|", width, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*i\t\t|", width, -1));
	printf(" printf \t%i\n", printf("|\t%-*i\t\t|", width, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*i\t|", width, INT_MAX));
	printf(" printf \t%i\n", printf("|\t%-*i\t|", width, INT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*i\t|", width, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%-*i\t|", width, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest width and Precision");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*i\t\t|", width, precision, 1));
	printf(" printf \t%i\n", printf("|\t%*.*i\t\t|", width, precision, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*i\t\t|", width, precision, 0));
	printf(" printf \t%i\n", printf("|\t%*.*i\t\t|", width, precision, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*i\t\t|", width, precision, -1));
	printf(" printf \t%i\n", printf("|\t%*.*i\t\t|", width, precision, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*i\t|", width, precision, INT_MAX));
	printf(" printf \t%i\n", printf("|\t%*.*i\t|", width, precision, INT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*i\t|", width, precision, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%*.*i\t|", width, precision, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest width, precision and left allign");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*i\t\t|", width, precision, 1));
	printf(" printf \t%i\n", printf("|\t%-*.*i\t\t|", width, precision, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*i\t\t|", width, precision, 0));
	printf(" printf \t%i\n", printf("|\t%-*.*i\t\t|", width, precision, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*i\t\t|", width, precision, -1));
	printf(" printf \t%i\n", printf("|\t%-*.*i\t\t|", width, precision, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*i\t|", width, precision, INT_MAX));
	printf(" printf \t%i\n", printf("|\t%-*.*i\t|", width, precision, INT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*i\t|", width, precision, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%-*.*i\t|", width, precision, INT_MIN));
}

static void test_signed_dec_d(int width, int precision)
{
	printf("\033[1;34m");
	printf("Testing: signed decimal (d)");
	printf("\033[0m\n");
	printf("\033[1;33m");
	printf("\ttest base");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%d\t\t|", 1));
	printf(" printf \t%i\n", printf("|\t%d\t\t|", 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%d\t\t|", 0));
	printf(" printf \t%i\n", printf("|\t%d\t\t|", 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%d\t\t|", -1));
	printf(" printf \t%i\n", printf("|\t%d\t\t|", -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%d\t|", INT_MAX));
	printf(" printf \t%i\n", printf("|\t%d\t|", INT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%d\t|", INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%d\t|", INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest precision");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*d\t\t|", precision, 1));
	printf(" printf \t%i\n", printf("|\t%.*d\t\t|", precision, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*d\t\t|", precision, 0));
	printf(" printf \t%i\n", printf("|\t%.*d\t\t|", precision, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*d\t\t|", precision, -1));
	printf(" printf \t%i\n", printf("|\t%.*d\t\t|", precision, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*d\t|", precision, INT_MAX));
	printf(" printf \t%i\n", printf("|\t%.*d\t|", precision, INT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*d\t|", precision, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%.*d\t|", precision, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest width");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%*d\t\t|", width, 1));
	printf(" printf \t%i\n", printf("|\t%*d\t\t|", width, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*d\t\t|", width, 0));
	printf(" printf \t%i\n", printf("|\t%*d\t\t|", width, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*d\t\t|", width, -1));
	printf(" printf \t%i\n", printf("|\t%*d\t\t|", width, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*d\t|", width, INT_MAX));
	printf(" printf \t%i\n", printf("|\t%*d\t|", width, INT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*d\t|", width, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%*d\t|", width, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest fillzero");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*d\t\t|", width, 1));
	printf(" printf \t%i\n", printf("|\t%0*d\t\t|", width, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*d\t\t|", width, 0));
	printf(" printf \t%i\n", printf("|\t%0*d\t\t|", width, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*d\t\t|", width, -1));
	printf(" printf \t%i\n", printf("|\t%0*d\t\t|", width, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*d\t|", width, INT_MAX));
	printf(" printf \t%i\n", printf("|\t%0*d\t|", width, INT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*d\t|", width, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%0*d\t|", width, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest left allign");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*d\t\t|", width, 1));
	printf(" printf \t%i\n", printf("|\t%-*d\t\t|", width, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*d\t\t|", width, 0));
	printf(" printf \t%i\n", printf("|\t%-*d\t\t|", width, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*d\t\t|", width, -1));
	printf(" printf \t%i\n", printf("|\t%-*d\t\t|", width, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*d\t|", width, INT_MAX));
	printf(" printf \t%i\n", printf("|\t%-*d\t|", width, INT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*d\t|", width, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%-*d\t|", width, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest width and Precision");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*d\t\t|", width, precision, 1));
	printf(" printf \t%i\n", printf("|\t%*.*d\t\t|", width, precision, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*d\t\t|", width, precision, 0));
	printf(" printf \t%i\n", printf("|\t%*.*d\t\t|", width, precision, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*d\t\t|", width, precision, -1));
	printf(" printf \t%i\n", printf("|\t%*.*d\t\t|", width, precision, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*d\t|", width, precision, INT_MAX));
	printf(" printf \t%i\n", printf("|\t%*.*d\t|", width, precision, INT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*d\t|", width, precision, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%*.*d\t|", width, precision, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest width, precision and left allign");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*d\t\t|", width, precision, 1));
	printf(" printf \t%i\n", printf("|\t%-*.*d\t\t|", width, precision, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*d\t\t|", width, precision, 0));
	printf(" printf \t%i\n", printf("|\t%-*.*d\t\t|", width, precision, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*d\t\t|", width, precision, -1));
	printf(" printf \t%i\n", printf("|\t%-*.*d\t\t|", width, precision, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*d\t|", width, precision, INT_MAX));
	printf(" printf \t%i\n", printf("|\t%-*.*d\t|", width, precision, INT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*d\t|", width, precision, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%-*.*d\t|", width, precision, INT_MIN));
}

static void test_unsigned_dec_u(int width, int precision)
{
	printf("\033[1;34m");
	printf("Testing: unsigmed decimal (u)");
	printf("\033[1;33m");
	printf(">\ttest base");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%u\t\t|", 1));
	printf(" printf \t%i\n", printf("|\t%u\t\t|", 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%u\t\t|", 0));
	printf(" printf \t%i\n", printf("|\t%u\t\t|", 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%u\t|", -1));
	printf(" printf \t%i\n", printf("|\t%u\t|", -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%u\t|", UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%u\t|", UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%u\t|", INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%u\t|", INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest precision");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*u\t\t|", precision, 1));
	printf(" printf \t%i\n", printf("|\t%.*u\t\t|", precision, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*u\t\t|", precision, 0));
	printf(" printf \t%i\n", printf("|\t%.*u\t\t|", precision, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*u\t|", precision, -1));
	printf(" printf \t%i\n", printf("|\t%.*u\t|", precision, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*u\t|", precision, UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%.*u\t|", precision, UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*u\t|", precision, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%.*u\t|", precision, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest width");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%*u\t\t|", width, 1));
	printf(" printf \t%i\n", printf("|\t%*u\t\t|", width, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*u\t\t|", width, 0));
	printf(" printf \t%i\n", printf("|\t%*u\t\t|", width, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*u\t|", width, -1));
	printf(" printf \t%i\n", printf("|\t%*u\t|", width, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*u\t|", width, UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%*u\t|", width, UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*u\t|", width, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%*u\t|", width, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest fillzero");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*u\t\t|", width, 1));
	printf(" printf \t%i\n", printf("|\t%0*u\t\t|", width, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*u\t\t|", width, 0));
	printf(" printf \t%i\n", printf("|\t%0*u\t\t|", width, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*u\t|", width, -1));
	printf(" printf \t%i\n", printf("|\t%0*u\t|", width, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*u\t|", width, UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%0*u\t|", width, UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*u\t|", width, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%0*u\t|", width, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest left allign");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*u\t\t|", width, 1));
	printf(" printf \t%i\n", printf("|\t%-*u\t\t|", width, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*u\t\t|", width, 0));
	printf(" printf \t%i\n", printf("|\t%-*u\t\t|", width, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*u\t|", width, -1));
	printf(" printf \t%i\n", printf("|\t%-*u\t|", width, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*u\t|", width, UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%-*u\t|", width, UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*u\t|", width, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%-*u\t|", width, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest width and Precision");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*u\t\t|", width, precision, 1));
	printf(" printf \t%i\n", printf("|\t%*.*u\t\t|", width, precision, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*u\t\t|", width, precision, 0));
	printf(" printf \t%i\n", printf("|\t%*.*u\t\t|", width, precision, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*u\t|", width, precision, -1));
	printf(" printf \t%i\n", printf("|\t%*.*u\t|", width, precision, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*u\t|", width, precision, UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%*.*u\t|", width, precision, UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*u\t|", width, precision, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%*.*u\t|", width, precision, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest width, precision and left allign");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*u\t\t|", width, precision, 1));
	printf(" printf \t%i\n", printf("|\t%-*.*u\t\t|", width, precision, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*u\t\t|", width, precision, 0));
	printf(" printf \t%i\n", printf("|\t%-*.*u\t\t|", width, precision, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*u\t|", width, precision, -1));
	printf(" printf \t%i\n", printf("|\t%-*.*u\t|", width, precision, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*u\t|", width, precision, UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%-*.*u\t|", width, precision, UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*u\t|", width, precision, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%-*.*u\t|", width, precision, INT_MIN));
}

static void test_unsigned_hex_x(int width, int precision)
{
	printf("\033[1;34m");
	printf("Testing: unsigned hexadecimal (x)");
	printf("\033[0m\n");
	printf("\033[1;33m");
	printf("\ttest base");
	printf("\033[0m\n");
		printf(" ft_printf \t%i\n", ft_printf("|\t%x\t\t|", 1));
	printf(" printf \t%i\n", printf("|\t%x\t\t|", 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%x\t\t|", 0));
	printf(" printf \t%i\n", printf("|\t%x\t\t|", 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%x\t|", -1));
	printf(" printf \t%i\n", printf("|\t%x\t|", -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%x\t|", UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%x\t|", UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%x\t|", INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%x\t|", INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest precision");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*x\t\t|", precision, 1));
	printf(" printf \t%i\n", printf("|\t%.*x\t\t|", precision, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*x\t\t|", precision, 0));
	printf(" printf \t%i\n", printf("|\t%.*x\t\t|", precision, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*x\t|", precision, -1));
	printf(" printf \t%i\n", printf("|\t%.*x\t|", precision, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*x\t|", precision, UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%.*x\t|", precision, UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*x\t|", precision, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%.*x\t|", precision, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest width");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%*x\t\t|", width, 1));
	printf(" printf \t%i\n", printf("|\t%*x\t\t|", width, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*x\t\t|", width, 0));
	printf(" printf \t%i\n", printf("|\t%*x\t\t|", width, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*x\t|", width, -1));
	printf(" printf \t%i\n", printf("|\t%*x\t|", width, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*x\t|", width, UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%*x\t|", width, UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*x\t|", width, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%*x\t|", width, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest fillzero");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*x\t\t|", width, 1));
	printf(" printf \t%i\n", printf("|\t%0*x\t\t|", width, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*x\t\t|", width, 0));
	printf(" printf \t%i\n", printf("|\t%0*x\t\t|", width, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*x\t|", width, -1));
	printf(" printf \t%i\n", printf("|\t%0*x\t|", width, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*x\t|", width, UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%0*x\t|", width, UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*x\t|", width, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%0*x\t|", width, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest left allign");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*x\t\t|", width, 1));
	printf(" printf \t%i\n", printf("|\t%-*x\t\t|", width, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*x\t\t|", width, 0));
	printf(" printf \t%i\n", printf("|\t%-*x\t\t|", width, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*x\t|", width, -1));
	printf(" printf \t%i\n", printf("|\t%-*x\t|", width, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*x\t|", width, UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%-*x\t|", width, UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*x\t|", width, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%-*x\t|", width, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest width and Precision");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*x\t\t|", width, precision, 1));
	printf(" printf \t%i\n", printf("|\t%*.*x\t\t|", width, precision, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*x\t\t|", width, precision, 0));
	printf(" printf \t%i\n", printf("|\t%*.*x\t\t|", width, precision, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*x\t|", width, precision, -1));
	printf(" printf \t%i\n", printf("|\t%*.*x\t|", width, precision, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*x\t|", width, precision, UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%*.*x\t|", width, precision, UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*x\t|", width, precision, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%*.*x\t|", width, precision, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest width, precision and left allign");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*x\t\t|", width, precision, 1));
	printf(" printf \t%i\n", printf("|\t%-*.*x\t\t|", width, precision, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*x\t\t|", width, precision, 0));
	printf(" printf \t%i\n", printf("|\t%-*.*x\t\t|", width, precision, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*x\t|", width, precision, -1));
	printf(" printf \t%i\n", printf("|\t%-*.*x\t|", width, precision, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*x\t|", width, precision, UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%-*.*x\t|", width, precision, UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*x\t|", width, precision, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%-*.*x\t|", width, precision, INT_MIN));
}

static void test_unsigned_HEX_X(int width, int precision)
{
	printf("\033[1;34m");
	printf("Testing: signed decimal (d)");
	printf("\033[0m\n");
	printf("\033[1;33m");
	printf("\ttest base");
	printf("\033[0m\n");
		printf(" ft_printf \t%i\n", ft_printf("|\t%X\t\t|", 1));
	printf(" printf \t%i\n", printf("|\t%X\t\t|", 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%X\t\t|", 0));
	printf(" printf \t%i\n", printf("|\t%X\t\t|", 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%X\t|", -1));
	printf(" printf \t%i\n", printf("|\t%X\t|", -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%X\t|", UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%X\t|", UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%X\t|", INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%X\t|", INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest precision");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*X\t\t|", precision, 1));
	printf(" printf \t%i\n", printf("|\t%.*X\t\t|", precision, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*X\t\t|", precision, 0));
	printf(" printf \t%i\n", printf("|\t%.*X\t\t|", precision, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*X\t|", precision, -1));
	printf(" printf \t%i\n", printf("|\t%.*X\t|", precision, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*X\t|", precision, UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%.*X\t|", precision, UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*X\t|", precision, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%.*X\t|", precision, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest width");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%*X\t\t|", width, 1));
	printf(" printf \t%i\n", printf("|\t%*X\t\t|", width, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*X\t\t|", width, 0));
	printf(" printf \t%i\n", printf("|\t%*X\t\t|", width, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*X\t|", width, -1));
	printf(" printf \t%i\n", printf("|\t%*X\t|", width, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*X\t|", width, UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%*X\t|", width, UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*X\t|", width, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%*X\t|", width, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest fillzero");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*X\t\t|", width, 1));
	printf(" printf \t%i\n", printf("|\t%0*X\t\t|", width, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*X\t\t|", width, 0));
	printf(" printf \t%i\n", printf("|\t%0*X\t\t|", width, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*X\t|", width, -1));
	printf(" printf \t%i\n", printf("|\t%0*X\t|", width, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*X\t|", width, UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%0*X\t|", width, UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%0*X\t|", width, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%0*X\t|", width, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest left allign");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*X\t\t|", width, 1));
	printf(" printf \t%i\n", printf("|\t%-*X\t\t|", width, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*X\t\t|", width, 0));
	printf(" printf \t%i\n", printf("|\t%-*X\t\t|", width, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*X\t|", width, -1));
	printf(" printf \t%i\n", printf("|\t%-*X\t|", width, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*X\t|", width, UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%-*X\t|", width, UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*X\t|", width, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%-*X\t|", width, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest width and Precision");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*X\t\t|", width, precision, 1));
	printf(" printf \t%i\n", printf("|\t%*.*X\t\t|", width, precision, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*X\t\t|", width, precision, 0));
	printf(" printf \t%i\n", printf("|\t%*.*X\t\t|", width, precision, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*X\t|", width, precision, -1));
	printf(" printf \t%i\n", printf("|\t%*.*X\t|", width, precision, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*X\t|", width, precision, UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%*.*X\t|", width, precision, UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*X\t|", width, precision, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%*.*X\t|", width, precision, INT_MIN));

	printf("\033[1;33m");
	printf(">\ttest width, precision and left allign");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*X\t\t|", width, precision, 1));
	printf(" printf \t%i\n", printf("|\t%-*.*X\t\t|", width, precision, 1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*X\t\t|", width, precision, 0));
	printf(" printf \t%i\n", printf("|\t%-*.*X\t\t|", width, precision, 0));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*X\t|", width, precision, -1));
	printf(" printf \t%i\n", printf("|\t%-*.*X\t|", width, precision, -1));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*X\t|", width, precision, UINT_MAX));
	printf(" printf \t%i\n", printf("|\t%-*.*X\t|", width, precision, UINT_MAX));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*X\t|", width, precision, INT_MIN));
	printf(" printf\t%i\n\n", printf("|\t%-*.*X\t|", width, precision, INT_MIN));
}

static void test_string_s(int width, int precision)
{
	char *str = NULL;
	printf("\033[1;34m");
	printf("Testing: string (s)");
	printf("\033[0m\n");
	printf("\033[1;33m");
	printf("\ttest base");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%s\t\t|","test 1"));
	printf(" printf \t%i\n", printf("|\t%s\t\t|","test 1"));
	printf(" ft_printf \t%i\n", ft_printf("|\t%s\t\t|", ""));
	printf(" printf \t%i\n", printf("|\t%s\t\t|", ""));
	printf(" ft_printf \t%i\n", ft_printf("|\t%s\t\t|",  "     -\n-     "));
	printf(" printf \t%i\n", printf("|\t%s\t\t|",  "     -\n-     "));
	printf(" ft_printf \t%i\n", ft_printf("|\t%s\t|",  "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Interdum consectetur libero id faucibus."));
	printf(" printf \t%i\n", printf("|\t%s\t|",  "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Interdum consectetur libero id faucibus."));
	printf(" ft_printf \t%i\n", ft_printf("|\t%s\t|", str));
	printf(" printf \t%i\n", printf("|\t%s\t|", str));

	printf("\033[1;33m");
	printf("\ttest precision");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*s\t\t|", precision,"test 1"));
	printf(" printf \t%i\n", printf("|\t%.*s\t\t|", precision,"test 1"));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*s\t\t|", precision,""));
	printf(" printf \t%i\n", printf("|\t%.*s\t\t|", precision,""));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*s\t\t|", precision, "     -\n-     "));
	printf(" printf \t%i\n", printf("|\t%.*s\t\t|", precision, "     -\n-     "));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*s\t|", precision,  "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Interdum consectetur libero id faucibus."));
	printf(" printf \t%i\n", printf("|\t%.*s\t|", precision,  "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Interdum consectetur libero id faucibus."));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.*s\t|", precision, str));
	printf(" printf \t%i\n", printf("|\t%.*s\t|", precision, str));

	printf("\033[1;33m");
	printf("\ttest width");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%*s\t|", width, "test 1"));
	printf(" printf \t%i\n", printf("|\t%*s\t|", width, "test 1"));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*s\t|", width,""));
	printf(" printf \t%i\n", printf("|\t%*s\t|", width,""));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*s\t\t|", width, "     -\n-     "));
	printf(" printf \t%i\n", printf("|\t%*s\t\t|", width, "     -\n-     "));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*s\t|\n", width,  "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Interdum consectetur libero id faucibus."));
	printf(" printf \t%i\n", printf("|\t%*s\t|\n", width,  "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Interdum consectetur libero id faucibus."));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*s\t|", width, str));
	printf(" printf \t%i\n", printf("|\t%*s\t|", width, str));

	printf("\033[1;33m");
	printf("\ttest left allign");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*s\t|", width,"test 1"));
	printf(" printf \t%i\n", printf("|\t%-*s\t|", width,"test 1"));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*s\t|", width,""));
	printf(" printf \t%i\n", printf("|\t%-*s\t|", width,""));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*s\t\t|", width, "     -\n-     "));
	printf(" printf \t%i\n", printf("|\t%-*s\t\t|", width, "     -\n-     "));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*s\t|", width,  "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Interdum consectetur libero id faucibus."));
	printf(" printf \t%i\n", printf("|\t%-*s\t|", width,  "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Interdum consectetur libero id faucibus."));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*s\t|", width, str));
	printf(" printf \t%i\n", printf("|\t%-*s\t|", width, str));

	printf("\033[1;33m");
	printf("\ttest width and Precision");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*s\t|", width, precision,"test 1"));
	printf(" printf \t%i\n", printf("|\t%*.*s\t|", width, precision,"test 1"));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*s\t|", width, precision,""));
	printf(" printf \t%i\n", printf("|\t%*.*s\t|", width, precision,""));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*s\t\t|", width, precision, "     -\n-     "));
	printf(" printf \t%i\n", printf("|\t%*.*s\t\t|", width, precision, "     -\n-     "));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*s\t|", width, precision,  "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Interdum consectetur libero id faucibus."));
	printf(" printf \t%i\n", printf("|\t%*.*s\t|", width, precision,  "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Interdum consectetur libero id faucibus."));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*.*s\t|", width, precision, str));
	printf(" printf \t%i\n", printf("|\t%*.*s\t|", width, precision, str));

	printf("\033[1;33m");
	printf("\ttest width, precision and left allign");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*s\t|", width, precision,"test 1"));
	printf(" printf \t%i\n", printf("|\t%-*.*s\t|", width, precision,"test 1"));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*s\t|", width, precision,""));
	printf(" printf \t%i\n", printf("|\t%-*.*s\t|", width, precision,""));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*s\t\t|", width, precision, "     -\n-     "));
	printf(" printf \t%i\n", printf("|\t%-*.*s\t\t|", width, precision, "     -\n-     "));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*s\t|", width, precision,  "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Interdum consectetur libero id faucibus."));
	printf(" printf \t%i\n", printf("|\t%-*.*s\t|", width, precision,  "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Interdum consectetur libero id faucibus."));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*.*s\t|", width, precision, str));
	printf(" printf \t%i\n", printf("|\t%-*.*s\t|", width, precision, str));

	printf("\033[1;33m");
	printf("\ttest precision default");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%.s\t|", "hello"));
	printf(" printf \t%i\n", printf("|\t%.s\t|", "hello"));
	printf(" ft_printf \t%i\n", ft_printf("|\t%.s\t|", str));
	printf(" printf \t%i\n", printf("|\t%.s\t|", str));
}

static void test_character_c(int width)
{
	printf("\033[1;34m");
	printf("Testing: signed decimal (d)");
	printf("\033[0m\n");
	printf("\033[1;33m");
	printf("\ttest base");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%c\t|", 'a'));
	printf(" printf \t%i\n", printf("|\t%c\t|", 'a'));
	printf(" ft_printf \t%i\n", ft_printf("|\t%c\t|", 'Z'));
	printf(" printf \t%i\n", printf("|\t%c\t|", 'Z'));
	printf(" ft_printf \t%i\n", ft_printf("|\t%c\t|", '!'));
	printf(" printf \t%i\n", printf("|\t%c\t|", '!'));
	printf(" ft_printf \t%i\n", ft_printf("|\t%c\t|", '\t'));
	printf(" printf \t%i\n", printf("|\t%c\t|", '\t'));
	printf(" ft_printf \t%i\n", ft_printf("|\t%c\t|", '\0'));
	printf(" printf \t%i\n", printf("|\t%c\t|", '\0'));

	printf("\033[1;33m");
	printf("\ttest width");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%*c\t|", width, 'a'));
	printf(" printf \t%i\n", printf("|\t%*c\t|", width, 'a'));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*c\t|", width, 'Z'));
	printf(" printf \t%i\n", printf("|\t%*c\t|", width, 'Z'));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*c\t|", width, '!'));
	printf(" printf \t%i\n", printf("|\t%*c\t|", width, '!'));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*c\t|", width, '\t'));
	printf(" printf \t%i\n", printf("|\t%*c\t|", width, '\t'));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*c\t|", width, '\0'));
	printf(" printf \t%i\n", printf("|\t%*c\t|", width, '\0'));

	printf("\033[1;33m");
	printf("\ttest left allign");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*c\t|", width, 'a'));
	printf(" printf \t%i\n", printf("|\t%-*c\t|", width, 'a'));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*c\t|", width, 'Z'));
	printf(" printf \t%i\n", printf("|\t%-*c\t|", width, 'Z'));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*c\t|", width, '!'));
	printf(" printf \t%i\n", printf("|\t%-*c\t|", width, '!'));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*c\t|", width, '\t'));
	printf(" printf \t%i\n", printf("|\t%-*c\t|", width, '\t'));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*c\t|", width, '\0'));
	printf(" printf \t%i\n", printf("|\t%-*c\t|", width, '\0'));
}

static void test_pointer_p(int width, int precision)
{
	int		*ip;
	char	*cp;
	void	*vp;

	ip = &precision;
	cp = "test";
	vp = NULL;
	
	printf("\033[1;34m");
	printf("Testing: pointer (p)");
	printf("\033[0m\n");
	printf("\033[1;33m");
	printf("\ttest base");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%p\t|", ip));
	printf(" printf \t%i\n", printf("|\t%p\t|", ip));
	printf(" ft_printf \t%i\n", ft_printf("|\t%p\t|", cp));
	printf(" printf \t%i\n", printf("|\t%p\t|", cp));
	printf(" ft_printf \t%i\n", ft_printf("|\t%p\t\t|", vp));
	printf(" printf \t%i\n", printf("|\t%p\t\t|", vp));
	
	printf("\033[1;33m");
	printf("\ttest width");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%*p\t|", width,  ip));
	printf(" printf \t%i\n", printf("|\t%*p\t|", width,  ip));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*p\t|", width, cp));
	printf(" printf \t%i\n", printf("|\t%*p\t|", width, cp));
	printf(" ft_printf \t%i\n", ft_printf("|\t%*p\t\t|", width, vp));
	printf(" printf \t%i\n", printf("|\t%*p\t\t|", width, vp));

	printf("\033[1;33m");
	printf("\ttest left allign");
	printf("\033[0m\n");
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*p\t|", width, ip));
	printf(" printf \t%i\n", printf("|\t%-*p\t|", width, ip));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*p\t|", width, cp));
	printf(" printf \t%i\n", printf("|\t%-*p\t|", width, cp));
	printf(" ft_printf \t%i\n", ft_printf("|\t%-*p\t\t|", width, vp));
	printf(" printf \t%i\n", printf("|\t%-*p\t\t|", width, vp));
}

int	main(int argc, char **argv)
{
	int	precision;
	int	width;
	char conchar;

	precision = 1;
	width = 3;
	if (argc != 2)
	{
		printf("\033[1;31m");
		printf("Invalid number of arguments.");
		printf("\033[0m\n");
		return (0);
	}
	if (!ft_strchr(CONVERSION_CHAR, argv[1][0]))
	{
		printf("\033[1;31m");
		printf("Invalid argument.");
		printf("\033[0m\n");
		return (0);
	}
	conchar = argv[1][0];
	if (conchar == '%')
		test_percentile();
	else if (conchar == 'i')
		test_signed_dec_i(width, precision);
	else if (conchar == 'd')
		test_signed_dec_d(width, precision);
	else if (conchar == 'u')
		test_unsigned_dec_u(width, precision);
	else if (conchar == 'x')
		test_unsigned_hex_x(width, precision);
	else if (conchar == 'X')
		test_unsigned_HEX_X(width, precision);
	else if (conchar == 's')
		test_string_s(width, precision);
	else if (conchar == 'c')
		test_character_c(width);
	else if (conchar == 'p')
		test_pointer_p(width, precision);
	return (0);
}
