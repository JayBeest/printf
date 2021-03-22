/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 16:25:37 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/02/03 16:25:40 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FT_PRINTF_H
# define PRINTF_FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>

typedef struct	s_pfs
{
	va_list		ap;
	int 		min_flag;
	int			plus_flag;
	int 		zero_flag;
	long		width;
	int 		star_width;
	long 		precision;
	long 		count;
	char 		spec;
	long 		vallen;
	int			isneg;
	long 		nest_i;
}				t_pfs;

#define CONVERSION_CHAR "sciupdxX%"

typedef char *(*t_convspec)(t_pfs *);

t_pfs 			*init_pfs(t_pfs *pfs, int reset);
int				ft_printf(const char *format, ...);
int				printf_converter(t_pfs *pfs);
long 			printf_parser(const char *s, t_pfs *pfs);

//Utils
char 			*make_field(t_pfs *pfs);
void 			add_pointer(char *rs, t_pfs *pfs);
void			paste_min_flag(t_pfs *pfs, char *rs, char *temprs);
void			paste_nomin_flag(t_pfs *pfs, char *rs, char *temprs);
void 			add_pointer_space(t_pfs *pfs);

// Libft
int				ft_atoi(const char *ptr);
int 			ft_isdigit(int c);
void			ft_itoba_nomalloc(long long num, int base, char *rs);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t len);
char			*ft_strchr(const char *s, int c);
int 			ft_strlen(const char *s);
void			ft_strtoupper(char *str);




// Checks

//static void 	check_flags(const char *s, t_pfs *pfs);
//static void 	check_width(const char *s, t_pfs *pfs);
//static void		check_precision(const char *s, t_pfs *pfs);
//static void		check_spec(const char *s, t_pfs *pfs);

// Converters

char 			*convert_s(t_pfs *pfs);
char 			*convert_c(t_pfs *pfs);
char			*convert_x(t_pfs *pfs);
char			*convert_i(t_pfs *pfs);
char			*convert_u(t_pfs *pfs);
char			*convert_p(t_pfs *pfs);

#endif