/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 23:29:14 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/03/22 22:37:51 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>

int 	ft_printf(const char *format, ...);

int	main(void)
{
	int 	rv;
	int 	rv2;

	void 	*ip = 23;

	char	ca = 'c';
	char	cb = 'h';
	char	cc = 'e';
	char	cd = 'c';
	char	ce = 'k';
	char	cf = '\0';
	
	char	*sa = "check1";
	char	*sb = "check2";
	char	*sc = "check3";
	char	*sd = "check4";
	char	*se = "check5";
	char 	sarr[20];

	int	ia = 1234;
	int	ib = 2;
	int	ic = 3;
	int	id = 4;
	int	ie = 12;
	char *str = NULL;


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

//	rv = printf("   printf ->|%c%c%c%c%c", ca, cb, cc, cd, ce);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|%c%c%c%c%c", ca, cb, cc, cd, ce);
//	printf("|-> rv: %d\n", rv2-13);
//
//	rv = printf("   printf ->|%*.*s", ie, id, sb);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|%*.*s", ie, id, sb);
//	printf("|-> rv: %d\n", rv2-13);
//
//	rv = printf("   printf ->|%04.2s", sa);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|%04.2s", sa);
//	printf("|-> rv: %d\n", rv2-13);
//
//	rv = printf("   printf ->|aa%ca", cf);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|aa%ca", cf);
//	printf("|-> rv: %d\n", rv2-13);
//
//	rv = printf("   printf ->|%4.7x", ia);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|%4.7x", ia);
//	printf("|-> rv: %d\n", rv2-13);
//
//	rv = printf("   printf ->|%14.7x", ia);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|%14.7x", ia);
//	printf("|-> rv: %d\n", rv2-13);


//	rv = printf("   printf ->|%14p", 1234567);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|%14p", 1234567);
//	printf("|-> rv: %d\n", rv2-13);
//
//	rv = printf("   printf ->|%2p", ia);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|%2p", ia);
//	printf("|-> rv: %d\n", rv2-13);
//
//	rv = printf("   printf ->|%p", ip);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|%p", ip);
//	printf("|-> rv: %d\n", rv2-13);
//
//	rv = printf("   printf ->|%p", ip);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|%p", ip);
//	printf("|-> rv: %d\n", rv2-13);
//
//	rv = printf("   printf ->|%015p", ia);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|%015p", ia);
//	printf("|-> rv: %d\n", rv2-13);



//	printf(" ft_printf \t%i\n", ft_printf("|\t%.*s\t\t|", 1,""));
//	printf(" printf \t%i\n", printf("|\t%.*s\t\t|", 1,""));
//	printf(" ft_printf \t%i\n", ft_printf("|\t%.s\t|", "hello"));
//	printf(" printf \t%i\n", printf("|\t%.s\t|", "hello"));
//	printf(" ft_printf \t%i\n", ft_printf("|\t%.s\t|", str));
//	printf(" printf \t%i\n", printf("|\t%.s\t|", str));
//
//	rv = printf("   printf ->|%08.3x", 8375);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|%08.3x", 8375);
//	printf("|-> rv: %d\n", rv2-13);
//
//	rv = printf("   printf ->|%7.4d", -3);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|%7.4d", -3);
//	printf("|-> rv: %d\n", rv2-13);



//	rv = printf("   printf ->|this %d number", -123);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|this %d number", -123);
//	printf("|-> rv: %d\n", rv2-13);
//
//	rv = printf("   printf ->|this %12d number", -123);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|this %12d number", -123);
//	printf("|-> rv: %d\n", rv2-13);
//
//	rv = printf("   printf ->|this %012d number", -123);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|this %012d number", -123);
//	printf("|-> rv: %d\n", rv2-13);
//
//	rv = printf("   printf ->|this %-012d number", -123);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|this %-012d number", -123);
//	printf("|-> rv: %d\n", rv2-13);
//
//	rv = printf("   printf ->|this %-012.5d number", -123);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|this %-012.5d number", -123);
//	printf("|-> rv: %d\n", rv2-13);
//
//	rv = printf("   printf ->|this %-012.2d number", -123);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|this %-012.2d number", -123);
//	printf("|-> rv: %d\n", rv2-13);
//
//	rv = printf("   printf ->|this %012.5d number", -123);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|this %012.5d number", -123);
//	printf("|-> rv: %d\n", rv2-13);

//	rv = printf("   printf ->|this %012.2d number", -123);
//	printf("|-> rv: %d\n", rv-13);
//	rv2 = ft_printf("ft_printf ->|this %012.2d number", -123);
//	printf("|-> rv: %d\n", rv2-13);

//	rv = printf("%-8.d", 0);
//	printf("|-> rv: %d\n", rv);
//	rv2 = ft_printf("%-8.d", 0);
//	printf("|-> rv: %d\n", rv2);

	rv = printf("%2.d", 0);
	printf("|-> rv: %d\n", rv);
	rv2 = ft_printf("%2.d", 0);
	printf("|-> rv: %d\n", rv2);

	rv = printf("%*s", -32, "abc");
	printf("|-> rv: %d\n", rv);
	rv2 = ft_printf("%*s", -32, "abc");
	printf("|-> rv: %d\n", rv2);

	rv = printf("%% *.5i 42 == |% *.5i|			", 4, 42);
	printf("|-> rv: %d\n", rv);
	rv2 = ft_printf("%% *.5i 42 == |% *.5i|			", 4, 42);
	printf("|-> rv: %d\n", rv2);

	rv = printf("%4.p", ia);
	printf("|-> rv: %d\n", rv);
	rv2 = ft_printf("%4.p", ia);
	printf("|-> rv: %d\n", rv2);

	rv = printf("%p", NULL);
	printf("|-> rv: %d\n", rv);
	rv2 = ft_printf("%p", NULL);
	printf("|-> rv: %d\n", rv2);

	rv = printf("%*p 42 == |%s|\n", -20, NULL, NULL);
	printf("|-> rv: %d\n", rv);
	rv2 = ft_printf("%*p 42 == |%s|\n", -20, NULL, NULL);
	printf("|-> rv: %d\n", rv2);


	return (0);
}
