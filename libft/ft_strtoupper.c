/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtoupper.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/24 22:59:08 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/02/24 23:03:37 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_strtoupper(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}

