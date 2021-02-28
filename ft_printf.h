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
	long 		precision;
	long 		count;
	char 		spec;
	long 		vallen;
	long 		nest_i;
}				t_pfs;

typedef char *(*t_convspec)(t_pfs *);

t_pfs 			*init_pfs(t_pfs *pfs, int reset);
int				ft_printf(const char *format, ...);
int				printf_converter(t_pfs *pfs, t_convspec funptr);
long 			printf_parser(const char *s, t_pfs *pfs);

//Utils
char 			*make_field(t_pfs *pfs);
long 			add_zeros(t_pfs *pfs, char *rs, long zeros);


// Libft
char			*ft_strchr(const char *s, int c);
int				ft_atoi(const char *ptr);
int 			ft_isdigit(int c);
void 			ft_putchar_fd(char c, int fd);
void			*ft_memset(void *s, int c, size_t len);
int 			ft_strlen(const char *s);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_itoba(long long num, int base, int iscap);
void			ft_itoba_nomalloc(long long num, int base, char *rs);
void			ft_strtolower(char *str);
void			ft_bzero(void *s, size_t n);




// Checks

static int 		check_flags(const char *s, t_pfs *pfs);
static int 		check_width(const char *s, t_pfs *pfs);
static int		check_precision(const char *s, t_pfs *pfs);
static void		check_spec(const char *s, t_pfs *pfs, t_convspec *funptr);

// Converters

char 			*convert_s(t_pfs *pfs);
char 			*convert_c(t_pfs *pfs);
char			*convert_x(t_pfs *pfs);
char			*convert_i(t_pfs *pfs);
char			*convert_u(t_pfs *pfs);

#endif