/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtolower.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/24 22:59:08 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/02/24 23:08:22 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_strtolower(char *str)
{
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
}
