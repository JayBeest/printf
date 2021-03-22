/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 23:57:10 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/02/24 23:11:39 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//void				*ft_memset(void *s, int c, size_t len);
//void				*ft_memcpy(void *dst, const void *src, size_t n);
//size_t				ft_strlen(const char *s);
//char				*ft_strchr(const char *s, int c);
//int					ft_atoi(const char *ptr);
int			ft_isdigit(int c);
int			ft_toupper(int c);

//int					ft_toupper(int c);
//void				ft_strtoupper(char *str);
//void				ft_itoba_nomalloc(long long num, int base, char *rs);

#endif
