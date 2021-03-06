/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 14:26:30 by jcorneli      #+#    #+#                 */
/*   Updated: 2020/11/26 16:58:06 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int			ft_toupper(int c)
{
	if (islower(c))
		return (c - 32);
	return (c);
}
