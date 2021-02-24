/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 23:29:14 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/02/18 12:57:18 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int 	rv;
	int 	rv2;

	char	ca = 'c';
	char	cb = 'h';
	char	cc = 'e';
	char	cd = 'c';
	char	ce = 'k';
	
	char	*sa = "check1";
	char	*sb = "check2";
	char	*sc = "check3";
	char	*sd = "check4";
	char	*se = "check5";
	char 	sarr[20];

	int	ia = 123;
	int	ib = 2;
	int	ic = 3;
	int	id = 4;
	int	ie = 5;


//	printf("%c%c%c%c%c\n%s\n%s\n%s\n%s\n%s\n%d%d%d%d%d|\n", ca, cb, cc, cd, ce, sa, sb, sc, sd, se, ia, ib, ic, id, ie);
//	printf("\n%15.*d|\n", 12, ia);
//	printf("\n%15.*d|\n", 12, ia);
//	printf("\n%-15.*s|\n", 12, sa);
//	printf("\n%15.*s|\n", 12, sa);
//	printf("\n%-015.*d|\n", 12, ia);
//	printf("\n%015.*d|\n", 12, ia);
//	printf("\n%-015.*s|\n", 12, sa);
//	printf("\n%015.*s|\n", 12, sa);
//	printf("\n%-08.*s|\n", 12, sa);
//	printf("\n%08.*s|\n\n\n\n", 12, sa);

//	rv = printf("yo %c%c%c%c%c", ca, cb, cc, cd, ce);
//	printf("|-> rv: %d\n", rv);
//	rv2 = ft_printf("yo %c%c%c%c%c", ca, cb, cc, cd, ce);
//	printf("|-> rv: %d\n", rv2);
	rv = printf("\n%-02.4s", sb, ia);
	printf("|-> rv: %d\n", rv);
	rv2 = ft_printf("\n%-02.4s", sb);
	printf("|-> rv: %d\n", rv2);

	rv = ft_printf("%4.2s", sa);
	printf("|-> rv: %d\n", rv);
	rv2 = printf("%4.2s", sa);
	printf("|-> rv: %d\n", rv2);

	ft_itoba_nomalloc(123456890, 16, sarr);
	printf("\n%s\n", sarr);
	return (0);
}
