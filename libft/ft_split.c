/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 15:38:49 by jcorneli      #+#    #+#                 */
/*   Updated: 2021/02/24 22:20:40 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	clean_count(char *temps, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (temps[i] != '\0')
	{
		while (temps[i] == c)
			i++;
		if (temps[i] == '\0')
			break ;
		if (temps[i] != c && (temps[i + 1] == c || temps[i + 1] == '\0'))
			count++;
		i++;
	}
	i = 0;
	while (temps[i] != '\0')
	{
		if (temps[i] == c)
			temps[i] = '\0';
		i++;
	}
	return (count);
}

static char		**free_split(char **split, size_t jindex)
{
	while (jindex != 0)
	{
		free(split[jindex]);
		jindex--;
	}
	free(split[jindex]);
	free(split);
	return (NULL);
}

static char		**make_split(char **split, char *s, size_t strcounter)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (strcounter > 0)
	{
		while (!s[i])
			i++;
		split[j] = ft_strdup(&s[i]);
		if (!split[j])
		{
			free(s);
			return (free_split(split, j));
		}
		if (strcounter - 1 > 0)
			i += ft_strlen(split[j]);
		j++;
		strcounter--;
	}
	free(s);
	return (split);
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	char	*temps;
	size_t	strcount;

	if (!s)
		return (NULL);
	temps = ft_strdup(s);
	if (!temps)
		return (NULL);
	strcount = clean_count(temps, c);
	split = (char **)malloc((strcount + 1) * sizeof(char *));
	if (!split)
	{
		free(temps);
		return (NULL);
	}
	split = make_split(split, temps, strcount);
	if (!split)
		return (NULL);
	split[strcount] = NULL;
	return (split);
}
