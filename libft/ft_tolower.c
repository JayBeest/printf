/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 14:36:15 by jcorneli      #+#    #+#                 */
/*   Updated: 2020/11/26 16:59:12 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	if (isupper(c))
		return (c + 32);
	return (c);
}
